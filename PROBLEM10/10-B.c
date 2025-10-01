/*
===================================================================================================================
Name: 10-B.c
Author: VIVEK JOSHI
Description:-Write a separate program using sigaction system call to catch the following signals.
b. SIGINT

Date: 01 Oct 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGINT: You pressed Ctrl+C!\n");
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    printf("Press Ctrl+C to send SIGINT...\n");
    while (1) {
        pause(); // wait for signals
    }

    return 0;
}


/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM10$ g++ 10-B.c -o 10B

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM10$ ./10B

Press Ctrl+C to send SIGINT...

^CCaught SIGINT: You pressed Ctrl+C!

^CCaught SIGINT: You pressed Ctrl+C!




===================================================================================================================
*/

