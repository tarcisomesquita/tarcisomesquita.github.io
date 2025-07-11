/* SPDX-License-Identifier: BSD-2-Clause */

#pragma once
#include <tilck/common/basic_defs.h>
#include <tilck/kernel/sched.h>

#define MAX_TASKLET_THREADS 64

struct tasklet_context {

   ulong arg1;
   ulong arg2;
};

void init_tasklets();

struct task *get_tasklet_runner(u32 tn);
int create_tasklet_thread(int priority, u16 limit);
bool any_tasklets_to_run(u32 tn);
u32 get_tasklet_runner_limit(u32 tn);
void destroy_last_tasklet_thread(void);

struct task *get_hi_prio_ready_tasklet_runner(void);

NODISCARD bool enqueue_tasklet_int(int tn, void *func, ulong arg1, ulong arg2);

#define enqueue_tasklet2(tn, f, a1, a2) \
   enqueue_tasklet_int(tn, (void *)(f), (ulong)(a1), (ulong)(a2))

#define enqueue_tasklet1(tn, f, a1) \
   enqueue_tasklet_int(tn, (void *)(f), (ulong)(a1), 0)

#define enqueue_tasklet0(tn, f) \
   enqueue_tasklet_int(tn, (void *)(f), 0, 0)

void tasklet_runner(void *arg);

