//
// Created by alaa on 12/3/2019.
//

#include "Server.h"
#include "Packet.h"
#include "SelectiveRepeat.h"
#include <netinet/in.h>
#include <pthread.h>
#include <asm/ioctls.h>

void Server::init_server(int port) {
    //create socket
    int server_socket = socket(AF_INET, SOCK_DGRAM, 0);

    //handle error in socket creation
    if (server_socket == 0) {
        perror("failed to create socket");
        exit(EXIT_FAILURE);
        close(server_socket);
    }
    cout << "Server socket created successfully\n";

    //bind socket with addr
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr *)&server_addr,
             sizeof(server_addr)) < 0) {
        perror("failed to bind socket with addr and port specified");
        exit(EXIT_FAILURE);
        close(server_socket);
    }
    cout << "Server socket binded with port successfully\n";

    //accept connection
    acceptConnections(server_socket);
}
void Server::acceptConnections(int server_socket) {
    while(true) {
        struct sockaddr_in client_addr;
        memset(&client_addr, 0, sizeof(client_addr));

        Packet init_packet;
        socklen_t address_len = sizeof(client_addr);
        memset(&init_packet, 0, sizeof(init_packet));
        //first receive the file name -which will be sent from- client.
        int bytesReceived = recvfrom(server_socket, &init_packet, sizeof(init_packet),
                     MSG_WAITALL, ( struct sockaddr *) &client_addr, &address_len);
        if (bytesReceived <= 0 || packet_corrupt(init_packet)) {
            cout << "Packet received is incomplete\n";
            continue;
        }
//        pid_t child = fork();
//        cout << "Server received filename packet from client\n";
//        if (child < 0) {
//            perror("UDP Server: ERROR while forking new process.\n");
//        }
//        // check if the process ID is zero
//        if (child == 0) {
            string filename(init_packet.data, init_packet.len);
            cout << "Packet name is : " << filename.c_str() << "\n";
            //find file and it's size
            ifstream file(filename.c_str(), ifstream::ate | ifstream::binary);
            if (!file.is_open()) {
                cout << "Cannot open file\n";
                continue;
                //exit(1);
            }
            cout << "File opened successfully\n";
            long len = file.tellg();
            file.close();

            //divide file into packets
            int numberOfPackets = ceil(len * 1.0 / 500);
            cout << "File length is " <<  to_string(len) << "\n";
            cout << "Sending " <<  to_string(numberOfPackets) << " packets\n";

            //send ack for receiving file name
            Server_Ack_Packet server_ack_packet;
            server_ack_packet.packets_numbers = numberOfPackets;
            sendto(server_socket, &server_ack_packet, sizeof(server_ack_packet),
                   MSG_CONFIRM, (const struct sockaddr *) &client_addr,
                   sizeof(client_addr));
            cout << "Server sending filename ack to client\n";
            //start timer for calculating time of sending file
            auto start = std::chrono::high_resolution_clock::now();

            //start sending packets
            SelectiveRepeat selectiveRepeat(server_socket, seed, plp, numberOfPackets, filename, client_addr);
            selectiveRepeat.sendData();

            auto finish = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = finish-start;
            cout << "Time taken to send packet is " << diff.count() << "\n";
        //}
    }
    //close(server_socket);
}

void Server::setParameters(int seed, float plp) {
    this->seed = seed;
    this->plp = plp;
}
bool Server::packet_corrupt(Packet packet) {
    uint32_t sum = 0;
    for(int i = 0; i < packet.len; i++){
        sum += packet.data[i];
    }
    if (sum == 0) {
        //exit(0);
    }
    sum += packet.len;
    sum += packet.seqno;
    // Add the carries
    while (sum >> 16)
        sum = (sum & 0xFFFF) + (sum >> 16);
    if ((uint16_t)(~sum) != packet.cksum) {
        cout << "Packet is corrupt\n";
    }
    return (uint16_t)(~sum) != packet.cksum;
}