/* SPDX-License-Identifier: BSD-2-Clause */

#include <tilck_gen_headers/config_modules.h>

#include <tilck/common/basic_defs.h>
#include <tilck/common/printk.h>

#include <tilck/kernel/datetime.h>
#include <tilck/kernel/sched.h>
#include <tilck/kernel/kmalloc.h>
#include <tilck/kernel/errno.h>

#include <tilck/mods/tracing.h>

#include "termutil.h"

#if MOD_tracing

#define REND_BUF_SZ                              256
static char *rend_bufs[6];
static int used_rend_bufs;
static char *line_buf;

void init_dp_tracing(void)
{
   for (int i = 0; i < 6; i++) {

      if (!(rend_bufs[i] = kmalloc(REND_BUF_SZ)))
         panic("[dp] Unable to allocate rend_buf[%d]", i);
   }

   if (!(line_buf = kmalloc(TRACED_SYSCALLS_STR_LEN)))
      panic("[dp] Unable to allocate line_buf");
}

static void
tracing_ui_show_help(void)
{
   dp_write_raw("\r\n\r\n");
   dp_write_raw(E_COLOR_YELLOW "Tracing mode help" RESET_ATTRS "\r\n");

   dp_write_raw(
      E_COLOR_YELLOW "  "
      E_COLOR_YELLOW "o" RESET_ATTRS "     : Toggle always enter + exit\r\n"
      RESET_ATTRS
   );

   dp_write_raw(
      E_COLOR_YELLOW "  "
      E_COLOR_YELLOW "b" RESET_ATTRS "     : Dump big buffers\r\n"
      RESET_ATTRS
   );

   dp_write_raw(
      E_COLOR_YELLOW "  "
      E_COLOR_YELLOW "e" RESET_ATTRS "     : Edit syscalls wildcard expr "
      E_COLOR_RED "[1]" RESET_ATTRS "\r\n"
      RESET_ATTRS
   );

   dp_write_raw(
      E_COLOR_YELLOW "  "
      E_COLOR_YELLOW "l" RESET_ATTRS "     : List traced syscalls\r\n"
      RESET_ATTRS
   );

   dp_write_raw(
      E_COLOR_YELLOW "  "
      E_COLOR_YELLOW "q" RESET_ATTRS "     : Back to the debug panel\r\n"
      RESET_ATTRS
   );

   dp_write_raw(
      E_COLOR_YELLOW "  "
      "ENTER" RESET_ATTRS " : Start / stop tracing\r\n"
   );

   dp_write_raw("\r\n" E_COLOR_RED "[1]" RESET_ATTRS " ");
   dp_write_raw("In the wildcard expr the " E_COLOR_BR_WHITE "*" RESET_ATTRS
                " character is allowed only once, at the end.\r\n");

   dp_write_raw("The " E_COLOR_BR_WHITE "!" RESET_ATTRS " character can be "
                "used, at the beginning of each sub-expr, to negate it.\r\n");

   dp_write_raw("Single sub-expressions are separated by comma or space. "
                "The " E_COLOR_BR_WHITE "?" RESET_ATTRS " character is\r\n");

   dp_write_raw("supported and has the usual meaning "
                "(matches 1 single char, any).\r\n");

   dp_write_raw(
      E_COLOR_BR_WHITE "Example: " RESET_ATTRS
      "read*,write*,!readlink* \r\n"
   );
}

