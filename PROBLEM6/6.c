/*
===================================================================================================================
Name: 6.c
Author: VIVEK JOSHI
Description:- Write a simple program to create three threads.

Date: 01 Oct 2025
===================================================================================================================
*/

#include <stdio.h>
#include <pthread.h>

void* threadFunction(void* arg) {
    int id = *(int*)arg;
    printf("Hello from thread %d\n", id);
    return NULL;
}

int main() {
    pthread_t t1, t2, t3;
    int id1 = 1, id2 = 2, id3 = 3;

    // Create three threads
    pthread_create(&t1, NULL, threadFunction, &id1);
    pthread_create(&t2, NULL, threadFunction, &id2);
    pthread_create(&t3, NULL, threadFunction, &id3);

    // Wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    printf("All threads finished.\n");
    return 0;
}


/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM6$ g++ 6.c -o 6

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM6$ ./6

Hello from thread 2

Hello from thread 3

Hello from thread 1

All threads finished.



===================================================================================================================
*/

