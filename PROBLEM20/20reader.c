/*
===================================================================================================================
Name: 20.c
Author: VIVEK JOSHI
Description:-Write two programs so that both can communicate by FIFO -Use one way communication.

Date: 29 Sept 2025
===================================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    const char *fifo_name = "myfifo";
    mkfifo(fifo_name, 0666);

    int fd = open(fifo_name, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    char buffer[100];
    read(fd, buffer, sizeof(buffer));
    printf("Message read from FIFO: %s\n", buffer);
    close(fd);

    return 0;
}


/*  
                                                      OUTPUT
===================================================================================================================

TERMINAL ----1

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM20$ g++ 20reader.c -o 20r

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM20$ g++ 20writer.c -o 20w

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM20$ ./20r

Message read from FIFO: Hello from writer!

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM20$  

-------------------------------------------------------------------------------------------------------------

TERMINAL ----2

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM20$ ./20w

Message written to FIFO.

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM20$  




===================================================================================================================
*/

