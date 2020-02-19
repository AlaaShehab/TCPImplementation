//
// Created by alaa on 12/3/2019.
//

#ifndef TCPIMPLEMENTATION_PACKET_H
#define TCPIMPLEMENTATION_PACKET_H


#include <stdint-gcc.h>

struct Packet {
    /* Header */
    uint16_t cksum;
    uint16_t len;
    uint32_t seqno;
    /* Data */
    char data[500]; /* Not always 500 bytes, can be less */
};

struct Ack_Packet {
    uint16_t cksum; /* Optional bonus part */
    uint16_t len;
    uint32_t ackno;
};

struct Server_Ack_Packet {
    uint32_t packets_numbers;
};

#endif //TCPIMPLEMENTATION_PACKET_H
