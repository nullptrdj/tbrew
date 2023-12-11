// (C) 2023 Token Studios
#include <client.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>x
#include <arpa/inet.h>
#include <string.h>
#include <language.h>
#include <vec.h>
#include <pthread.h>

#define TCP_PORT 6342
#define UDP_PORT 8463

// ReSharper disable once CppDFAConstantFunctionResult
int main(void) {
    // Printing the Logo
    printf(LANG_LOGO);

    // Declaring vars
    int fd_tcp, fd_udp;
    struct sockaddr_in addr_tcp, addr_udp, addr_cli;

    // Prevent undefined behaviours
    memset(&addr_tcp, 0, sizeof(addr_tcp));
    addr_tcp.sin_family = AF_INET;
    addr_tcp.sin_port = htons(TCP_PORT);
    addr_tcp.sin_addr.s_addr = htonl(INADDR_ANY);
    memset(&addr_udp, 0, sizeof(addr_udp));
    addr_udp.sin_family = AF_INET;
    addr_udp.sin_port = htons(UDP_PORT);
    addr_udp.sin_addr.s_addr = htonl(INADDR_ANY);

    // Opening sockets
    if ((fd_tcp = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror(LANG_ERR_TCP_OPEN);
        return 1;
    } printf(LANG_TCP_OPEN);
    if ((fd_udp = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror(LANG_ERR_UDP_OPEN);
        return 1;
    } printf(LANG_UDP_OPEN);

    // Binding sockets
    if (bind(fd_tcp, (struct sockaddr *)&addr_tcp, sizeof(addr_tcp))) {
        fprintf(stderr, FLANG_ERR_TCP_BIND, TCP_PORT);
        return 1;
    } printf(FLANG_TCP_BIND, TCP_PORT);
    if (bind(fd_udp, (struct sockaddr *)&addr_udp, sizeof(addr_udp))) {
        fprintf(stderr, FLANG_ERR_UDP_BIND, UDP_PORT);
        return 1;
    } printf(FLANG_UDP_BIND, UDP_PORT);

    // Listen
    if (listen(fd_tcp, 5) != 0) {
        perror(LANG_ERR_TCP_LISTEN);
        return 1;
    } printf(LANG_LISTENING);

    // TODO: clients vector
    Vec *clients = new_vec(sizeof(Client));

    // ReSharper disable once CppDFAEndlessLoop
    for (;;) {
        socklen_t socksize = sizeof(addr_cli);
        accept(fd_tcp, (struct sockaddr *)&addr_cli, &socksize);
        printf(FLANG_TCP_CONNECTION, inet_ntoa(addr_cli.sin_addr), htons(addr_cli.sin_port));

        Client *client = malloc(sizeof(client));
        strcpy(client->token, "123456781234567");
        client->address = addr_cli;
        client->fd_tcp = &fd_tcp;
        client->fd_udp = &fd_udp;
        client->active = true;
        client->parcel = malloc(sizeof(Parcel));

        client = vec_puts(clients, client);
        pthread_create(client->critical_thread, NULL, listen_critical, client);
    }
}
