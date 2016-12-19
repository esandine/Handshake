#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int server_handshake(int *from_client) {

  //Create wkp
  mkfifo("wkp", 0644);  
  printf("[SERVER] WKP Created\n");

  //Open wkp and wait for client to connect
  printf("[SERVER] Waiting for client...\n");
  int fd = open("wkp", O_RDONLY);
  *from_client = fd;

  //Read name of client's private pipe
  char client_id[32];
  read(fd, client_id, sizeof(client_id));
  printf("[SERVER] Client %s connected\n", client_id);

  //Remove wkp
  remove("wkp");

  //Connect to client's private pipe and write message
  int fd2 = open(client_id, O_RDONLY);
  write(fd2, "Connected to server", 20);

  return fd2;
}

int client_handshake(int *to_server) {

  //Convert PID to string
  char client_pid[32];
  sprintf(client_pid, "%d", getpid());

  //Make wkp with PID
  mkfifo(client_pid, 0644);
  printf("[CLIENT] Created private pipe\n");

  //Connect to server's wkp
  int fd = open("wkp", O_WRONLY);
  *to_server = fd;
  printf("[CLIENT] Connected to WKP\n");

  //Send PID to server
  write(fd, client_pid, sizeof(client_pid));
  
  int fd2 = open(client_pid, O_WRONLY);
  
  char server_message[128];
  read(fd2, server_message, sizeof(server_message));

  printf("[CLIENT] Received from server: %s\n", server_message);
  remove(client_pid);
  
  
  return fd2;
}


