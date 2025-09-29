/*
===================================================================================================================
Name: 19.d.c
Author: VIVEK JOSHI
Description:-Create a FIFO file by
d. mknod system call

Date: 29 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    const char *fifo_name = "myfifo using mknod system call";

    if (mknod(fifo_name, S_IFIFO | 0666, 0) == -1) {
        perror("mknod");
        exit(1);
    }

    printf("FIFO file '%s' created successfully.\n", fifo_name);
    return 0;
}




/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM19$ g++ 19.d.c -o 19d

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM19$ ./19d

FIFO file 'myfifo using mknod system call' created successfully.


===================================================================================================================
*/

