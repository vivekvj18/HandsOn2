/*
===================================================================================================================
Name: 10-A.c
Author: VIVEK JOSHI
Description:-Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV

Date: 01 Oct 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler(int sig) {
    printf("Caught SIGSEGV: Segmentation fault!\n");
    exit(1);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGSEGV, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    printf("Triggering segmentation fault...\n");
    int *p = NULL;
    *p = 42;   // generates SIGSEGV

    return 0;
}



/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM10$ g++ 10.c -o 10

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM10$ ./10

Triggering segmentation fault...

Caught SIGSEGV: Segmentation fault!



===================================================================================================================
*/

