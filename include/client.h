// (C) 2023 Token Studios
#pragma once
#include <netinet/in.h>

#include <constants.h>
#include <parcel.h>
#include <messages.h>

/** @brief Client Struct */
typedef struct {
    char sesid[37];
    struct sockaddr_in address;
    uint16_t fd;
    bool active;
    bool logged_in;

    pthread_t *critical_thread;

    Parcel *parcel;
} Client;

/**
 * \brief Send a message to a client
 * \param fd File descriptor of the client
 * \param message Message to send
 * \param size Size of the message
 * \param type Message type
 * \return Number of bytes sent
 */
ssize_t message_out(uint16_t fd, const char *message, uint16_t size, Messages type);

/**
 * \brief Delete a client
 * \param client Client to delete
 */
void delete_client(Client *client);

/**
 * \brief Listen for TCP Parcels
 * \param args Arguments pointer (Must be a pointer to a Client struct)
 */
void *listen_critical(void *args);