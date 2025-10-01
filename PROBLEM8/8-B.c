/*
===================================================================================================================
Name: 8-B.c
Author: VIVEK JOSHI
Description:- Write a separate program using signal system call to catch the following signals.
b. SIGINT

Date: 01 Oct 2025
===================================================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGINT: You pressed Ctrl+C!\n");
}

int main() {
    signal(SIGINT, handler);  // Catch SIGINT

    printf("Press Ctrl+C to trigger SIGINT...\n");
    while (1) {
        sleep(1);
    }

    return 0;
}



/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM8$ g++ 8-B.c -o 8B

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM8$ ./8B

Press Ctrl+C to trigger SIGINT...

^CCaught SIGINT: You pressed Ctrl+C!





===================================================================================================================
*/

