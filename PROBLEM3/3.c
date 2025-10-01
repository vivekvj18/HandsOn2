/*
===================================================================================================================
Name: 3.c
Author: VIVEK JOSHI
Description:- Write a program to set (any one) system resource limit. Use setrlimit system call.

Date: 01 Oct 2025
===================================================================================================================
*/

#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    struct rlimit rl;

    // Set maximum number of open files to 50
    rl.rlim_cur = 50;  // soft limit
    rl.rlim_max = 100; // hard limit

    if (setrlimit(RLIMIT_NOFILE, &rl) == 0) {
        printf("Resource limit set successfully.\n");

        // Verify new limit
        struct rlimit new_rl;
        getrlimit(RLIMIT_NOFILE, &new_rl);
        printf("Soft limit: %ld, Hard limit: %ld\n", new_rl.rlim_cur, new_rl.rlim_max);
    } else {
        perror("setrlimit failed");
    }

    return 0;
}


/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM3$ g++ 3.c -o 3

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM3$ ./3

Resource limit set successfully.

Soft limit: 50, Hard limit: 100


===================================================================================================================
*/

