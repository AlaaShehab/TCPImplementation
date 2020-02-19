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
#include <ctime>
#include <cmath>
#include <set>
#include <thread>
#include <mutex>
#include <netinet/in.h>
#include "Packet.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <iostream>
#include <vector>
#include <iterator>


using namespace std;

class SelectiveRepeat {
public:
    SelectiveRepeat(int server_socket, int seed, float plp, int number_of_packets, string filename, struct sockaddr_in client_addr);
    void sendData();

private:
    int server_socket;
    int seed;
    float plp;
    string filename;
    int number_of_packets;
    struct sockaddr_in client_addr;

    double cwnd;
    int window_base;
    int window_end;
    int mss;
    int ssthresh;
    int dupAck;
    int file_size;
    FILE * file;

    thread thread1;
    thread thread2;

    map<int, pair<Packet, double >> window_packets;
    map<int, Ack_Packet> acked_packets;
    set<int> lost_packets;

    void fill_lost_packets();
    void send_data();
    void receive_ack();
    bool ack_corrupt(Ack_Packet);
    uint16_t calculate_checksum(Packet);

    Packet get_data_from_file(int i);

    void file_op();
    mutex mtx;

    vector<double> cwnd_for_analysis;
    vector<double> time_for_analysis;
    clock_t start;
};


#endif //TCPIMPLEMENTATION_SELECTIVEREPEAT_H
