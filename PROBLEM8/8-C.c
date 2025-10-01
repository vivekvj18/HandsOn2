/*
===================================================================================================================
Name: 8-C.c
Author: VIVEK JOSHI
Description:- Write a separate program using signal system call to catch the following signals.
c. SIGFPE

Date: 01 Oct 2025
===================================================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig) {
    printf("Caught SIGFPE: Floating point exception (divide by zero)!\n");
    exit(1);
}

int main() {
    signal(SIGFPE, handler);  // Catch SIGFPE

    printf("Triggering divide by zero...\n");
    int x = 1 / 0;  // Causes SIGFPE

    return 0;
}



/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM8$ g++ 8-C.c -o 8C

8-C.c: In function ‘int main()’:

8-C.c:25:15: warning: division by zero [-Wdiv-by-zero]

25 |     int x = 1 / 0;  // Causes SIGFPE

|             ~~^~~

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM8$ ./8C

Triggering divide by zero...

Caught SIGFPE: Floating point exception (divide by zero)!






===================================================================================================================
*/

