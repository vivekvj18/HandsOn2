/*
===================================================================================================================
Name: 1-C.c
Author: VIVEK JOSHI
Description:- Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
c. ITIMER_PROF

Date: 01 Oct 2025
===================================================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>

void handler(int sig) {
    printf("ITIMER_PROF expired!\n");
    exit(0);
}

int main() {
    signal(SIGPROF, handler);

    struct itimerval timer;
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_PROF, &timer, NULL);

    volatile long long counter = 0;
    while(1) {
        counter++;  // busy loop consumes CPU + system time
    }
    return 0;
}


/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM1$ g++ 1-C.c -o 1C

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM1$ ./1C

ITIMER_PROF expired!

===================================================================================================================
*/

