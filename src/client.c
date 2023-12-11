// (C) 2023 Token Studios
#include <client.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Free a client and the pointers it refers to. Must be called for all clients!
void delete_client(Client *client) {
    free(client->parcel);
    pthread_cancel(*client->critical_thread);
    free(client);
}

// Listen for Parcel Messages (UDP)
void *listen_parcels(void *ptr) {
    printf("shit");
    Client *client = ptr;
    while (client->active) {
        char buffer[sizeof(Parcel)];

        if (recvfrom(*client->fd_udp, buffer, sizeof(buffer) - 1, 0, (struct sockaddr *)&client->address,
        (socklen_t*)sizeof(client->address)) != sizeof (Parcel)) {
            perror("Client sent corrupt parcel!");
            continue;
        }

        memcpy(client->parcel, buffer, sizeof(Parcel));
    }
    return nullptr;
}