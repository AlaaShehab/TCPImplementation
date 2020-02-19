//
// Created by alaa on 12/3/2019.
//

#include "Client.h"
#include "Packet.h"
#include "SelectiveRepeat.h"

void Client::init_client (int port, string filename) {
    struct sockaddr_in server_addr;
    int client_socket;

    memset(&client_socket, '0', sizeof(client_socket));

    //create socket
    if ((client_socket = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("failed to create socket");
        exit(EXIT_FAILURE);
    }
    cout << "client socket created successfully\n";

    //clear the address
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    //create a packet with filename
    Packet packet;
    memset(&packet, 0, sizeof(packet));
    string fname = strdup(filename.c_str());
    cout << "file name is " << fname << "and file size is " << fname.size() << "\n";
    strcpy(packet.data, fname.c_str());
    packet.len = fname.size();
    packet.seqno = 0;
    packet.cksum = calculate_checksum(packet);

    //send packet to server
    sendto(client_socket, &packet, sizeof(packet),
           MSG_CONFIRM, (const struct sockaddr *) &server_addr,
           sizeof(server_addr));

    cout << "client sent file name to server\n";

    //wait for ack from server
    socklen_t addrlen = sizeof(server_addr);
    Server_Ack_Packet server_ack_packet;
    int bytesReceived = recvfrom(client_socket, &server_ack_packet,
            sizeof(server_ack_packet), MSG_WAITALL,
            (struct sockaddr *) &server_addr, &addrlen);
    cout << "client received filename packet ack from server\n";
    if (bytesReceived <= 0) {
        perror("Server ack is not completely received");
    }

    auto start = std::chrono::high_resolution_clock::now();
    //receive file packets from server
    SelectiveRepeat selectiveRepeat(client_socket, server_ack_packet.packets_numbers,
            filename, server_addr);
    selectiveRepeat.receiveData();

    //TODO calculate time it took to receive data from server
    auto finish = std::chrono::high_resolution_clock::now();
    close(client_socket);
}

uint16_t Client::calculate_checksum(Packet packet) {
    uint32_t sum = 0;
    for(int i = 0; i < packet.len; i++){
        sum += packet.data[i];
    }
    sum += packet.len;
    sum += packet.seqno;
    // Add the carries
    while (sum >> 16)
        sum = (sum & 0xFFFF) + (sum >> 16);
    // Return the one's complement of sum
    return ( (uint16_t)(~sum)  );
}
