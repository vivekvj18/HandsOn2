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
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

typedef struct {
    int client_fd;
    int id;
} client_info;

void* client_handler(void* arg) {
    client_info* info = (client_info*)arg;
    int client_fd = info->client_fd;
    char buffer[BUFFER_SIZE];

    printf("Client %d connected.\n", info->id);

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int valread = read(client_fd, buffer, BUFFER_SIZE);
        if (valread <= 0) break;

        buffer[strcspn(buffer, "\n")] = 0;
        printf("Client %d says: %s\n", info->id, buffer);

        printf("Server reply to client %d: ", info->id);
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0;

        write(client_fd, buffer, strlen(buffer));
    }

    printf("Client %d disconnected.\n", info->id);
    close(client_fd);
    free(info);
    pthread_exit(NULL);
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

    printf("Server listening on port %d\n", PORT);

    while (1) {
        client_fd = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
        if (client_fd < 0) { perror("Accept failed"); continue; }

        pthread_t tid;
        client_info* info = malloc(sizeof(client_info));
        info->client_fd = client_fd;
        info->id = ++client_count;

        pthread_create(&tid, NULL, client_handler, info);
        pthread_detach(tid); // resources freed automatically
    }

    close(server_fd);
    return 0;
}


/*  
                                                      OUTPUT
===================================================================================================================

TERMINAL-1

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM33$ g++ server.c -o server

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM33$ g++ client.c -o client

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM33$ ./server

Server listening on port 8080
Client says: Hi Server, Vivek Joshi This Side..!
Server reply: Hello...!   

--------------------------------------------------------------------------------------------------------------

TERMINAL-2

vivekjoshi@vivekj:~/Desktop/MTECH CSE 2025/SOFTWARE SYSTEMS/HANDSON2/PROBLEM33$ ./client

You: Hi Server, Vivek Joshi This Side..!
Server: Hello...!
You: exit




===================================================================================================================
*/

