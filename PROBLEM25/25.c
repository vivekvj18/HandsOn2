/*
===================================================================================================================
Name: 25.c
Author: VIVEK JOSHI
Description:-Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv

Date: 30 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <time.h>

int main() {
    key_t key = ftok("progfile", 65);
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    int msqid = msgget(key, 0666 | IPC_CREAT);
    if (msqid == -1) {
        perror("msgget");
        exit(1);
    }

    struct msqid_ds info;

    if (msgctl(msqid, IPC_STAT, &info) == -1) {
        perror("msgctl");
        exit(1);
    }

    printf("Message Queue Info:\n");
    printf("-------------------\n");
    printf("Access permissions: %o\n", info.msg_perm.mode & 0777);
    printf("Owner UID: %d\n", info.msg_perm.uid);
    printf("Owner GID: %d\n", info.msg_perm.gid);
    printf("Time of last message sent: %s", ctime(&info.msg_stime));
    printf("Time of last message received: %s", ctime(&info.msg_rtime));
    printf("Time of last change in queue: %s", ctime(&info.msg_ctime));
    printf("Current number of bytes in queue: %ld\n", info.msg_cbytes);
    printf("Number of messages in queue: %ld\n", info.msg_qnum);
    printf("Maximum bytes allowed in queue: %ld\n", info.msg_qbytes);
    printf("PID of last msgsnd: %d\n", info.msg_lspid);
    printf("PID of last msgrcv: %d\n", info.msg_lrpid);

    return 0;
}



/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM25$ g++ 25.c -o 25

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM25$ touch progfile

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM25$ ./25

Message Queue Info:
-------------------
Access permissions: 666
Owner UID: 1000
Owner GID: 1000
Time of last message sent: Thu Jan  1 05:30:00 1970
Time of last message received: Thu Jan  1 05:30:00 1970
Time of last change in queue: Tue Sep 30 14:24:58 2025
Current number of bytes in queue: 0
Number of messages in queue: 0
Maximum bytes allowed in queue: 16384
PID of last msgsnd: 0
PID of last msgrcv: 0




===================================================================================================================
*/

