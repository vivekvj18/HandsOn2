/*
===================================================================================================================
Name: 17.c
Author: VIVEK JOSHI
Description:-Write a program to execute ls -l | wc.
a. use fcntl

Date: 29 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int pipefd[2];
    if (pipe(pipefd) == -1) { perror("pipe"); exit(1); }

    if (fork() == 0) { // ls -l
        close(pipefd[0]);
        int newfd = fcntl(pipefd[1], F_DUPFD, STDOUT_FILENO);
        if (newfd != STDOUT_FILENO) {     // ensure it is exactly stdout
            dup2(newfd, STDOUT_FILENO);
            close(newfd);
        }
        close(pipefd[1]);
        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls");
        exit(1);
    }

    if (fork() == 0) { // wc
        close(pipefd[1]);
        int newfd = fcntl(pipefd[0], F_DUPFD, STDIN_FILENO);
        if (newfd != STDIN_FILENO) {
            dup2(newfd, STDIN_FILENO);
            close(newfd);
        }
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

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM17$ gcc 17.c.c -o 17c

17.c.c: In function ‘main’:

17.c.c:49:5: warning: implicit declaration of function ‘wait’ [-Wimplicit-function-declaration]
   49 |     wait(NULL);
      |     ^~~~

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM17$ ./17c
      7      56     366





===================================================================================================================
*/

