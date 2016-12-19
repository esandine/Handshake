#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "pipe_networking.h"

int server_handshake(int *address) {

  int wkp = mkfifo("wkp", 0644);
  wkp = open("wkp",O_RDONLY);
  char buf[20];
  read(wkp, buf, 20);
  remove("wkp");
  int pvt_pipe = open(buf, O_WRONLY);
  char message[20];
  strcpy(message, "Secret Message");
  write(pvt_pipe, message, 20);
  printf("Buf: %s\n", buf);
  return 0;

}

void process( char * s );

int main() {

  int to_client, from_client;
  char buffer[512];
  
  to_client = server_handshake( &from_client );

  read( from_client, buffer, sizeof(buffer) );
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
