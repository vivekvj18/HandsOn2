/*
===================================================================================================================
Name: 14.c
Author: VIVEK JOSHI
Description:-Write a simple program to create a pipe, write to the pipe, read from pipe and display on the monitor.

Date: 25 Sept 2025
===================================================================================================================
*/

#include <stdio.h>      
#include <unistd.h>     
#include <string.h>     

int main() {
    int fd[2];                        
    char write_msg[] = "ThIS IS A MESSAGE FROM PIPE....!!!";
    char read_msg[100];

    
    if (pipe(fd) == -1) {
        perror("pipe failed");
        return 1;
    }
    
    write(fd[1], write_msg, strlen(write_msg) + 1); // +1 for '\0'
    
    read(fd[0], read_msg, sizeof(read_msg));

    printf("Message read from pipe: %s\n", read_msg);

    close(fd[0]);
    close(fd[1]);

    return 0;
}







/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM14$ g++ 14.c -o 14

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM14$ ./14

Message read from pipe: ThIS IS A MESSAGE FROM PIPE....!!!


===================================================================================================================
*/

