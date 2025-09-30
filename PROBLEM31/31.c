/*
===================================================================================================================
Name: 31.c
Author: VIVEK JOSHI
Description:- Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
b. create a counting semaphore

Date: 30 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int main() {
    key_t key = ftok("semfile", 65);
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    int semid = semget(key, 2, 0666 | IPC_CREAT);
    if (semid == -1) {
        perror("semget");
        exit(1);
    }

    union semun u;

    u.val = 1; 
    if (semctl(semid, 0, SETVAL, u) == -1) {
        perror("semctl binary");
        exit(1);
    }
    printf("Binary semaphore created with value = 1\n");

    u.val = 3; 
    if (semctl(semid, 1, SETVAL, u) == -1) {
        perror("semctl counting");
        exit(1);
    }
    printf("Counting semaphore created with value = 3\n");

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

