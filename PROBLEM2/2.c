/*
===================================================================================================================
Name: 2.c
Author: VIVEK JOSHI
Description:- Write a program to print the system resource limits. Use getrlimit system call.

Date: 01 Oct 2025
===================================================================================================================
*/

#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

void print_limit(int resource, const char* name) {
    struct rlimit rl;
    if (getrlimit(resource, &rl) == 0) {
        printf("%s:\n", name);
        printf("  Soft limit: %ld\n", rl.rlim_cur);
        printf("  Hard limit: %ld\n\n", rl.rlim_max);
    } else {
        perror("getrlimit failed");
    }
}

int main() {
    print_limit(RLIMIT_CPU, "CPU time (seconds)");
    print_limit(RLIMIT_FSIZE, "Maximum file size (bytes)");
    print_limit(RLIMIT_DATA, "Maximum data size (bytes)");
    print_limit(RLIMIT_STACK, "Maximum stack size (bytes)");
    print_limit(RLIMIT_NOFILE, "Maximum number of open files");
    print_limit(RLIMIT_AS, "Maximum virtual memory size (bytes)");
    return 0;
}


/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM2$ g++ 2.c -o 2

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM2$ ./2

CPU time (seconds):
  Soft limit: -1
  Hard limit: -1

Maximum file size (bytes):
  Soft limit: -1
  Hard limit: -1

Maximum data size (bytes):
  Soft limit: -1
  Hard limit: -1

Maximum stack size (bytes):
  Soft limit: 8388608
  Hard limit: -1

Maximum number of open files:
  Soft limit: 1024
  Hard limit: 1048576

Maximum virtual memory size (bytes):
  Soft limit: -1
  Hard limit: -1



===================================================================================================================
*/

