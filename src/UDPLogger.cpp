//
// Created by Henrique on 10/12/2018.
//

#include "UDPLogger.h"

Logger* logger;

UDPLogger::UDPLogger(IPAddress &ipAddress, uint16_t port, Level level) {
    this->ipAddress = ipAddress;
    this->port = port;
    udp->connect(this->ipAddress, this->port);
    logger = new Logger(this->udp, level);
}

template<typename... Any>
void UDPLogger::debug(const char* message, Any... args){
    this->checkConnection();
    logger->debug(message, args);
}

void UDPLogger::debug(const char* message){
    this->checkConnection();
    logger->debug(message);
}

template<typename... Any>
void UDPLogger::info(const char* message, Any... args){
    this->checkConnection();
    logger->info(message, args);
}
void UDPLogger::info(const char* message){
    this->checkConnection();
    logger->info(message);
}

template<typename... Any>
void UDPLogger::warning(const char* message, Any... args){
    this->checkConnection();
    logger->warning(message, args);
}
void UDPLogger::warning(const char* message){
    this->checkConnection();
    logger->warning(message);
}

template<typename... Any>
void UDPLogger::error(const char* message, Any... args){
    this->checkConnection();
    logger->error(message, args);
}
void UDPLogger::error(const char* message){
    this->checkConnection();
    logger->error(message);
}

Level UDPLogger::getLevel(){
    return logger->getLevel();
}

void UDPLogger::setLevel(Level level){
    logger->setLevel(level);
}

void UDPLogger::checkConnection() {
    if(!this->udp->connected()){
        udp->connect(this->ipAddress, this->port);
    }
}
