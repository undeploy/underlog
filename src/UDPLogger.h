//
// Created by Henrique on 10/12/2018.
//

#ifndef UNDERLOG_UDPLOGGER_H
#define UNDERLOG_UDPLOGGER_H

#include "Logger.h"
#include "Print.h"
#include "ESPAsyncUDP.h"


class UDPLogger {

private:
    IPAddress ipAddress;
    uint16_t port;
    AsyncUDP *udp;

public:
    UDPLogger::UDPLogger(IPAddress &ipAddress, uint16_t port, Level level);

    template<typename... Any>
    void debug(const char *message, Any... args);

    void debug(const char *message);

    template<typename... Any>
    void info(const char *message, Any... args);

    void info(const char *message);

    template<typename... Any>
    void warning(const char *message, Any... args);

    void warning(const char *message);

    template<typename... Any>
    void error(const char *message, Any... args);

    void error(const char *message);

    Level getLevel();

    void setLevel(Level level);

    void checkConnection();
};

#endif //UNDERLOG_UDPLOGGER_H
