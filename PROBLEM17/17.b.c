/*
===================================================================================================================
Name: 17.c
Author: VIVEK JOSHI
Description:-Write a program to execute ls -l | wc.
a. use dup2

Date: 29 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipefd[2];
    if (pipe(pipefd) == -1) { perror("pipe"); exit(1); }

    if (fork() == 0) { // ls -l
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);   // pipe write -> stdout
        close(pipefd[1]);
        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls");
        exit(1);
    }

    if (fork() == 0) { // wc
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);    // pipe read -> stdin
        close(pipefd[0]);
        execlp("wc", "wc", NULL);
        perror("execlp wc");
        exit(1);
    }

    close(pipefd[0]);
    close(pipefd[1]);
    wait(NULL);
    wait(NULL);
    return 0;
}


/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM17$ gcc 17.b.c -o 17b

17.b.c: In function ‘main’:

17.b.c:40:5: warning: implicit declaration of function ‘wait’ [-Wimplicit-function-declaration]
   40 |     wait(NULL);
      |     ^~~~
vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM17$ ./17b

5      38     247




===================================================================================================================
*/

