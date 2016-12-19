#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int server_handshake(int *address) {

  int wkp = mkfifo("wkp", 0644);
  wkp = open("wkp",O_RDONLY);
  return 0;
  
}

int client_handshake(int *address) {
  
  char pid_str[20];
  sprintf(pid_str, "%d", getpid());
  int pvt_pipe = mkfifo(pid_str, 0644);
  int wkp = open("wkp",O_WRONLY);
  return 0;
}

int main() {
  int address = 28034;
  client_handshake(&address);
}
