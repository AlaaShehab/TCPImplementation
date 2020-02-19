//
// Created by alaa on 12/3/2019.
//

#ifndef TCPIMPLEMENTATION_CLIENT_H
#define TCPIMPLEMENTATION_CLIENT_H

#include <netinet/in.h>
#include <bits/stdc++.h>
#include <sys/socket.h>
#include <string>
#include <vector>
#include <limits.h>
#include <unistd.h>
#include <fstream>
#include "Packet.h"

using namespace std;

class Client {
public:
    void init_client (int, string);

private:
    uint16_t calculate_checksum(Packet);

};


#endif //TCPIMPLEMENTATION_CLIENT_H
