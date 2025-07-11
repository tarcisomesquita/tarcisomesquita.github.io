/* SPDX-License-Identifier: BSD-2-Clause */

#include <tilck/common/basic_defs.h>
#include <tilck/common/atomics.h>

#include <tilck/kernel/process.h>
#include <tilck/kernel/sched.h>
#include <tilck/kernel/hal.h>
#include <tilck/kernel/irq.h>
#include <tilck/kernel/timer.h>
#include <tilck/kernel/elf_utils.h>
#include <tilck/kernel/tasklet.h>
#include <tilck/kernel/datetime.h>

static u64 __ticks;        /* ticks since the timer started */

u64 __time_ns;             /* nanoseconds since the timer started */
u32 __tick_duration;       /* the real duration of a tick, ~TS_SCALE/TIMER_HZ */
int __tick_adj_val;
int __tick_adj_ticks_rem;

#if KRN_TRACK_NESTED_INTERR
u32 slow_timer_irq_handler_count;
#endif

static struct list timer_wakeup_list = make_list(timer_wakeup_list);

u64 get_ticks(void)
{
   u64 curr_ticks;
   ulong var;

   disable_interrupts(&var);
   {
      curr_ticks = __ticks;
   }
   enable_interrupts(&var);
   return curr_ticks;
}

void task_set_wakeup_timer(struct task *ti, u32 ticks)
{
   ulong var;
   ASSERT(ticks > 0);

   disable_interrupts(&var);
   {
      if (ti->ticks_before_wake_up == 0) {
         ASSERT(!list_is_node_in_list(&ti->wakeup_timer_node));
         list_add_tail(&timer_wakeup_list, &ti->wakeup_timer_node);
      } else {
         ASSERT(list_is_node_in_list(&ti->wakeup_timer_node));
      }

      ti->ticks_before_wake_up = ticks;
   }
   enable_interrupts(&var);
}

void task_update_wakeup_timer_if_any(struct task *ti, u32 new_ticks)
{
   ulong var;
   ASSERT(new_ticks > 0);

   disable_interrupts(&var);
   {
      if (ti->ticks_before_wake_up > 0) {
         ASSERT(list_is_node_in_list(&ti->wakeup_timer_node));
         ti->ticks_before_wake_up = new_ticks;
      }
   }
   enable_interrupts(&var);
}

u32 task_cancel_wakeup_timer(struct task *ti)
{
   ulong var;
   u32 old;
   disable_interrupts(&var);
   {
      old = ti->ticks_before_wake_up;

      if (old > 0) {
         ti->ticks_before_wake_up = 0;
         list_remove(&ti->wakeup_timer_node);
      }
   }
   enable_interrupts(&var);
   return old;
}

static struct task *tick_all_timers(void)
{
   struct task *pos, *temp;
   struct task *last_ready_task = NULL;
   ulong var;

   /*
    * This is *NOT* the best we can do. In particular, it's terrible to keep
    * the interrupts disabled while iterating the _whole_ timer_wakeup_list.
    * A better solution is to keep the tasks to wake-up in a sort of ordered
    * list and then use relative timers. This way, at each tick we'll have to
    * decrement just one single counter. We'll start decrement the next counter
    * only when the first counter reaches 0 and the list node is removed.
    *
    * Of course, if we cannot use kmalloc() in case of sleep, it gets much
    * harder to create such an ordered list and make it live inside a member
    * of struct task. Maybe a BST will do the job, but that would require
    * paying O(logN) per tick for finding the earliest timer. Not sure how
    * better would be now for N < 50 (typical), given the huge added constant
    * for the BST functions. Also, the cancellation of a timer would require
    * some extra effort in order to re-calculate the relative timer values,
    * while we want the cancellation to be light-fast because it's run by IRQ
    * handlers.
    *
    * In conclusion, for the moment, given the very limited scale of Tilck (tens
    * of tasks at most running on the whole system), this solution is safe and
    * good-enough but, at some point a smarter ad-hoc solution for Tilck should
    * be devised.
    */
   disable_interrupts(&var);

   list_for_each(pos, temp, &timer_wakeup_list, wakeup_timer_node) {

      /* If task is part of this list, it's counter must be > 0 */
      ASSERT(pos->ticks_before_wake_up > 0);

      if (UNLIKELY(--pos->ticks_before_wake_up == 0)) {

         list_remove(&pos->wakeup_timer_node);

         if (pos->state == TASK_STATE_SLEEPING) {
            task_change_state(pos, TASK_STATE_RUNNABLE);
            last_ready_task = pos;
         }
      }
   }

   enable_interrupts(&var);
   return last_ready_task;
}

