// (C) 2023 Token Studios
#pragma once
#include <parcel.h>
#include <netinet/in.h>
#include <constants.h>

typedef struct {
    char token[16];
    struct sockaddr_in address;
    int *fd_tcp;
    int *fd_udp;
    bool active;

    pthread_t *critical_thread;

    Parcel *parcel;
} Client;

void delete_client(Client *client);

void *listen_critical(void *ptr);
