/*
===================================================================================================================
Name: 8-E.c
Author: VIVEK JOSHI
Description:- Write a separate program using signal system call to catch the following signals.
e. SIGALRM (use setitimer system call)

Date: 01 Oct 2025
===================================================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGALRM: Timer expired (setitimer)!\n");
}

int main() {
    signal(SIGALRM, handler);  // Catch SIGALRM

    struct itimerval timer;
    timer.it_value.tv_sec = 2;      // First trigger after 2 sec
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;   // No repeat
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    pause();  // Wait for signal
    return 0;
}




/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM8$ g++ 8-E.c -o 8E

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM8$ ./8E

Caught SIGALRM: Timer expired (setitimer)!





===================================================================================================================
*/

