/*
===================================================================================================================
Name: 8-F.c
Author: VIVEK JOSHI
Description:- Write a separate program using signal system call to catch the following signals.
f. SIGVTALRM (use setitimer system call)

Date: 01 Oct 2025
===================================================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGVTALRM: Virtual timer expired!\n");
}

int main() {
    signal(SIGVTALRM, handler);  // Catch SIGVTALRM

    struct itimerval timer;
    timer.it_value.tv_sec = 1;    // First trigger after 1 sec CPU time
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0; // No repeat
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    while (1) {
        // Busy loop (consumes CPU, so SIGVTALRM will fire)
    }

    return 0;
}


/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM8$ g++ 8-F.c -o 8F

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM8$ ./8F

Caught SIGVTALRM: Virtual timer expired!





===================================================================================================================
*/

