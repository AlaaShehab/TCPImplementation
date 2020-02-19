//
// Created by alaa on 12/3/2019.
//

#include "SelectiveRepeat.h"

SelectiveRepeat::SelectiveRepeat(int client_socket,
        int packetsToReceive, string filename, struct sockaddr_in server_addr) {
    this->packetsToReceive = packetsToReceive;
    this->client_socket = client_socket;
    this->filename = filename;
    this->server_addr = server_addr;

    window_base = 0;
    window_end = min(packetsToReceive - 1, cwnd - 1);
    data_received.clear();
}

void SelectiveRepeat::receiveData() {
    cout << "Start to receive data\n";
    //loop until all packets are received
    while (window_base < packetsToReceive) {
        //receive packet
        Packet packet;
        memset(&packet, 0, sizeof(packet));
        socklen_t addrlen = sizeof(server_addr);
        int bytesReceived = recvfrom(client_socket, &packet,
                                     sizeof(packet), MSG_WAITALL,
                                     (struct sockaddr *) &server_addr, &addrlen);
        cout << "Client received a packet with seqno " << packet.seqno << "\n";
        if (bytesReceived <= 0) {
            perror("Packet not received");
        }
        if (packet.seqno < window_base || packet.seqno > window_end) {
            cout << "Packet is not in the current window\n";
            //update window
            while (window_base < packetsToReceive && data_received.find(window_base) != data_received.end()) {
                window_base++;
            }
            window_end = min(packetsToReceive - 1, window_base + cwnd - 1);
        }
        if (data_received.find(packet.seqno) != data_received.end()) {
            cout << "Packet is already received\n";
        }
        //if new packet is received and not corrupt and within window
        if (!packet_corrupt(packet) && packet.seqno >= window_base && packet.seqno <= window_end
            && data_received.find(packet.seqno) == data_received.end()) {
            //put packet in buffer
            data_received[packet.seqno] = packet;
            cout << "Packet " << packet.seqno << " received successfully\n";

            //create ack
            Ack_Packet ack_packet;
            ack_packet.ackno = packet.seqno;
            ack_packet.len = sizeof(packet.seqno);
            ack_packet.cksum = calculate_checksum(ack_packet);

            //send ack
            sendto(client_socket, &ack_packet, sizeof(ack_packet),
                   MSG_CONFIRM, (const struct sockaddr *) &server_addr,
                   sizeof(server_addr));
            cout << "Sending packet ack to server\n";

            //update window
            while (window_base < packetsToReceive && data_received.find(window_base) != data_received.end()) {
                window_base++;
            }
            window_end = min(packetsToReceive - 1, window_base + cwnd - 1);
        }
        if (!packet_corrupt(packet) && (packet.seqno >= window_base || packet.seqno < window_base)
            && data_received.find(packet.seqno) != data_received.end()) {
            //create ack
            Ack_Packet ack_packet;
            ack_packet.ackno = packet.seqno;
            ack_packet.len = sizeof(packet.seqno);
            ack_packet.cksum = calculate_checksum(ack_packet);

            //send ack
            sendto(client_socket, &ack_packet, sizeof(ack_packet),
                   MSG_CONFIRM, (const struct sockaddr *) &server_addr,
                   sizeof(server_addr));
            cout << "Sending repeated packet ack to server\n";
        }
    }
    cout << "File received successfully\n";
    //write data to file
    FILE *file = fopen(filename.c_str(), "wb");
    int current = 0;
    while (current < packetsToReceive) {
        Packet packet = data_received[current];
        string data = string(packet.data, packet.len);
        fwrite(data.c_str(), sizeof(char), data.size(), file);
        current++;
    }
    fclose(file);
}

bool SelectiveRepeat::packet_corrupt(Packet packet) {
    uint32_t sum = 0;
    for(int i = 0; i < packet.len; i++){
        sum += packet.data[i];
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
uint16_t SelectiveRepeat::calculate_checksum(Ack_Packet packet) {
    uint32_t sum = 0;
    sum += packet.len;
    sum += packet.ackno;
    // Add the carries
    while (sum >> 16)
        sum = (sum & 0xFFFF) + (sum >> 16);
    // Return the one's complement of sum
    return ( (uint16_t)(~sum)  );
}