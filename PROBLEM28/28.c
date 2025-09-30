/*
===================================================================================================================
Name: 28.c
Author: VIVEK JOSHI
Description:- Write a program to change the exiting message queue permission. (use msqid_ds structure)

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
    struct msqid_ds buf;

    // Generate a unique key (make sure "msgfile" exists)
    key = ftok("msgfile", 65);
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Get the message queue (must already exist)
    msgid = msgget(key, 0600 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    // Get current info about the queue
    if (msgctl(msgid, IPC_STAT, &buf) == -1) {
        perror("msgctl IPC_STAT");
        exit(1);
    }

    printf("Old permissions: %o\n", buf.msg_perm.mode);

    // Change permissions (e.g., rw-rw-rw-)
    buf.msg_perm.mode = 0666;

    // Apply the new permissions
    if (msgctl(msgid, IPC_SET, &buf) == -1) {
        perror("msgctl IPC_SET");
        exit(1);
    }

    printf("New permissions set to: %o\n", buf.msg_perm.mode);

    return 0;
}


/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM28$ touch msgfile

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM28$ g++ 28.c -o 28

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM28$ ./28

Old permissions: 600

New permissions set to: 666


===================================================================================================================
*/

