#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "pipe_networking.h"


int main() {
  printf("[CLIENT] Client started\n");
   int to_server, from_server;

   
  from_server = client_handshake( &to_server );

  
  char buffer[512];
  printf("Enter message: ");
  fgets( buffer, sizeof(buffer), stdin );
  char *p = strchr(buffer, '\n');
  *p = 0;
  
  write( to_server, buffer, sizeof(buffer) );
  read( from_server, buffer, sizeof(buffer) );
  printf("[CLIENT] Response received: %s\n", buffer );

  
  return 0;
}
