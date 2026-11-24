#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>

int main(){
    int server_socket,client_socket;
    struct sockaddr_in server_addr;
    char buffer[1024];

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket(struct sockaddr*)&server_addr,sizeof(server_addr));
    listen(server_socket,5);
    printf("server is waiting for the client");
    client_socket = accept(server_socket,NULL,NULL);
    printf("client connected");
    while(1){
        memset(buffer,0,sizeof(buffer));
        int bytes = recv(client_socket,buffer,sizeof(buffer)-1,0);
        if(buytes<=0)break;
        printf("client \n:",buffer);
        if(strcmp(buffer == 'exit')==0)
        break;
        printf("enter reply:");
        fgets(buffer,sizeof(buffer),stdin);
        buffer[strcspn(buffer,"\n")] = '\0';
        send(client_socket,buffer,strlen(buffer)+1,0);
    }
    close(client_socket);
    close(server_socket);
    return 0;
}

