/*
This client send messages to a server. That's it.
compile: g++ client.cpp -o client
run: ./client <server IP> <server port>

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
#include <cstdlib>
#include <string>
#include <cstring>
#include "Caesar.cpp"
#include "OTP.cpp"

using namespace std;


int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        cout << "usage: "<< argv[0] << " <Server IP> <Port Number>\n";
        return (EXIT_FAILURE);
    }

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

    // Set destination info
    addrinfo hints, *server_info;
    memset(&hints, 0, sizeof(addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    // get server info
    getaddrinfo(argv[1], argv[2], &hints, &server_info);

    int client_socket = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);

    connect(client_socket, server_info->ai_addr, server_info->ai_addrlen);

    string msg;
    char message[80];
    memset(message, 0, sizeof(message));
    while (1)
    {
        // inputing values into msg
        getline(cin, msg, '\n');
        // We have msg from client
        // CONVERT STRING WITH CAESAR CIPHER
        msg = caesarEncryption(msg, 6);
        // CONVERT STRING WITH OTP CIPHER
        // msg = otpEncryption(msg, otpKey);
        strcpy(message, msg.c_str());
        // send message to the server assumption
        send(client_socket, &message, (size_t)strlen(message), 0);
        memset(message, 0, sizeof(message));
        // server received message assumption
        recv(client_socket, &message, sizeof(message), 0);
        cout << "Server: " << message << endl;
        memset(message, 0, sizeof(message));
    }

    return 0;
}
