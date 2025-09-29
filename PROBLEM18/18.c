/*
===================================================================================================================
Name: 18.c
Author: VIVEK JOSHI
Description:-Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.

Date: 29 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipe1[2], pipe2[2];
    pipe(pipe1);
    pipe(pipe2);

    if (fork() == 0) {                     
        dup2(pipe1[1], STDOUT_FILENO);   
        close(pipe1[0]); close(pipe1[1]);
        close(pipe2[0]); close(pipe2[1]);
        execlp("ls", "ls", "-l", NULL);  
        exit(1);
    }

    if (fork() == 0) {                     
        dup2(pipe1[0], STDIN_FILENO);    
        dup2(pipe2[1], STDOUT_FILENO);   
        close(pipe1[0]); close(pipe1[1]);
        close(pipe2[0]); close(pipe2[1]);
        execlp("grep", "grep", "^d", NULL);
        exit(1);
    }

    if (fork() == 0) {                     
        dup2(pipe2[0], STDIN_FILENO);    
        close(pipe1[0]); close(pipe1[1]);
        close(pipe2[0]); close(pipe2[1]);
        execlp("wc", "wc", "-l", NULL);  // -l to print only lines (directories)
        exit(1);
    }

    close(pipe1[0]); close(pipe1[1]);
    close(pipe2[0]); close(pipe2[1]);

    for (int i = 0; i < 3; i++) wait(NULL);

    return 0;
}




/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM18$ g++ 18.c -o 18a

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM18$ ./18a

0

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM18$ mkdir testdir

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM18$ g++ 18.c -o 18a

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM18$ ./18a

1




===================================================================================================================
*/

