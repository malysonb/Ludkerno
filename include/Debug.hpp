#pragma once
#include <iostream>
#define IN_DEBUG 1

class Debug
{
    int logLevel = INFO;
    public:
    enum Level{
        INFO, WARN, ERROR
    };
    static void log(const char*, Level level);
    template <typename T>
    static void log(T message, Level level);
};