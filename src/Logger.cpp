#include "Logger.h"

Logger::Logger(Print *printer, Level level) {
    this->printer = printer;
    this->level = level;
}

void Logger::log(const char *message) {
    this->printer->println(message);
}

template<typename T, typename... Any>
void Logger::log(const char *message, T value, Any... arguments) // recursive variadic function
{
    while(*message != '\0') {
        if (message[0] == '{' && (message[1]) == '}') {
            this->printer->print(value);
            log(message + 2, arguments...); // recursive call
            return;
        }
        this->printer->print(*message);
        message++;
    }
    this->printer->println();
}

template<typename... Any>
void Logger::debug(const char *message, Any... arguments) {
    if(this->level >= DEBUG) {
        this->log(message, arguments...);
    }
};

void Logger::debug(const char *message) {
    this->debug(message, '\0');
};

template<typename... Any>
void Logger::info(const char *message, Any... arguments) {
    if(this->level >= INFO) {
        this->log(message, arguments...);
    }
};

void Logger::info(const char *message) {
    this->info(message, '\0');
};

template<typename... Any>
void Logger::warning(const char *message, Any... arguments) {
    if(this->level >= WARNING) {
        this->log(message, arguments...);
    }
};

void Logger::warning(const char *message) {
    this->warning(message, '\0');
};

template<typename... Any>
void Logger::error(const char *message, Any... arguments) {
    if(this->level >= ERROR) {
        this->log(message, arguments...);
    }
};

void Logger::error(const char *message) {
    this->error(message, '\0');
};