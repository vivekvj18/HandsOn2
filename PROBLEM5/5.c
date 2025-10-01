/*
===================================================================================================================
Name: 5.c
Author: VIVEK JOSHI
Description:- Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.

Date: 01 Oct 2025
===================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

int main() {
    // a. Maximum length of arguments to exec functions
    long arg_max = sysconf(_SC_ARG_MAX);
    printf("Maximum length of arguments to exec: %ld\n", arg_max);

    // b. Maximum number of simultaneous processes per user id
    long proc_max = sysconf(_SC_CHILD_MAX);
    printf("Maximum number of simultaneous processes per user ID: %ld\n", proc_max);

    // c. Number of clock ticks (jiffy) per second
    long ticks = sysconf(_SC_CLK_TCK);
    printf("Number of clock ticks per second: %ld\n", ticks);

    // d. Maximum number of open files
    long open_max = sysconf(_SC_OPEN_MAX);
    printf("Maximum number of open files: %ld\n", open_max);

    // e. Size of a page
    long page_size = sysconf(_SC_PAGESIZE);
    printf("Page size: %ld bytes\n", page_size);

    // f. Total number of pages in physical memory
    long total_pages = sysconf(_SC_PHYS_PAGES);
    printf("Total number of pages in physical memory: %ld\n", total_pages);

    // g. Number of currently available pages in physical memory
    long avail_pages = sysconf(_SC_AVPHYS_PAGES);
    printf("Number of currently available pages: %ld\n", avail_pages);

    return 0;
}



/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM5$ g++ 5.c -o 5

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM5$ ./5

Maximum length of arguments to exec: 2097152
Maximum number of simultaneous processes per user ID: 61524
Number of clock ticks per second: 100
Maximum number of open files: 1024
Page size: 4096 bytes
Total number of pages in physical memory: 3996422
Number of currently available pages: 1978205



===================================================================================================================
*/

