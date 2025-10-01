/*
===================================================================================================================
Name: 11.c
Author: VIVEK JOSHI
Description:-Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.

Date: 01 Oct 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    struct sigaction sa;

    // Step 1: Ignore SIGINT
    sa.sa_handler = SIG_IGN;   // ignore the signal
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    printf("SIGINT is ignored for 10 seconds. Try pressing Ctrl+C now...\n");
    sleep(10);

    // Step 2: Reset SIGINT to default
    sa.sa_handler = SIG_DFL;   // default action
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    printf("SIGINT reset to default. Press Ctrl+C again to terminate.\n");
    sleep(10);

    printf("No Ctrl+C pressed. Exiting normally.\n");
    return 0;
}


/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM11$ g++ 11.c -o 11

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM11$ ./11

SIGINT is ignored for 10 seconds. Try pressing Ctrl+C now...

^C^C^C^C^C^C^C^C^C^C^CSIGINT reset to default. Press Ctrl+C again to terminate.
^C



===================================================================================================================
*/

