#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "pipe_networking.h"

int client_handshake(int *address) {

  char pid_str[20];
  sprintf(pid_str, "%d", getpid());
  int pvt_pipe = mkfifo(pid_str, 0644);
  int wkp = open("wkp",O_WRONLY);
  write(wkp,pid_str,20);
  char buf[20];
  pvt_pipe = open(pid_str, O_RDONLY);
  read(pvt_pipe, buf, 20);
  if(!strcmp(buf, "Secret Message")){
    remove(pid_str);
    printf("Connection established");
  }else{
    printf("Connection failed");
  }
  return 0;
}

int main() {

  int to_server, from_server;

  from_server = client_handshake( &to_server );
  
  char buffer[512];
  printf("enter message: ");
  fgets( buffer, sizeof(buffer), stdin );
  char *p = strchr(buffer, '\n');
  *p = 0;
  
  write( to_server, buffer, sizeof(buffer) );
  read( from_server, buffer, sizeof(buffer) );
  printf( "received: %s\n", buffer );
  
  return 0;
}
