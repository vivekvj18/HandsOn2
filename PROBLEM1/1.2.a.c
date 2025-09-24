/*
===================================================================================================================
Name: 1_2_a.c
Author: VIVEK JOSHI
Description:-Write a separate program (for each time domain) to set a interval timer in 10micro second
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
    static int count = 0;
    count++;
    printf("ITIMER_REAL: Timer expired at 10 microseconds, count = %d\n", count);
    if (count >= 10) {
        printf("Exiting after 10 signals.\n");
        exit(0);
    }
}

int main() {
    struct itimerval timer;
    signal(SIGALRM, timer_handler);

    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = 10;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 10;

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

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM1$ gcc 1.2.a.c -o 1.2.a

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM1$ ./1.2.a 

ITIMER_REAL: Timer expired at 10 microseconds, count = 1
ITIMER_REAL: Timer expired at 10 microseconds, count = 2
ITIMER_REAL: Timer expired at 10 microseconds, count = 3
ITIMER_REAL: Timer expired at 10 microseconds, count = 4
ITIMER_REAL: Timer expired at 10 microseconds, count = 5
ITIMER_REAL: Timer expired at 10 microseconds, count = 6
ITIMER_REAL: Timer expired at 10 microseconds, count = 7
ITIMER_REAL: Timer expired at 10 microseconds, count = 8
ITIMER_REAL: Timer expired at 10 microseconds, count = 9
ITIMER_REAL: Timer expired at 10 microseconds, count = 10
Exiting after 10 signals.


===================================================================================================================
*/

