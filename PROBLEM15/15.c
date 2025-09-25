/*
===================================================================================================================
Name: 15.c
Author: VIVEK JOSHI
Description:-Write a simple program to create a pipe, write to the pipe, read from pipe and display on the monitor.

Date: 25 Sept 2025
===================================================================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int fd[2];
    char message[] = "HELLO CHILD, I AM PARENT....!!!!";
    char buffer[100];

    if (pipe(fd) == -1) {
        perror("Pipe creation failed");
        exit(1);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid > 0) {
        close(fd[0]);
        write(fd[1], message, strlen(message) + 1);
        close(fd[1]);
    } else {
        close(fd[1]);
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(fd[0]);
    }

    return 0;
}






/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM15$ g++ 15.c -o 15

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM15$ ./15

Child received: HELLO CHILD, I AM PARENT....!!!!


===================================================================================================================
*/

