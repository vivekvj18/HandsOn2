/*
===================================================================================================================
Name: 19.b.c
Author: VIVEK JOSHI
Description:-Create a FIFO file by
b. mkfifo command

Date: 29 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    const char *fifo_name = "my fifo using mkfifo";

    if (mkfifo(fifo_name, 0666) == -1) {
        perror("mkfifo");
        exit(1);
    }

    printf("FIFO file '%s' created successfully.\n", fifo_name);
    return 0;
}



/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM19$ g++ 19.b.c -o 19b

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM19$ ./19b

FIFO file 'my fifo using mkfifo' created successfully.





===================================================================================================================
*/

