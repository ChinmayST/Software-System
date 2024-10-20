/*
============================================================================
Name : 34a.c
Author : Chinmay Tavarej
Description : Write a program to create a concurrent server.    a. use fork    b. use pthread_create
Date: 10th Oct, 2024
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void handle_client(int client_socket) {
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    recv(client_socket, buffer, sizeof(buffer), 0);
    printf("Received message: %s\n", buffer);

    const char* response = "Hello from the server!";
    send(client_socket, response, strlen(response), 0);

    close(client_socket);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating server socket");
        exit(1);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int opt = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("Error setting socket options");
        exit(1);
    }

    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    if (listen(server_socket, 5) < 0) {
        perror("Error listening for connections");
        exit(1);
    }

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("Error accepting client connection");
            exit(1);
        }

        if (fork() == 0) {
            close(server_socket);
            handle_client(client_socket);
            exit(0);
        } else {
            close(client_socket);
        }
    }

    close(server_socket);
    return 0;
}


/*
============================================================================
Output : 

iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/34$ gcc 34aClient.c -o 34aClient
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/34$ gcc 34aServer.c -o 34aServer

iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/34$ ./34aServer
Received message: Hello from the client!

iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/34$ ./34aClient
Received message: Hello from the server!

============================================================================
*/ 



