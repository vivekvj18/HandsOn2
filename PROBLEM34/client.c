/*
===================================================================================================================
Name: 34.c
Author: VIVEK JOSHI
Description:- Write a program to create a concurrent server.
a. use fork
b. use pthread_create

Date: 01 Oct 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SERVER_IP "127.0.0.1"  // Replace with server IP if on another machine
#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) { perror("Socket creation failed"); exit(1); }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (connect(sock, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        exit(1);
    }

    printf("Connected to server. Type messages (type 'exit' to quit):\n");

    while (1) {
        printf("You: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0; // remove newline

        write(sock, buffer, strlen(buffer));

        if (strcmp(buffer, "exit") == 0) break;

        memset(buffer, 0, BUFFER_SIZE);
        int valread = read(sock, buffer, BUFFER_SIZE);
        if (valread <= 0) break;

        buffer[strcspn(buffer, "\n")] = 0;
        printf("Server: %s\n", buffer);
    }

    close(sock);
    return 0;
}


/*  
                                                      OUTPUT
===================================================================================================================

TERMINAL-1

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM34$ g++ forkserver.c -o forkserver

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM34$ g++ client.c -o client

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM34$ ./forkserver

Server listening on port 8080

Client 1 connected.
Client 1 says: Hi, I am client 1
Server reply to client 1: Hello Client 1

Client 2 connected.
Client 2 says: Hi, I am client 2
Server reply to client 2: Hello Client 2


--------------------------------------------------------------------------------------------------------------

TERMINAL-2

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM34$ ./client

Connected to server. Type messages (type 'exit' to quit):

You: Hi, I am client 1
Server: Hello Client 1
You: exit

--------------------------------------------------------------------------------------------------------------

TERMINAL-3

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM34$ ./client

Connected to server. Type messages (type 'exit' to quit):

You: Hi, I am client 2
Server: Hello Client 2
You: exit


===================================================================================================================
*/

