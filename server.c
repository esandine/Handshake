#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "pipe_networking.h"


void process( char * s );

int main() {
  
  printf("[SERVER] Server started\n");
  
  int to_client, from_client;
  char buffer[512];

  
  to_client = server_handshake( &from_client );

  read( from_client, buffer, sizeof(buffer) );
  printf("[SERVER] Received from client: %s\n", buffer);
  process( buffer );
  write( to_client, buffer, sizeof(buffer));
  
  return 0;
}

void process( char * s ) {

  while ( *s ) {
    *s = (*s - 'a' + 13) % 26 + 'a';
    s++;
  }
}
