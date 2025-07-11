
/*
   Schedule an alarm.  In SECONDS seconds, the process will get a SIGALRM.
   If SECONDS is zero, any currently scheduled alarm will be cancelled.
   The function returns the number of seconds remaining until the last
   alarm scheduled would have signaled, or zero if there wasn't one.
   There is no return value to indicate an error, but you can set `errno'
   to 0 and check its value after calling `alarm', and this might tell you.
   The signal may come late due to processor scheduling.  */

// #include <unistd.h> //  = = = = = = = = = = = = = = = = = = = = = = = =
extern unsigned int alarm (unsigned int __seconds);

int main()
{
   sig.__sigaction_handler.sa_handler = alarm_handler;
   sigaction(14,&sig,((void *)0));

   return 0;
}

