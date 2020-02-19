//
// Created by alaa on 12/10/19.
//
#include <iostream>
#include "Server.h"

int main(int argc, char* argv[]) {
    Server server;
    server.setParameters(atoi(argv[2]), atof(argv[3]));
    server.init_server(atoi(argv[1]));
    return 0;
}