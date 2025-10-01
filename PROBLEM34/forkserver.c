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
#include <sys/types.h>
#include <signal.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_client(int client_fd, int client_id) {
    char buffer[BUFFER_SIZE];

    printf("Client %d connected.\n", client_id);

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int valread = read(client_fd, buffer, BUFFER_SIZE);
        if (valread <= 0) break;

        buffer[strcspn(buffer, "\n")] = 0;
        printf("Client %d says: %s\n", client_id, buffer);

        printf("Server reply to client %d: ", client_id);
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0;

        write(client_fd, buffer, strlen(buffer));
    }

    printf("Client %d disconnected.\n", client_id);
    close(client_fd);
    exit(0); // important to terminate child process
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    int client_count = 0;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) { perror("Socket failed"); exit(1); }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) { perror("Bind failed"); exit(1); }
    if (listen(server_fd, 5) < 0) { perror("Listen failed"); exit(1); }

    signal(SIGCHLD, SIG_IGN); // prevent zombie processes

    printf("Server listening on port %d\n", PORT);

    while (1) {
        client_fd = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
        if (client_fd < 0) { perror("Accept failed"); continue; }

        client_count++;
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            close(server_fd);
            handle_client(client_fd, client_count);
        } else if (pid > 0) {
            // Parent process
            close(client_fd);
        } else {
            perror("Fork failed");
        }
    }

    close(server_fd);
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

