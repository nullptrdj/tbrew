// (C) 2023 Token Studios
#pragma once
#include <constants.h>

#define LANG_LOG CMAG "Log " CWHT "| " CNRM

#define LANG_TCP_OPEN LANG_LOG "Safely opened " CBLU "TCP" CNRM " socket.\n"
#define LANG_UDP_OPEN LANG_LOG "Safely opened " CRED "UDP" CNRM " socket.\n"
#define LANG_LISTENING "\n" LANG_LOG CCYN "Finished steeping .𖥔 ݁ ˖ֶָ֢\n" LANG_LOG "Now listening for incoming connections...\n" CNRM

#define FLANG_TCP_BIND LANG_LOG "Safely binded to " CBLU "TCP" CNRM ":" CCYN "%hu" CNRM ".\n"
#define FLANG_UDP_BIND LANG_LOG "Safely binded to " CRED "UDP" CNRM ":" CCYN "%hu" CNRM ".\n"
#define FLANG_TCP_CONNECTION LANG_LOG "Accepted connection from " CBLU "%s" CNRM ":" CCYN "%hu" CNRM ".\n"

#define LANG_ERR_TCP_OPEN "Err | Failed to open the " CBLU "TCP" CNRM " socket.\n"
#define LANG_ERR_UDP_OPEN "Err | Failed to open the " CRED "UDP" CNRM " socket.\n"
#define LANG_ERR_TCP_LISTEN "Err | Failed to listen on the TCP socket.\n"

#define FLANG_ERR_TCP_BIND LANG_LOG "Failed to bind to " CGRN "TCP" CNRM ":" CYEL "%hu" CNRM ".\n"
#define FLANG_ERR_UDP_BIND LANG_LOG "Failed to bind to " CRED "UDP" CNRM ":" CYEL "%hu" CNRM ".\n"

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