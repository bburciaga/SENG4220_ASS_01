/*
This server accept multi clients, and echo back each received message!
compile: g++ server.cpp -o server
run: ./server <port number> (which port number is between 1000 to 65535)

Author: Sina Keshvadi
*/
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <iostream>
#include <string.h> // memset
#include <unistd.h> // close
#include "Caesar.cpp"
#include "OTP.cpp"
#include "BruteForce.cpp"

using namespace std;

void show_message(int n, string message);
void handle_client(int tcp_socket);

int main(int argc, char const *argv[]) {
  if (argc != 2)
    show_message(-1, "usage: ./server <Port Number>");

  // Set server info
  addrinfo hints, *server_info;
  memset(&hints, 0, sizeof(addrinfo));

  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE; // use my IP
  getaddrinfo(NULL, argv[1], &hints, &server_info);

  // socket
  int server_socket = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);

  // bind
  bind(server_socket, server_info->ai_addr, server_info->ai_addrlen);

  // listen()
  listen(server_socket, 5);

  // if you want to show your server's host name
  /* char hostname[80];
  memset(hostname, 0, sizeof(hostname));
  gethostname(hostname, sizeof(hostname));
  cout << "Server on " << hostname <<"\nWaiting for connections ... \n";
  */
  cout << "Server: Waiting for connections ... \n";

  // accept()
  while (1) {
    if (!fork())
      handle_client(accept(server_socket, server_info->ai_addr, &server_info->ai_addrlen));
  }

  close(server_socket);

  return 0;
}

void show_message(int n, string message) {
  if (n < 0) {
    cout << message << endl;
    exit(EXIT_FAILURE);
  }
}

void handle_client(int tcp_socket) {
  int otpKey[80] = {
    2,7,5,2,0,4,0,0,0,7,
    7,2,6,4,0,1,0,2,4,2,
    1,6,5,4,4,7,0,0,5,7,
    2,6,0,5,3,2,3,6,1,7,
    0,4,5,6,1,6,3,6,6,3,
    1,7,7,0,7,2,0,0,5,1,
    2,1,0,6,0,7,6,6,0,1,
    0,1,2,7,1,1,7,2,4,7
  };
  char message[80];
  cout << "Client connected.\n";
  size_t recv_size;
  while (1) {
    memset(message, 0, sizeof(message));
    recv_size = recv(tcp_socket, &message, sizeof(message), 0);
    if (recv_size == 0)
        break;
    // Named cool message because it's just a random name
    string coolMessage(message);
    // CAESAR DECRYPTION
    //coolMessage = caesarDecryption(coolMessage, 6);
    // BRUTE FORCE DECRYPTION
    coolMessage = bruteForce(coolMessage);
    // OTP DECRYPTION
    //coolMessage = otpDecryption(coolMessage, otpKey);
    // Print decrypted message with Key
    // cout << "Client: " << coolMessage << "\nsize: " << recv_size << endl;
    // Print Brute Force decryptions
    cout << "Client: " << message << endl;
    cout << coolMessage << endl;
    send(tcp_socket, &message, sizeof(message), 0);
  }
  close(tcp_socket);
}
