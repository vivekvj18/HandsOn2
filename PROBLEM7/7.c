/*
===================================================================================================================
Name: 7.c
Author: VIVEK JOSHI
Description:- Write a simple program to print the created thread ids.

Date: 01 Oct 2025
===================================================================================================================
*/

#include <stdio.h>
#include <pthread.h>

void* threadFunction(void* arg) {
    printf("Hello from thread! Thread ID: %lu\n", pthread_self());
    return NULL;
}

int main() {
    pthread_t t1, t2, t3;

    // Create threads
    pthread_create(&t1, NULL, threadFunction, NULL);
    pthread_create(&t2, NULL, threadFunction, NULL);
    pthread_create(&t3, NULL, threadFunction, NULL);

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

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM7$ g++ 7.c -o 7

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM7$ ./7

Hello from thread! Thread ID: 124149844408000
Hello from thread! Thread ID: 124149836015296
Hello from thread! Thread ID: 124149827622592
All threads finished.




===================================================================================================================
*/

