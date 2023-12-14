// (C) 2023 Token Studios
#pragma once
#include <stdint.h>

#include <vec.h>

/** @brief Arguments for the listen_udp pthread */
typedef struct {
    uint16_t *fd;
    Vec *clients;
} UArgs;

/**
 * \brief Listen for UDP Parcels
 * \param args Arguments pointer (Must be a pointer to a UArgs struct)
 */
void *listen_udp(void *args);