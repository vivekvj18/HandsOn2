/*
===================================================================================================================
Name: 32.c
Author: VIVEK JOSHI
Description:- Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
b. protect shared memory from concurrent write access
c. protect multiple pseudo resources ( may be two) using counting semaphore
d. remove the created semaphore

Date: 30 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

void sem_wait(int semid, int semnum) {
    struct sembuf sb = {semnum, -1, 0}; 
    semop(semid, &sb, 1);
}

void sem_signal(int semid, int semnum) {
    struct sembuf sb = {semnum, 1, 0};  
    semop(semid, &sb, 1);
}

int main() {
    key_t key = ftok("semfile", 65);
    int semid = semget(key, 2, 0666 | IPC_CREAT); // 2 semaphores: [0]=binary, [1]=counting
    if (semid == -1) { perror("semget"); exit(1); }

    union semun u;
    u.val = 1; semctl(semid, 0, SETVAL, u); // binary semaphore
    u.val = 2; semctl(semid, 1, SETVAL, u); // counting semaphore (2 resources)

    // a) Ticket number creation with semaphore
    int shmid = shmget(key, sizeof(int), 0666 | IPC_CREAT);
    int *ticket = (int*) shmat(shmid, NULL, 0);
    *ticket = 0;

    printf("\n--- Ticket Counter with Semaphore ---\n");
    for (int i = 0; i < 3; i++) {
        sem_wait(semid, 0); // lock
        (*ticket)++;
        printf("Process got Ticket #%d\n", *ticket);
        sem_signal(semid, 0); // unlock
        sleep(1);
    }

    // b) Protect shared memory write
    printf("\n--- Shared Memory Write with Protection ---\n");
    char *msg = (char*) shmat(shmid, NULL, 0);
    sem_wait(semid, 0);
    sprintf(msg, "Hello from process %d", getpid());
    printf("Wrote to shared memory: %s\n", msg);
    sem_signal(semid, 0);

    // c) Multiple pseudo resources (like 2 printers)
    printf("\n--- Using Counting Semaphore (2 resources) ---\n");
    for (int i = 0; i < 4; i++) {
        sem_wait(semid, 1); // take resource
        printf("Process %d using resource...\n", i+1);
        sleep(1);
        printf("Process %d done.\n", i+1);
        sem_signal(semid, 1); // release resource
    }

    // d) Remove semaphore and shared memory
    shmdt(ticket);
    shmctl(shmid, IPC_RMID, NULL);
    semctl(semid, 0, IPC_RMID);

    printf("\nSemaphore and Shared Memory removed.\n");
    return 0;
}


/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM32$ g++ 32.c -o 32

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM32$ ./32


--- Ticket Counter with Semaphore ---
Process got Ticket #1
Process got Ticket #2
Process got Ticket #3

--- Shared Memory Write with Protection ---
Wrote to shared memory: Hello from process 25601

--- Using Counting Semaphore (2 resources) ---
Process 1 using resource...
Process 1 done.
Process 2 using resource...
Process 2 done.
Process 3 using resource...
Process 3 done.
Process 4 using resource...
Process 4 done.




===================================================================================================================
*/

