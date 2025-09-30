/*
===================================================================================================================
Name: 26.c
Author: VIVEK JOSHI
Description:-Write a program to send messages to the message queue. Check $ipcs -q

Date: 30 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

// Define message buffer structure
struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key;
    int msgid;

    // Generate unique key
    key = ftok("msgfile", 65);   // msgfile must exist
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Create a message queue
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    struct msg_buffer message;
    message.msg_type = 1;  // Message type should be >0

    printf("Enter a message to send: ");
    fgets(message.msg_text, sizeof(message.msg_text), stdin);
    message.msg_text[strcspn(message.msg_text, "\n")] = '\0'; // remove newline

    // Send message
    if (msgsnd(msgid, &message, sizeof(message.msg_text), 0) == -1) {
        perror("msgsnd");
        exit(1);
    }

    printf("Message sent to queue successfully!\n");
    printf("Run 'ipcs -q' in another terminal to check the message queue.\n");

    return 0;
}




/*  
                                                      OUTPUT
===================================================================================================================



vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM26$ g++ 26.c -o 26

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM26$ ./26

Enter a message to send: Hi Vivek Here....!!!
Message sent to queue successfully!
Run 'ipcs -q' in another terminal to check the message queue.


vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM26$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x41090d93 0          vivekjoshi 666        0            0           
0x41090d98 1          vivekjoshi 666        0            0           
0x41090d9d 2          vivekjoshi 666        100          1    


===================================================================================================================
*/

