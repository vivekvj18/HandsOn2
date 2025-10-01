/*
===================================================================================================================
Name: 8-D.c
Author: VIVEK JOSHI
Description:- Write a separate program using signal system call to catch the following signals.
d. SIGALRM (use alarm system call)

Date: 01 Oct 2025
===================================================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGALRM: Timer expired!\n");
}

int main() {
    signal(SIGALRM, handler);  // Catch SIGALRM

    printf("Setting alarm for 3 seconds...\n");
    alarm(3);

    pause();  // Wait for signal
    return 0;
}



/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM8$ g++ 8-D.c -o 8D

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM8$ ./8D

Setting alarm for 3 seconds...

Caught SIGALRM: Timer expired!




===================================================================================================================
*/

