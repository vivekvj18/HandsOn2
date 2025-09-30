/*
===================================================================================================================
Name: 29.c
Author: VIVEK JOSHI
Description:- Write a program to remove the message queue.

Date: 30 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key;
    int msgid;

    // Generate a unique key (same as used while creating the queue)
    key = ftok("msgfile", 65);
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Get the message queue ID
    msgid = msgget(key, 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    // Remove the message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(1);
    }

    printf("Message queue removed successfully.\n");
    return 0;
}


/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM29$ g++ createqueue.c -o cq

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM29$ ./cq

Message queue created with ID: 8

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM29$ ipcs -q


------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x41090d93 0          vivekjoshi 666        0            0           
0x41090d98 1          vivekjoshi 666        0            0           
0x41090d9d 2          vivekjoshi 666        100          1           
0x41090cf9 3          vivekjoshi 666        0            0           
0x41090dac 4          vivekjoshi 666        0            0           
0x41090d5e 5          vivekjoshi 666        0            0           
0x41090d59 6          vivekjoshi 666        0            0           
0x41090cdf 7          vivekjoshi 666        0            0           
0x41090d66 8          vivekjoshi 666        0            0           


vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM29$ g++ 29.c -o 29

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM29$ ./29

Message queue removed successfully.

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM29$ ipcs -q


------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x41090d93 0          vivekjoshi 666        0            0           
0x41090d98 1          vivekjoshi 666        0            0           
0x41090d9d 2          vivekjoshi 666        100          1           
0x41090cf9 3          vivekjoshi 666        0            0           
0x41090dac 4          vivekjoshi 666        0            0           
0x41090d5e 5          vivekjoshi 666        0            0           
0x41090d59 6          vivekjoshi 666        0            0           
0x41090cdf 7          vivekjoshi 666        0            0 


===================================================================================================================
*/

