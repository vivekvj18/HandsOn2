/*
===================================================================================================================
Name: 8-A.c
Author: VIVEK JOSHI
Description:- Write a separate program using signal system call to catch the following signals.
a. SIGSEGV

Date: 01 Oct 2025
===================================================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig) {
    printf("Caught SIGSEGV: Segmentation fault!\n");
    exit(1);
}

int main() {
    signal(SIGSEGV, handler);  // Catch SIGSEGV

    printf("Triggering segmentation fault...\n");
    int *p = NULL;
    *p = 42;  // Causes SIGSEGV

    return 0;
}


/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM8$ g++ 8-A.c -o 8A

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM8$ ./8A

Triggering segmentation fault...

Caught SIGSEGV: Segmentation fault!




===================================================================================================================
*/

