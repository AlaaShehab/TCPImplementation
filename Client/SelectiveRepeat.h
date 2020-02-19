//
// Created by alaa on 12/3/2019.
//

#ifndef TCPIMPLEMENTATION_SELECTIVEREPEAT_H
#define TCPIMPLEMENTATION_SELECTIVEREPEAT_H

#include <string>
#include <vector>
#include <limits.h>
#include <unistd.h>
#include <fstream>
#include <map>
#include <netinet/in.h>
#include "Packet.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

class SelectiveRepeat {

public:
    SelectiveRepeat(int, int, string, struct sockaddr_in);
    void receiveData();
private:
    int packetsToReceive;
    int client_socket;
    string filename;
    struct sockaddr_in server_addr;

    int window_base;
    int window_end;
    int cwnd = 100;
    map<int, Packet> data_received;

    bool packet_corrupt(Packet packet);
    uint16_t calculate_checksum(Ack_Packet);
};


#endif //TCPIMPLEMENTATION_SELECTIVEREPEAT_H
