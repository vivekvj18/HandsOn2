/*
===================================================================================================================
Name: 24.c
Author: VIVEK JOSHI
Description:-Write a program to create a message queue and print the key and message queue id.

Date: 30 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key = ftok("progfile", 65); // generate unique key
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    int msqid = msgget(key, 0666 | IPC_CREAT); // create message queue
    if (msqid == -1) {
        perror("msgget");
        exit(1);
    }

    printf("Message Queue created successfully.\n");
    printf("Key: %d\n", key);
    printf("Message Queue ID: %d\n", msqid);

    return 0;
}



/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM24$ touch progfile

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM24$ ./24

Message Queue created successfully.

Key: 1091112339

Message Queue ID: 0



===================================================================================================================
*/

