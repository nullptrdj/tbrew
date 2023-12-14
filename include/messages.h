// (C) 2023 Token Studios
#pragma once

/** @brief Message types */
typedef enum {
    m_login,
    m_reject,
    m_uuid,
} Messages;

#pragma pack(1)
/** @brief Login Packet */
typedef struct {
    char username[11];
} Login;
#pragma pack(0)