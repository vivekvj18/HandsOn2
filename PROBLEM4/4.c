/*
===================================================================================================================
Name: 4.c
Author: VIVEK JOSHI
Description:- Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.

Date: 01 Oct 2025
===================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

static inline uint64_t rdtsc(){
    unsigned int lo, hi;
    __asm__ volatile ("rdtsc" : "=a"(lo), "=d"(hi));
    return ((uint64_t)hi << 32) | lo;
}

int main() {
    uint64_t start, end;
    start = rdtsc();

    for(int i = 0; i < 100; i++) {
        getppid();  // system call
    }

    end = rdtsc();

    printf("Time taken for 100 getppid() calls: %llu clock cycles\n", (end - start));
    return 0;
}


/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM4$ ./4

Time taken for 100 getppid() calls: 135856 clock cycles


===================================================================================================================
*/

