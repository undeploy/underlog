#include "Logger.h"
#include "Arduino.h"

Logger::Logger(Print *printer, Level level) {
    this->printer = printer;
    this->level = level;
}

void Logger::log(const char *message) {
    Serial.println(message);
}

template<typename T, typename... Any>
void Logger::log(const char *message, T value, Any... arguments) // recursive variadic function
{
    for (int i = 0; *message != '\0'; message++) {
        if (*message == '{' && (message[i + 1]) == '}') {
            Serial.print(value);
            log(message + 2, arguments...); // recursive call
            return;
        }
        Serial.print(*message);
    }
}

template<typename... Any>
void Logger::debug(const char *message, Any... arguments) {
    this->log(message, arguments...);
};

void Logger::debug(const char *message) {
    this->log(message);
};

template<typename... Any>
void Logger::info(const char *message, Any... arguments) {
    this->log(message, arguments...);
};

void Logger::info(const char *message) {
    this->log(message);
};

template<typename... Any>
void Logger::warning(const char *message, Any... arguments) {
    this->log(message, arguments...);
};

void Logger::warning(const char *message) {
    this->log(message);
};

template<typename... Any>
void Logger::error(const char *message, Any... arguments) {
    this->log(message, arguments...);
};

void Logger::error(const char *message) {
    this->log(message);
};
