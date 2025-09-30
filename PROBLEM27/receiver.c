/*
===================================================================================================================
Name: 27.c
Author: VIVEK JOSHI
Description:- Write a program to receive messages from the message queue.
a. with 0 as a flag
b. with IPC_NOWAIT as a flag

Date: 30 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <errno.h>

// Define message buffer structure
struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;

    // Generate the same key used by sender
    key = ftok("msgfile", 65);
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Access the existing message queue
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    printf("Receiving message with flag = 0 (blocking)...\n");
    if (msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0) == -1) {
        perror("msgrcv");
    } else {
        printf("Received (blocking): %s\n", message.msg_text);
    }

    printf("\nReceiving message with flag = IPC_NOWAIT (non-blocking)...\n");
    if (msgrcv(msgid, &message, sizeof(message.msg_text), 1, IPC_NOWAIT) == -1) {
        if (errno == ENOMSG) {
            printf("No message available (non-blocking).\n");
        } else {
            perror("msgrcv");
        }
    } else {
        printf("Received (non-blocking): %s\n", message.msg_text);
    }

    return 0;
}



/*  
                                                      OUTPUT
===================================================================================================================



TERMINAL-1

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM27$ g++ sender.c -o sender

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM27$ g++ receiver.c -o receiver

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM27$ ./sender

Message sent: Hello from vivek....!
----------------------------------------------------------------------------------------------------------------

TERMINAL-2

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM27$ ./receiver

Receiving message with flag = 0 (blocking)...
Received (blocking): Hello from vivek....!

Receiving message with flag = IPC_NOWAIT (non-blocking)...
No message available (non-blocking). 


===================================================================================================================
*/

