//
// Created by alaa on 12/3/2019.
//

#ifndef TCPIMPLEMENTATION_SERVER_H
#define TCPIMPLEMENTATION_SERVER_H

#include <bits/stdc++.h>
#include <sys/socket.h>
#include <fcntl.h>
#include "Packet.h"

using namespace std;

class Server {
public:
    void init_server (int);
    void setParameters(int, float);

private:
    bool packet_corrupt(Packet);
    void acceptConnections (int);
    int seed;
    float plp;
};


#endif //TCPIMPLEMENTATION_SERVER_H