static void
tracing_ui_msg(void)
{
   dp_write_raw(
      E_COLOR_YELLOW
      "Tilck syscall tracing (h: help)\r\n"
      RESET_ATTRS
   );

   dp_write_raw(

      TERM_VLINE " Always ENTER+EXIT: %s "
      TERM_VLINE " Big bufs: %s "
      TERM_VLINE " #Sys traced: " E_COLOR_BR_BLUE "%d" RESET_ATTRS " "
      TERM_VLINE " #Tasks traced: " E_COLOR_BR_BLUE "%d" RESET_ATTRS " "
      TERM_VLINE "\r\n",

      tracing_is_force_exp_block_enabled()
         ? E_COLOR_GREEN "ON" RESET_ATTRS
         : E_COLOR_RED "OFF" RESET_ATTRS,

      tracing_are_dump_big_bufs_on()
         ? E_COLOR_GREEN "ON" RESET_ATTRS
         : E_COLOR_RED "OFF" RESET_ATTRS,

      get_traced_syscalls_count(),
      get_traced_tasks_count()
   );

   get_traced_syscalls_str(line_buf, TRACED_SYSCALLS_STR_LEN);

   dp_write_raw(
      TERM_VLINE
      " Trace expr: " E_COLOR_YELLOW "%s" RESET_ATTRS "\r\n", line_buf
   );

   dp_write_raw("\r\n");
   dp_write_raw(E_COLOR_YELLOW "> " RESET_ATTRS);
}

static inline bool
dp_should_full_dump_param(bool exp_block,
                          enum sys_param_kind kind,
                          enum trace_event_type t)
{
   return kind == sys_param_in_out ||
          (t == te_sys_enter && kind == sys_param_in) ||
          (t == te_sys_exit && (!exp_block || kind == sys_param_out));
}

static const char *
dp_get_esc_color_for_param(const struct sys_param_type *t, const char *rb)
{
   if (rb[0] == '\"' && t->ui_type == ui_type_string)
      return E_COLOR_RED;

   if (t == &ptype_errno_or_val && rb[0] == '-')
      return E_COLOR_WHITE_ON_RED;

   if (t->ui_type == ui_type_integer)
      return E_COLOR_BR_BLUE;

   return "";
}

static void
dp_dump_rendered_params(const char *sys_name, const struct syscall_info *si)
{
   int dumped_bufs = 0;

   dp_write_raw("%s(", sys_name);

   for (int i = 0; i < si->n_params; i++) {

      const struct sys_param_info *p = &si->params[i];

      if (!rend_bufs[i][0])
         continue;

      dp_write_raw(E_COLOR_MAGENTA "%s" RESET_ATTRS ": ", p->name);

      dp_write_raw(
         "%s%s" RESET_ATTRS,
         dp_get_esc_color_for_param(p->type, rend_bufs[i]),
         rend_bufs[i]
      );

      if (dumped_bufs < used_rend_bufs - 1)
         dp_write_raw(", ");

      dumped_bufs++;
   }

   dp_write_raw(")");
}

static void
dp_render_full_dump_single_param(int i,
                                 struct trace_event *e,
                                 const struct syscall_info *si,
                                 const struct sys_param_info *p,
                                 const struct sys_param_type *type)
{
   char *data;
   size_t data_size;
   long hlp = -1; /* helper param, means "real_size" for ptype_buffer */

   if (p->helper_param_name) {

      int idx = tracing_get_param_idx(si, p->helper_param_name);
      ASSERT(idx >= 0);

      hlp = (long) e->args[idx];
   }

   if (!tracing_get_slot(e, si, i, &data, &data_size)) {

      ASSERT(type->dump_from_val);

      if (!type->dump_from_val(e->args[i], hlp, rend_bufs[i], REND_BUF_SZ))
         snprintk(rend_bufs[i], REND_BUF_SZ, "(raw) %p", e->args[i]);

   } else {

      long sz = -1;
      ASSERT(type->dump);

      if (p->helper_param_name)
         sz = hlp;

      sz = MIN(sz, (long)data_size);

      if (p->real_sz_in_ret && e->type == te_sys_exit)
         hlp = e->retval >= 0 ? e->retval : 0;

      if (!type->dump(e->args[i], data, sz, hlp, rend_bufs[i], REND_BUF_SZ))
         snprintk(rend_bufs[i], REND_BUF_SZ, "(raw) %p", e->args[i]);
   }
}

static void
dp_render_minimal_dump_single_param(int i, struct trace_event *e)
{
   if (!ptype_voidp.dump_from_val(e->args[i], -1, rend_bufs[i], REND_BUF_SZ))
      panic("Unable to serialize a ptype_voidp in a render buf");
}

