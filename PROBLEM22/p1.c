/*
===================================================================================================================
Name: 22.c
Author: VIVEK JOSHI
Description:-Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.

Date: 29 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/select.h>

int main() {
    const char *fifo_name = "myfifo";
    mkfifo(fifo_name, 0666);

    int fd = open(fifo_name, O_RDONLY | O_NONBLOCK);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    fd_set readfds;
    struct timeval timeout;

    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Waiting for data on FIFO for 10 seconds...\n");

    int ret = select(fd + 1, &readfds, NULL, NULL, &timeout);

    if (ret == -1) {
        perror("select");
        close(fd);
        exit(1);
    } else if (ret == 0) {
        printf("No data received within 10 seconds.\n");
    } else {
        if (FD_ISSET(fd, &readfds)) {
            char buffer[100];
            int n = read(fd, buffer, sizeof(buffer)-1);
            if (n > 0) {
                buffer[n] = '\0';
                printf("Received: %s\n", buffer);
            }
        }
    }

    close(fd);
    return 0;
}



/*  
                                                      OUTPUT
===================================================================================================================

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM22$ g++ p1.c -o p1

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM22$ ./p1

Waiting for data on FIFO for 10 seconds...

No data received within 10 seconds.

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM22$ ./p1

Waiting for data on FIFO for 10 seconds...

Received: Hello Vivek





===================================================================================================================
*/

