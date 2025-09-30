/*
===================================================================================================================
Name: 30.c
Author: VIVEK JOSHI
Description:- Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory

Date: 30 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    char *str = (char*) shmat(shmid, NULL, 0);
    if (str == (char*)-1) {
        perror("shmat");
        exit(1);
    }
    printf("Writing to shared memory...\n");
    strcpy(str, "Hello Shared Memory!");
    printf("Data written: %s\n", str);

    char *readonly = (char*) shmat(shmid, NULL, SHM_RDONLY);
    if (readonly == (char*)-1) {
        perror("shmat read-only");
        exit(1);
    }
    printf("Reading in read-only mode: %s\n", readonly);
    printf("Trying to overwrite in read-only mode...\n");

    shmdt(str);
    shmdt(readonly);
    shmctl(shmid, IPC_RMID, NULL);
    printf("Shared memory removed.\n");

    return 0;
}


/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM30$ touch shmfile

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM30$ g++ 30.c -o 30

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM30$ ./30

Writing to shared memory...

Data written: Hello Shared Memory!

Reading in read-only mode: Hello Shared Memory!

Trying to overwrite in read-only mode...

Shared memory removed.



===================================================================================================================
*/

