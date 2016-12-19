#ifndef PIPE_NETWORKING_H
#define PIPE_NETWORKING_H

#include "pipe_networking.c"

int server_handshake(int *address);

int client_handshake(int *address);

#endif
