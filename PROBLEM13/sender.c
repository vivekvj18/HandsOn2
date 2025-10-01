/*
===================================================================================================================
Name: sender.c
Author: VIVEK JOSHI
Description:-Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.

Date: 30 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <pid>\n", argv[0]);
        return 1;
    }
    int pid = atoi(argv[1]);
    printf("Sending SIGSTOP to process %d\n", pid);
    kill(pid, SIGSTOP);
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

