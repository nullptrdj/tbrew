// (C) 2023 Token Studios
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <uuid/uuid.h>

#include <client.h>
#include <string.h>

void delete_client(Client *client) {
    free(client->parcel);
    pthread_cancel(*client->critical_thread);
    free(client);
}

void *listen_critical(void *args) {
    Client *client = args;

    // Login Packet
    char buffer[sizeof(Login)];
    const uint8_t len = recv(client->fd, buffer, sizeof(buffer), 0);
    if (len != sizeof(Login)) {
        perror("Client sent corrupt login");
        return 0;
    }

    // Gen UUID
    uuid_t uuid;
    uuid_generate_random(uuid);
    uuid_unparse(uuid, client->sesid);

    // Notify the client of its new UUID
    message_out(client->fd, client->sesid, 37, m_uuid);
    client->logged_in = true;

    return 0;
}

ssize_t message_out(const uint16_t fd, const char *message, const uint16_t size, const Messages type) {
    char buf[size+1];
    buf[0] = (char)type;
    memcpy(buf+1, message, size);
    return send(fd, buf, sizeof(buf), 0);
}