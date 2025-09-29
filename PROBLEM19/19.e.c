/*
===================================================================================================================
Name: 19.e.c
Author: VIVEK JOSHI
Description:-Create a FIFO file by
e. mkfifo library function

Date: 29 Sept 2025
===================================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    const char *fifo_name = "myfifo using mkfifo library function";

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

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM19$ g++ 19.e.c -o 19e

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM19$ ./19e

FIFO file 'myfifo using mkfifo library function' created successfully.



===================================================================================================================
*/