static void
dp_dump_syscall_with_info(struct trace_event *e,
                          const char *sys_name,
                          const struct syscall_info *si)
{
   used_rend_bufs = 0;

   for (int i = 0; i < si->n_params; i++) {

      bzero(rend_bufs[i], REND_BUF_SZ);

      const struct sys_param_info *p = &si->params[i];
      const struct sys_param_type *type = p->type;

      if (p->invisible)
         continue;

      if (dp_should_full_dump_param(exp_block(si), p->kind, e->type)) {

         dp_render_full_dump_single_param(i, e, si, p, type);
         used_rend_bufs++;

      } else if (e->type == te_sys_enter) {

         dp_render_minimal_dump_single_param(i, e);
         used_rend_bufs++;
      }
   }

   dp_dump_rendered_params(sys_name, si);
}

static void
dp_dump_ret_val(const struct syscall_info *si, long retval)
{
   if (!si) {

      if (retval <= 1024 * 1024) {

         if (retval >= 0) {

            /* we guess it's just a number */
            dp_write_raw(E_COLOR_BR_BLUE "%d" RESET_ATTRS, retval);

         } else {

            /* we guess it's an errno */
            dp_write_raw(E_COLOR_WHITE_ON_RED "-%s" RESET_ATTRS,
                         get_errno_name(-retval));
         }

      } else {

         /* we guess it's a pointer */
         dp_write_raw("%p", retval);
      }

      return;
   }

   const struct sys_param_type *rt = si->ret_type;
   ASSERT(rt->dump_from_val);

   if (!rt->dump_from_val((ulong)retval, -1, rend_bufs[0], REND_BUF_SZ)) {
      dp_write_raw("(raw) %p", retval);
      return;
   }

   dp_write_raw(
      "%s%s" RESET_ATTRS,
      dp_get_esc_color_for_param(si->ret_type, rend_bufs[0]),
      rend_bufs[0]
   );
}

static void
dp_dump_syscall_event(struct trace_event *e,
                      const char *sys_name,
                      const struct syscall_info *si)
{
   if (e->type == te_sys_enter) {

      dp_write_raw(E_COLOR_BR_GREEN "ENTER" RESET_ATTRS " ");

   } else {

      if (!si || exp_block(si))
         dp_write_raw(E_COLOR_BR_BLUE "EXIT" RESET_ATTRS " ");
      else
         dp_write_raw(E_COLOR_YELLOW "CALL" RESET_ATTRS " ");
   }

   if (si)
      dp_dump_syscall_with_info(e, sys_name, si);
   else
      dp_write_raw("%s()", sys_name);

   if (e->type == te_sys_exit) {

      dp_write_raw(" -> ");
      dp_dump_ret_val(si, e->retval);
   }

   dp_write_raw("\r\n");
}

static void
dp_dump_tracing_event(struct trace_event *e)
{
   const char *sys_name = NULL;
   const struct syscall_info *si = NULL;

   dp_write_raw(
      "%05u.%03u [%04d] ",
      (u32)(e->sys_time / TS_SCALE),
      (u32)((e->sys_time % TS_SCALE) / (TS_SCALE / 1000)),
      e->tid
   );

   if (e->type == te_sys_enter || e->type == te_sys_exit) {

      sys_name = tracing_get_syscall_name(e->sys);
      ASSERT(sys_name);
      sys_name += 4; /* skip the "sys_" prefix */
      si = tracing_get_syscall_info(e->sys);
      dp_dump_syscall_event(e, sys_name, si);

   } else {

      dp_write_raw(E_COLOR_BR_RED "<unknown event>\r\n" RESET_ATTRS);
   }
}

static bool
dp_tracing_screen_main_loop(void)
{
   struct trace_event e;
   int rc;
   char c;

   while (true) {

      /* Check the input for Ctrl+C */
      rc = vfs_read(dp_input_handle, &c, 1);

      if (rc < 0 && rc != -EAGAIN)
         return false; /* exit because of an error */

      /* rc == 1 */

      switch (c) {

         case 'q':
            return false; /* clean exit */

         case DP_KEY_ENTER:
            return true; /* stop dumping the trace buffer */
      }

      if (read_trace_event(&e, TIMER_HZ / 10))
         dp_dump_tracing_event(&e);
   }

   NOT_REACHED();
}

