/*
===================================================================================================================
Name: 10-C.c
Author: VIVEK JOSHI
Description:-Write a separate program using sigaction system call to catch the following signals.
c. SIGFPE

Date: 01 Oct 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler(int sig) {
    printf("Caught SIGFPE: Divide by zero error!\n");
    exit(1);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGFPE, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    printf("Triggering divide by zero...\n");
    int a = 5, b = 0;
    int c = a / b;  // generates SIGFPE
    printf("%d\n", c);

    return 0;
}


/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM10$ g++ 10-C.c -o 10C

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM10$ ./10C

Triggering divide by zero...

Caught SIGFPE: Divide by zero error!




===================================================================================================================
*/

