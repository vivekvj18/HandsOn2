/*
===================================================================================================================
Name: 16.c
Author: VIVEK JOSHI
Description:-Write a program to send and receive data from parent to child vice versa. Use two way
communication.

Date: 25 Sept 2025
===================================================================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int fd1[2];
    int fd2[2];
    char parent_msg[] = "Hello Child!";
    char child_msg[]  = "Hello Parent!";
    char buffer[100];

    if (pipe(fd1) == -1 || pipe(fd2) == -1) {
        perror("Pipe creation failed");
        exit(1);
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid > 0) {
        close(fd1[0]);
        close(fd2[1]);
        write(fd1[1], parent_msg, strlen(parent_msg) + 1);
        read(fd2[0], buffer, sizeof(buffer));
        printf("Parent received: %s\n", buffer);
        close(fd1[1]);
        close(fd2[0]);
    } else {
        close(fd1[1]);
        close(fd2[0]);
        read(fd1[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        write(fd2[1], child_msg, strlen(child_msg) + 1);
        close(fd1[0]);
        close(fd2[1]);
    }

    return 0;
}





/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM16$ g++ 16.c -o 16

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM16$ ./16

Child received: Hello Child!

Parent received: Hello Parent!


===================================================================================================================
*/

