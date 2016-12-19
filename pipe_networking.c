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

  
  char pid_str[20];
  sprintf(pid_str, "%d", getpid());

  
  printf("%s\n", pid_str);
  int pvt_pipe = mkfifo(pid_str, 0644);
  
  return 0;
}

int main() {
  client_handshake(28034);
}
