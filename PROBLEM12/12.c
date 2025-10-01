/*
===================================================================================================================
Name: 12.c
Author: VIVEK JOSHI
Description:-Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.

Date: 01 Oct 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid > 0) {
        printf("Parent: PID=%d, child PID=%d\n", getpid(), pid);
        printf("Parent: sleeping 10s (child will kill me)...\n");
        sleep(10);
        printf("Parent: woke up and exiting normally (this line should not appear if killed).\n");
        exit(0);
    } else {
        sleep(1);
        pid_t ppid = getppid();
        printf("Child: my PID=%d, parent PID=%d\n", getpid(), ppid);
        printf("Child: sending SIGKILL to parent (%d)\n", ppid);
        if (kill(ppid, SIGKILL) == -1) {
            perror("kill");
        }
        sleep(1);
        printf("Child: after kill attempt, my parent PID=%d\n", getppid());
        printf("Child: I am now an orphan (adopted by init/systemd). Sleeping 5s to observe...\n");
        sleep(5);
        printf("Child: exiting now.\n");
        exit(0);
    }
}
  







/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM12$ g++ 12.c -o 12

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM12$ ./12

Parent: PID=5434, child PID=5435
Parent: sleeping 10s (child will kill me)...
Child: my PID=5435, parent PID=5434
Child: sending SIGKILL to parent (5434)
Killed

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM12$ Child: after kill attempt, my parent PID=2288

Child: I am now an orphan (adopted by init/systemd). Sleeping 5s to observe...
Child: exiting now.



===================================================================================================================
*/

