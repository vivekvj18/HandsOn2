/*
===================================================================================================================
Name: 13.c
Author: VIVEK JOSHI
Description:-Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.

Date: 30 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught signal %d\n", sig);
}

int main() {
    signal(SIGSTOP, handler); 
    printf("My PID is %d, waiting for SIGSTOP...\n", getpid());
    while (1) {
        sleep(1);
    }
    return 0;
}







/*  
                                                      OUTPUT
===================================================================================================================

TERMINAL-1

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM13$ g++ receiver.c -o receiver

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM13$ g++ sender.c -o sender

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM13$ ./receiver

My PID is 4483, waiting for SIGSTOP...

[1]+  Stopped                 ./receiver

-------------------------------------------------------------------------------------------------------------------

TERMINAL-2

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM13$ ./sender 4483

Sending SIGSTOP to process 4483


===================================================================================================================
*/

