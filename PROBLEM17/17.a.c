/*
===================================================================================================================
Name: 17.c
Author: VIVEK JOSHI
Description:-Write a program to execute ls -l | wc.
a. use dup

Date: 29 Sept 2025
===================================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipefd[2];
    if (pipe(pipefd) == -1) { perror("pipe"); exit(1); }

    pid_t pid1 = fork();
    if (pid1 == 0) { // First child -> ls -l
        close(pipefd[0]);                 // close unused read end
        close(STDOUT_FILENO);             // close stdout
        dup(pipefd[1]);                   // duplicate write end to lowest fd (1)
        close(pipefd[1]);                 // not needed after dup
        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls");
        exit(1);
    }

    pid_t pid2 = fork();
    if (pid2 == 0) { // Second child -> wc
        close(pipefd[1]);                 // close unused write end
        close(STDIN_FILENO);              // close stdin
        dup(pipefd[0]);                   // duplicate read end to lowest fd (0)
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

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM17$ gcc 17.a.c -o 17a

17.a.c: In function ‘main’:

17.a.c:45:5: warning: implicit declaration of function ‘wait’ [-Wimplicit-function-declaration]
   45 |     wait(NULL);
      |     ^~~~
vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM17$ ./17a

3      20     128



===================================================================================================================
*/