static void
dp_exit_trace_syscall_str(void)
{
   dp_move_left(2);
   dp_write_raw(E_COLOR_YELLOW "expr> " RESET_ATTRS);
   dp_set_input_blocking(true);
   dp_read_line(line_buf, TRACED_SYSCALLS_STR_LEN);
   dp_set_input_blocking(false);

   if (set_traced_syscalls(line_buf) < 0)
      dp_write_raw(E_COLOR_RED "Invalid input\r\n" RESET_ATTRS);
}

static void
dp_list_traced_syscalls(void)
{
   dp_write_raw("\r\n\r\n");
   dp_write_raw(E_COLOR_YELLOW "Traced syscalls list" RESET_ATTRS);
   dp_write_raw("\r\n");

   for (u32 i = 0; i < MAX_SYSCALLS; i++) {

      if (!tracing_is_enabled_on_sys(i))
         continue;

      dp_write_raw("%s ", 4 + tracing_get_syscall_name(i));
   }

   dp_write_raw("\r\n");
}

static int
dp_tracing_dump_remaining_events(void)
{
   char c;
   int rem;
   struct key_event ke;
   struct trace_event e;

   if (!(rem = tracing_get_in_buffer_events_count()))
      return 0; /* no remaining events in the buffer */

   dp_write_raw("Discard remaining %d events in the buf? [Y/n] ", rem);

   do {

      if (dp_read_ke_from_tty(&ke) < 0)
         return -1; /* unexpected I/O error */

      c = ke.print_char;

   } while (c != 'y' && c != 'n' && c != '\r');

   if (c == '\r')
      c = 'y';

   dp_write_raw_int(&c, 1);

   while (true) {

      if (!read_trace_event_noblock(&e))
         break;

      if (c == 'n')
         dp_dump_tracing_event(&e);
   }

   dp_write_raw("\r\n");
   return 1;
}

enum kb_handler_action
dp_tracing_screen(void)
{
   char c;
   int rc;
   bool should_continue;

   dp_set_cursor_enabled(true);
   dp_clear();
   dp_move_cursor(1, 1);
   tracing_ui_msg();

   while (true) {

      dp_set_input_blocking(true);
      {
         rc = vfs_read(dp_input_handle, &c, 1);
      }
      dp_set_input_blocking(false);

      if (rc <= 0)
         break; /* something gone wrong */

      if (c == 'q')
         break; /* clean exit */

      if (c == DP_KEY_ENTER) {

         dp_write_raw("\r\n");
         dp_write_raw(
            E_COLOR_GREEN "-- Tracing active --" RESET_ATTRS "\r\n\r\n"
         );

         tracing_set_enabled(true);
         {
            should_continue = dp_tracing_screen_main_loop();
         }
         tracing_set_enabled(false);

         if (!should_continue)
            break;

         dp_write_raw(
            E_COLOR_RED "-- Tracing stopped --" RESET_ATTRS "\r\n"
         );

         if ((rc = dp_tracing_dump_remaining_events()) < 0)
            break; /* unexpected I/O error */

         dp_write_raw("\r\n");
         tracing_ui_msg();
         continue;
      }

      if (c == 'o' || c == 'h' || c == 'l')
         dp_write_raw("%c", c);

      switch (c) {

         case 'o':
            tracing_set_force_exp_block(!tracing_is_force_exp_block_enabled());
            break;

         case 'b':
            tracing_set_dump_big_bufs_opt(!tracing_are_dump_big_bufs_on());
            break;

         case 'h':
            tracing_ui_show_help();
            break;

         case 'e':
            dp_exit_trace_syscall_str();
            break;

         case 'l':
            dp_list_traced_syscalls();
            break;

         default:
            continue;
      }

      dp_write_raw("\r\n\r\n");
      tracing_ui_msg();
   }

   ui_need_update = true;
   dp_set_cursor_enabled(false);
   return kb_handler_ok_and_continue;
}

#endif // #if MOD_tracing
