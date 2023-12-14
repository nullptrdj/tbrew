// (C) 2023 Token Studios
#pragma once
#include <constants.h>

/** @brief Log Prefix Macro */
#define LANG_LOG CMAG "Log " CWHT "| " CNRM
/** @brief Error Prefix Macro */
#define LANG_ERR CRED "Err " CWHT "| " CNRM

/** @brief TCP Open Log */
#define LANG_TCP_OPEN LANG_LOG "Safely opened " CBLU "TCP" CNRM " socket.\n"
/** @brief UDP Open Log */
#define LANG_UDP_OPEN LANG_LOG "Safely opened " CRED "UDP" CNRM " socket.\n"
/** @brief TCP Listen Log */
#define LANG_LISTENING "\n" LANG_LOG CCYN "Finished steeping .𖥔 ݁ ˖ֶָ֢\n" LANG_LOG "Now listening for incoming connections...\n" CNRM

/** @brief TCP Bind Log */
#define FLANG_TCP_BIND LANG_LOG "Safely binded to " CBLU "TCP" CNRM ":" CCYN "%hu" CNRM ".\n"
/** @brief UDP Bind Log */
#define FLANG_UDP_BIND LANG_LOG "Safely binded to " CRED "UDP" CNRM ":" CCYN "%hu" CNRM ".\n"
/** @brief TCP Connection Log */
#define FLANG_TCP_CONNECTION LANG_LOG "Accepted connection from " CBLU "%s" CNRM ":" CCYN "%hu" CNRM ".\n"

/** @brief TCP Open Error */
#define LANG_ERR_TCP_OPEN LANG_ERR "Failed to open the " CBLU "TCP" CNRM " socket.\n"
/** @brief UDP Open Error */
#define LANG_ERR_UDP_OPEN LANG_ERR "Failed to open the " CRED "UDP" CNRM " socket.\n"
/** @brief TCP Listen Error */
#define LANG_ERR_TCP_LISTEN LANG_ERR "Failed to listen on the TCP socket.\n"
/** @brief UDP Accept Error */
#define LANG_ERR_UDP_CORRUPT LANG_ERR "Received corrupt " CRED "UDP" CNRM " packet.\n"

/** @brief TCP Bind Error */
#define FLANG_ERR_TCP_BIND LANG_ERR "Failed to bind to " CGRN "TCP" CNRM ":" CYEL "%hu" CNRM ".\n"
/** @brief UDP Bind Error */
#define FLANG_ERR_UDP_BIND LANG_ERR "Failed to bind to " CRED "UDP" CNRM ":" CYEL "%hu" CNRM ".\n"

/** @brief Tbrew Logo */
#define LANG_LOGO CWHT "\
)  ( \n\
(   ) ) \n\
) ( ( " CWHT "\n\
_________ \n\
.-'" CCYN "---------" CWHT "|                        ╱|、\n\
( C|" CCYN "/\\/\\/\\/\\/" CWHT "|  " CMAG "⊹ tbrew v0.0.1 ⊹" CWHT "   (˚ˎ。7\n\
'-." CCYN "/\\/\\/\\/\\/" CWHT "|      " CMAG "nullptrdj" CWHT "        |、˜〵  |\n\
'" CCYN "_________" CWHT "'                       じしˍ,)ノ\n\
'-------' \n\
"