//
// Created by Henrique on 9/23/2018.
//

#ifndef UNDERLOG_LOGGER_H
#define UNDERLOG_LOGGER_H

#include <Print.h>
#include "Arduino.h"

enum Level{DEBUG=3, INFO=2, WARNING=1, ERROR=0};

class Logger {

private:
    template<typename T, typename... Any>
    void log(const char* message, T value, Any... arguments);
    void log(const char *message);

    Print *printer;
    Level level;
public:
    Logger(Print *printer, Level level);

    template<typename... Any>
    void debug(const char* message, Any... args);
    void debug(const char* message);

    template<typename... Any>
    void info(const char* message, Any... args);
    void info(const char* message);

    template<typename... Any>
    void warning(const char* message, Any... args);
    void warning(const char* message);

    template<typename... Any>
    void error(const char* message, Any... args);
    void error(const char* message);

    Level getLevel();
    void setLevel(Level level);
};

#endif //UNDERLOG_LOGGER_H
