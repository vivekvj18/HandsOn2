/*
===================================================================================================================
Name: 8-F.c
Author: VIVEK JOSHI
Description:- Write a separate program using signal system call to catch the following signals.
g. SIGPROF (use setitimer system call)

Date: 01 Oct 2025
===================================================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <stdlib.h>

void handler(int sig) {
    printf("Caught SIGPROF: Profiling timer expired!\n");
    exit(0);   // Exit after signal
}

int main() {
    signal(SIGPROF, handler);  // Catch SIGPROF

    struct itimerval timer;
    timer.it_value.tv_sec = 1;    // Trigger after 1 second of CPU time
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0; // No repeat
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_PROF, &timer, NULL);

    volatile long long counter = 0;
    while (1) {
        counter++;   // Busy loop consumes CPU time so SIGPROF triggers
    }

    return 0;
}




/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM8$ g++ 8-G.c -o 8G

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM8$ ./8G

Caught SIGPROF: Profiling timer expired!



===================================================================================================================
*/

