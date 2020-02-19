//
// Created by alaa on 12/3/2019.
//

#include <iterator>
#include "SelectiveRepeat.h"

SelectiveRepeat::SelectiveRepeat(int server_socket, int seed, float plp, int number_of_packets,
                            string filename, struct sockaddr_in client_addr) {
    this->server_socket = server_socket;
    this->seed = seed;
    this->plp = plp;
    this->number_of_packets = number_of_packets;
    this->filename = filename;
    this->client_addr = client_addr;

    cwnd = 1;
    window_base = 0;
    window_end = window_base;
    mss = 1;
    ssthresh = 400;
    dupAck = 0;

    window_packets.clear();
    acked_packets.clear();

    fill_lost_packets();
    file_op();

}

void SelectiveRepeat::fill_lost_packets() {
    int number_of_lost_packets = ceil(plp * number_of_packets);
    cout << "Number of loss packets is " << number_of_lost_packets << "\n";
    srand(seed);
    for (int i = 0; i < number_of_lost_packets; i++) {
        //pick a random number (packet which will not be sent)
        int packet_number = rand() % number_of_packets;
        //if packet already chosen then pick another one
        if (lost_packets.count(packet_number) == 0) {
            lost_packets.insert(packet_number);
        } else { //else add packet number to the set of lost packets
            i--;
        }
    }
}

void SelectiveRepeat::sendData() {
    start = clock();
    cwnd_for_analysis.push_back(cwnd);
    time_for_analysis.push_back((clock() - start) / (CLOCKS_PER_SEC/1000));
    thread1 = std::thread (&SelectiveRepeat::send_data, this);
    thread2  = std::thread (&SelectiveRepeat::receive_ack, this);
    thread1.join();
    thread2.join();
}

void SelectiveRepeat::send_data() {
    cout << "Sending data to client\n";
    while (window_base < number_of_packets) {
        //update window
        while(window_base <= window_end && acked_packets.find(window_base) != acked_packets.end()){
            window_base++;
        }
        window_end = min((int)floor(window_base + cwnd - 1), number_of_packets - 1);
        //loop on the current window to either send packet or check for timeout.
        for (int i = window_base; i <= window_end; i++) {
            //if current packet in cnwd is not sent then send it
            if (window_packets.find(i) == window_packets.end()
                && acked_packets.find(i) == acked_packets.end()) {
                Packet packet = get_data_from_file(i);
                //this is a lost package i.e. it won't be sent
                if (lost_packets.count(i)) {
                    cout << "Packet " << i << " is lost\n";
                    lost_packets.erase(i);
                    clock_t start = clock() / CLOCKS_PER_SEC;
                    window_packets[i] = {packet, start};
                } else { //send packet
                    sendto(server_socket, &packet, sizeof(packet),
                           MSG_CONFIRM, (const struct sockaddr *) &client_addr,
                           sizeof(client_addr));
                    double start = clock() / CLOCKS_PER_SEC;
                    window_packets.erase(i);
                    window_packets[i] = {packet, start};
                    cout << "Sending packet " << i << "\n";
                }
            }
            if(window_packets.find(i) != window_packets.end() &&
                acked_packets.find(i) == acked_packets.end()){
                double current = clock() / CLOCKS_PER_SEC;
                if((current - window_packets[i].second) > 1){
                    cout << "timeout for packet " << i <<"\n";
                    cout << "Will resend packet " << window_base << "\n";
                    window_packets.clear();
                    ssthresh = ceil(cwnd/2);
                    cwnd = 1;
                    //update window
                    while(window_base <= window_end && acked_packets.find(window_base) != acked_packets.end()){
                        window_base++;
                    }
                    window_base = window_base;
                    window_end = window_base;
                    break;
                }
            }
        }
    }
    //printing analysis data to file
    ofstream cwnd_file;
    cwnd_file.open("cwnd.txt");
    ofstream time_file;
    time_file.open("time.txt");
    for (int i=0; i<cwnd_for_analysis.size(); i++)
    {
        cwnd_file << cwnd_for_analysis[i] << '\n';
        time_file << time_for_analysis[i] << '\n';
    }

    cwnd_file.close();
    time_file.close();
}

void SelectiveRepeat::receive_ack() {

    while (window_base < number_of_packets) {
        bool no_ack_received = true;
        Ack_Packet ack_packet;
        clock_t begin = clock();
        //Make server socket non blocking
//        int flags = fcntl(server_socket, F_GETFL);
//        fcntl(server_socket, F_SETFL, flags | O_NONBLOCK);

        //Receive packet
        while((clock() - begin) < 1){
            socklen_t addresslen = sizeof(client_addr);
            int bytes = recvfrom(server_socket, &ack_packet, sizeof(ack_packet),
                                 0, (struct sockaddr*)&client_addr, &addresslen);
            if(bytes > 0){
                cout << "Ack received for packet " << ack_packet.ackno << "\n";
                no_ack_received = false;
                break;
            }
        }
        if (no_ack_received) {
            continue;
        }
        //ack is not corrupt and the acked packet is indeed sent
        if(!ack_corrupt(ack_packet)
            && window_packets.find(ack_packet.ackno) != window_packets.end()){
            acked_packets[ack_packet.ackno] = ack_packet;
            //update window
            while(window_base <= window_end && acked_packets.find(window_base) != acked_packets.end()){
                window_base++;
            }
            //update congestion window
            if(cwnd < ssthresh){
                cwnd += 1;
            }else if(cwnd < number_of_packets){
                cwnd += (1/floor(cwnd));
            }
            cwnd_for_analysis.push_back(cwnd);
            time_for_analysis.push_back((clock() - start) / (CLOCKS_PER_SEC/1000));
            window_end = min((int)floor(window_base + cwnd - 1), number_of_packets - 1);
        }
    }

}
bool SelectiveRepeat::ack_corrupt(Ack_Packet ack) {
    uint32_t sum = 0;
    sum += ack.len;
    sum += ack.ackno;
    // Add the carries
    while (sum >> 16)
        sum = (sum & 0xFFFF) + (sum >> 16);
    if ((uint16_t)(~sum) != ack.cksum) {
        cout << "Ack  is corrupt\n";
    }
    return (uint16_t)(~sum) != ack.cksum;
}

Packet SelectiveRepeat::get_data_from_file(int i) {
    //get either 500 or the remaining size if not a factor of 500
    int size = min(500, file_size - (i*500));

    //buffer to keep data
    char * buffer = (char*) malloc(size);
    int bytes;
    fseek(file, i * 500, SEEK_SET);
    bytes = fread (buffer, sizeof(char), size, file);

    Packet packet;
    packet.len = bytes;
    for(int i = 0 ;i < bytes; i++){
        packet.data[i] = buffer[i];
    }
    packet.seqno = i;
    packet.cksum = calculate_checksum(packet);

    return packet;
}

void SelectiveRepeat::file_op() {
    file = fopen(filename.c_str(), "rb");
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);
}
uint16_t SelectiveRepeat::calculate_checksum(Packet packet) {
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