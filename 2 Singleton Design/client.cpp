#include <iostream>
#include <thread>
#include "./include/Logger.hpp"

void user1Logs() {
    Logger *logger1 = Logger::getLogger();
    logger1->Log("This message is from client1");
}

void user2Logs() {
    Logger *logger2 = Logger::getLogger();
    logger2->Log("This message is from client2"); 
}

int main() {
    std::thread t1(user1Logs);
    std::thread t2(user2Logs);

    t1.join();
    t2.join();

    return 0;
}