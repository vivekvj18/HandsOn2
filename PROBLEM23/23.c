/*
===================================================================================================================
Name: 23.c
Author: VIVEK JOSHI
Description:-Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).

Date: 30 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>

int main() {
    long max_files = sysconf(_SC_OPEN_MAX);
    printf("Maximum number of files that can be opened in a process: %ld\n", max_files);

    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    long pipe_size = fpathconf(fd[0], _PC_PIPE_BUF);
    printf("Pipe buffer size: %ld bytes\n", pipe_size);

    close(fd[0]);
    close(fd[1]);

    return 0;
}


/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM23$ g++ 23.c -o 23

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM23$ ./23

Maximum number of files that can be opened in a process: 1024

Pipe buffer size: 4096 bytes


===================================================================================================================
*/

