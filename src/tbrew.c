// (C) 2023 Token Studios
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>

#include <tbrew.h>
#include <client.h>
#include <vec.h>
#include <language.h>
#include <parcel.h>
#include <constants.h>

int main(void) {
    printf(LANG_LOGO);

    // Server Initialization
    uint16_t fd_tcp, fd_udp;
    struct sockaddr_in addr_tcp, addr_udp, addr_cli;

    memset(&addr_tcp, 0, sizeof(addr_tcp));
    addr_tcp.sin_family = AF_INET;
    addr_tcp.sin_port = htons(TCP_PORT);
    addr_tcp.sin_addr.s_addr = htonl(INADDR_ANY);
    memset(&addr_udp, 0, sizeof(addr_udp));
    addr_udp.sin_family = AF_INET;
    addr_udp.sin_port = htons(UDP_PORT);
    addr_udp.sin_addr.s_addr = htonl(INADDR_ANY);

    // Socket Opening
    if ((fd_tcp = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror(LANG_ERR_TCP_OPEN);
        return 1;
    } printf(LANG_TCP_OPEN);
    if ((fd_udp = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror(LANG_ERR_UDP_OPEN);
        return 1;
    } printf(LANG_UDP_OPEN);

    // Socket Binding
    if (bind(fd_tcp, (struct sockaddr *)&addr_tcp, sizeof(addr_tcp))) {
        fprintf(stderr, FLANG_ERR_TCP_BIND, TCP_PORT);
        return 1;
    } printf(FLANG_TCP_BIND, TCP_PORT);
    if (bind(fd_udp, (struct sockaddr *)&addr_udp, sizeof(addr_udp))) {
        fprintf(stderr, FLANG_ERR_UDP_BIND, UDP_PORT);
        return 1;
    } printf(FLANG_UDP_BIND, UDP_PORT);

    // TCP Listening
    if (listen(fd_tcp, 5) != 0) {
        perror(LANG_ERR_TCP_LISTEN);
        return 1;
    } printf(LANG_LISTENING);

    // Vector of Clients
    Vec *clients = new_vec(sizeof(Client));

    // UDP Shitz
    pthread_t *udp_thread = malloc(sizeof(pthread_t));
    pthread_create(udp_thread, NULL, listen_udp, &(UArgs){&fd_udp, clients});

    for (;;) {
        // Accept TCP Connections
        socklen_t socksize = sizeof(addr_cli);
        const uint16_t fd = accept(fd_tcp, (struct sockaddr *)&addr_cli, &socksize);
        printf(FLANG_TCP_CONNECTION, inet_ntoa(addr_cli.sin_addr), htons(addr_cli.sin_port));

        // Client Initialization
        Client *client = malloc(sizeof(Client));
        client->address = addr_cli;
        client->fd = fd;
        client->active = true;
        client->critical_thread = malloc(sizeof(pthread_t));
        client->parcel = malloc(sizeof(Parcel));

        // THROW HIM TO THE WOLVES
        client = vec_puts(clients, client);
        pthread_create(client->critical_thread, NULL, listen_critical, client);
    }
}


void *listen_udp(void *args) {
    // PThread Args
    const uint16_t fd = *((UArgs*)args)->fd;
    const Vec *clients = ((UArgs*)args)->clients;

    // Socket Shitz
    struct sockaddr_in addr;
    socklen_t socksize = sizeof(addr);

    for (;;) {
        // Receive UDP Parcel
        char buffer[sizeof(Parcel)];
        const uint16_t len = recvfrom(fd, buffer, sizeof(buffer), 0, (struct sockaddr *)&addr, &socksize);
        if (len != sizeof(Parcel)) {
            printf("%d\t%lu\n", len, sizeof(Parcel));
            fprintf(stderr, LANG_ERR_UDP_CORRUPT); // TODO: Send reject packet?
            continue;
        }

        // WHAT THE FUCK
        const Parcel *parcel = buffer;

        for (uint8_t i = 0; i < clients->size; i++) {
            const Client *client = vec_gets(clients, i);
            if (strcmp(client->sesid, parcel->uuid) == 0) {
                memmove(client->parcel, parcel, sizeof(Parcel));
                // TODO: Send update to all other clients
                message_out(client->fd, client->sesid, 37, m_uuid);
                break;
            }
        }
    }
}