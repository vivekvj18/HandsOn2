/*
===================================================================================================================
Name: 21.c
Author: VIVEK JOSHI
Description:-Write two programs so that both can communicate by FIFO -Use two way communications.

Date: 29 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main() {
    mkfifo("fifo1", 0666);
    mkfifo("fifo2", 0666);

    char buffer[100];

    while (1) {
        int fd1 = open("fifo1", O_RDONLY);
        read(fd1, buffer, sizeof(buffer));
        close(fd1);

        if (strcmp(buffer, "exit") == 0) break;
        printf("Program1 says: %s\n", buffer);

        printf("Program2: Enter message: ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = 0;

        int fd2 = open("fifo2", O_WRONLY);
        write(fd2, buffer, strlen(buffer)+1);
        close(fd2);

        if (strcmp(buffer, "exit") == 0) break;
    }

    return 0;
}



/*  
                                                      OUTPUT
===================================================================================================================

TERMINAL ----1

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM21$ g++ p1.c -o p1

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM21$ g++ p2.c -o p2

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM21$ ./p1

Program1: Enter message: Hello Vivek Here...!!!

Program2 says: Hey Myself Raunak..!

Program1: Enter message: exit
 

-------------------------------------------------------------------------------------------------------------

TERMINAL ----2


vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM21$ ./p2

Program1 says: Hello Vivek Here...!!!

Program2: Enter message: Hey Myself Raunak..!

===================================================================================================================
*/

