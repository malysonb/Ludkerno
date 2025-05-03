#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <cstdint>
class Object
{
private:
    /* data */
public:
    std::string toString(){
        uintptr_t pointer = reinterpret_cast<uintptr_t>(this);
        std::stringstream name;
        name << typeid(*this).name() << "@" << "0x" << std::hex << pointer;
        return name.str();
    }
};
