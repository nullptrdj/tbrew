// (C) 2023 Token Studios
#pragma once
#include <stdint.h>

/** @brief True Boolean Macro */
#define true 1
/** @brief False Boolean Macro */
#define false 0
/** @brief Poor Man's Bool */
#define bool uint8_t

/** @brief Normal Color Macro */
#define CNRM  "\x1B[0m"
/** @brief Red Color Macro */
#define CRED  "\x1B[31m"
/** @brief Green Color Macro */
#define CGRN  "\x1B[32m"
/** @brief Yellow Color Macro */
#define CYEL  "\x1B[33m"
/** @brief Blue Color Macro */
#define CBLU  "\x1B[34m"
/** @brief Magenta Color Macro */
#define CMAG  "\x1B[35m"
/** @brief Cyan Color Macro */
#define CCYN  "\x1B[36m"
/** @brief White Color Macro */
#define CWHT  "\x1B[37m"

/** @brief Default TCP Port */
#define TCP_PORT 6342
/** @brief Default UDP Port */
#define UDP_PORT 8463