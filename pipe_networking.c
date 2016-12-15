#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int server_handshake(int *address) {

  int wkp = mkfifo("wkp", 0644);

  return 0;
  
}

int client_handshake(int *address) {

  int pid = getpid();
  int pvt_pipe = mkfifo(pid, 0644);
  
  return 0;
}

int main() {
 
}
