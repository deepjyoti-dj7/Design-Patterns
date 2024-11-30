#include <iostream>
#include <mutex>
#include "../include/Logger.hpp"

int Logger::counter = 0;
Logger* Logger::loggerInstance = nullptr;
std::mutex Logger::mtx;

Logger::Logger() {
    counter++;
    std::cout << "Instance created, no of instance: " << counter << std::endl;
}

void Logger::Log(std::string message) {
    std::cout << message << std::endl;
}

Logger* Logger::getLogger() {
    if (loggerInstance == nullptr) {
        mtx.lock();
        if (loggerInstance == nullptr) {
            loggerInstance = new Logger();
        }
        mtx.unlock();
    }
    return loggerInstance;
}