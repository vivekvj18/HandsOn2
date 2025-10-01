/*
===================================================================================================================
Name: 1-A.c
Author: VIVEK JOSHI
Description:- Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL

Date: 01 Oct 2025
===================================================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <stdlib.h>

void handler(int sig) {
    printf("ITIMER_REAL expired!\n");
    exit(0);
}

int main() {
    signal(SIGALRM, handler);

    struct itimerval timer;
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    while(1) {}  // wait for signal
    return 0;
}


/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM1$ g++ 1-A.c -o 1A

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM1$ ./1A

ITIMER_REAL expired!




===================================================================================================================
*/

