cmake_minimum_required(VERSION 3.13)
project(TCPImplementation)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(TCPImplementation main.cpp Server/Server.cpp Server/Server.h Server/Packet.h Server/SelectiveRepeat.cpp Server/SelectiveRepeat.h Client/Client.cpp Client/Client.h Client/Packet.h Client/SelectiveRepeat.cpp Client/SelectiveRepeat.h Client/main.cpp Server/main.cpp)