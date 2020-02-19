//
// Created by alaa on 12/10/19.
//

#include <iostream>
#include "Client.h"

int main(int argc, char* argv[]) {
    Client client;
    client.init_client(atoi(argv[1]), argv[2]);
    return 0;
}