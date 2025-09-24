/*
===================================================================================================================
Name: 1_1_a.c
Author: VIVEK JOSHI
Description:-Write a separate program (for each time domain) to set a interval timer in 10sec
a. ITIMER_REAL

Date: 11 Sept 2025
===================================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

void timer_handler(int signum) {
    printf("ITIMER_REAL: Timer expired after 10 seconds\n");
}

int main() {
    struct itimerval timer;
    signal(SIGALRM, timer_handler);

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 0;

    if (setitimer(ITIMER_REAL, &timer, NULL) == -1) {
        perror("Error setting timer");
        exit(1);
    }

    while (1) {
        pause();
    }
    return 0;
}








/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLvivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM1$ gcc 1.1.a.c -o 1.1.a

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM1$ ./1.1.a 

ITIMER_REAL: Timer expired after 10 seconds
ITIMER_REAL: Timer expired after 10 seconds
ITIMER_REAL: Timer expired after 10 seconds
ITIMER_REAL: Timer expired after 10 seconds
ITIMER_REAL: Timer expired after 10 seconds


===================================================================================================================
*/