void kernel_sleep(u64 ticks)
{
   DEBUG_ONLY(check_not_in_irq_handler());

   /*
    * Implementation: why
    * ---------------------
    *
    * In theory, the function could be implemented just as:
    *
    *    if (ticks) {
    *       task_set_wakeup_timer(get_curr_task(), ticks);
    *       task_change_state(get_curr_task(), TASK_STATE_SLEEPING);
    *    }
    *    kernel_yield();
    *
    * But that would require task->ticks_before_wake_up to be actually 64-bit,
    * wide and that's bad on 32-bit systems because:
    *
    *    - it would require using the soft 64-bit integers (slow)
    *    - it would make impossible, in the case we wanted that, the counter
    *      to be atomic.
    *
    * Therefore, in order to use a 32-bit value for 'ticks_before_wake_up' and,
    * at the same time being able to sleep for more than 2^32-1 ticks, we need
    * a more tricky implementation (below), and the little extra runtime price
    * for it is totally fine, since we're going to sleep anyways!
    *
    * Implementation: how
    * ----------------------
    *
    * The simpler way to explain the algorithm is to just assume everything
    * is in base 10 and that ticks_before_wake_up has 2 digits, while we want
    * to support 4 digits sleep time. For example, we want to sleep for 234
    * ticks. The algorithm first computes 534 % 100 = 34 and then 534 / 100 = 5.
    * After that, it sleeps q (= 5) times for 99 ticks (max allowed). Clearly,
    * we missed 5 ticks (5 * 99 < 500) this way, but we'll going to fix that
    * buy just sleeping 'q' ticks. Thus, by now, we've slept for 500 ticks.
    * Now we have to sleep for 34 ticks more are we're done.
    *
    * The same logic applies to base-2 case with 32-bit and 64-bit integers,
    * just the numbers are much bigger. The remainder can be computed using
    * a bitmask, while the division by using just a right shift.
    */

   const u32 rem = ticks & 0xffffffff;
   const u32 q = ticks >> 32;

   for (u32 i = 0; i < q; i++) {
      task_set_wakeup_timer(get_curr_task(), 0xffffffff);
      task_change_state(get_curr_task(), TASK_STATE_SLEEPING);
      kernel_yield();
   }

   if (q) {
      task_set_wakeup_timer(get_curr_task(), q);
      task_change_state(get_curr_task(), TASK_STATE_SLEEPING);

      if (rem) {
         /* Yield only if we're going to sleep again because rem > 0 */
         kernel_yield();
      }
   }

   if (rem) {
      task_set_wakeup_timer(get_curr_task(), rem);
      task_change_state(get_curr_task(), TASK_STATE_SLEEPING);
   }

   /* We must yield at least once, even if ticks == 0 */
   kernel_yield();
}

static ALWAYS_INLINE void debug_timer_irq_sanity_checks(void)
{
   /*
    * We CANNOT allow the timer to call the scheduler if it interrupted an
    * interrupt handler. That's why interrupt handlers always to run with
    * preemption disabled. But, if we got here, preemption was NOT disabled and
    * therefore, we're in one of following two cases:
    *
    * nested_interrupts_count == 1
    *     meaning the timer is the only current interrupt: a kernel or an user
    *     task was running regularly.
    *
    * OR
    *
    * nested_interrupts_count == 2
    *     meaning that the timer interrupted a syscall working with preemption
    *     enabled.
    *
    * The ASSERT below checks that.
    */

#if defined(DEBUG) && KRN_TRACK_NESTED_INTERR
   {
      ulong var;
      disable_interrupts(&var); /* under #if KRN_TRACK_NESTED_INTERR */
      int c = get_nested_interrupts_count();
      ASSERT(c == 1 || (c == 2 && in_syscall()));
      enable_interrupts(&var);
   }
#endif
}

static ALWAYS_INLINE bool timer_nested_irq(void)
{

#if KRN_TRACK_NESTED_INTERR

   ulong var;
   disable_interrupts(&var); /* under #if KRN_TRACK_NESTED_INTERR */

   if (in_nested_irq_num(X86_PC_TIMER_IRQ)) {
      slow_timer_irq_handler_count++;
      enable_interrupts(&var);
      return true;
   }

   enable_interrupts(&var);

#endif

   return false;
}

enum irq_action timer_irq_handler(regs_t *context)
{
   if (KRN_TRACK_NESTED_INTERR)
      if (timer_nested_irq())
         return IRQ_FULLY_HANDLED;

   /*
    * It is SAFE to directly increase the 64-bit integer __ticks here, without
    * disabling the interrupts and without trying to use any kind of atomic
    * operation because this is the ONLY place where __ticks is modified. Even
    * when nested IRQ0 is allowed, __ticks won't be touched by the nested
    * handler as you can see above.
    */
   __ticks++;

   if (UNLIKELY(__tick_adj_ticks_rem)) {
      __time_ns += (u32)((s32)__tick_duration + __tick_adj_val);
      __tick_adj_ticks_rem--;
   } else {
      __time_ns += __tick_duration;
   }

   account_ticks();
   struct task *last_ready_task = tick_all_timers();

   /*
    * Here we have to check that disabled_preemption_count is > 1, not > 0
    * since as the way the handle_irq() is implemented, that counter will be
    * always 1 when this function is called. We must not call schedule()
    * if there has been another part of the code that disabled the preemption.
    */
   if (disable_preemption_count > 1) {
      return IRQ_FULLY_HANDLED;
   }

   ASSERT(disable_preemption_count == 1); // again, for us disable = 1 means 0.
   debug_timer_irq_sanity_checks();

   if (last_ready_task) {

      if (get_curr_task()->state == TASK_STATE_RUNNING) {
         task_change_state(get_curr_task(), TASK_STATE_RUNNABLE);
      }

      save_current_task_state(context);
      switch_to_task(last_ready_task, get_int_num(context));
   }

   if (need_reschedule()) {
      save_current_task_state(context);
      schedule(get_int_num(context));
   }

   return IRQ_FULLY_HANDLED;
}

static struct irq_handler_node timer_irq_handler_node = {
   .node = make_list_node(timer_irq_handler_node.node),
   .handler = timer_irq_handler,
};

void init_timer(void)
{
   __tick_duration = hw_timer_setup(TS_SCALE / TIMER_HZ);
   irq_install_handler(X86_PC_TIMER_IRQ, &timer_irq_handler_node);
}
