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
        Object *o = this;
        unsigned int pointer = (intptr_t) &o;
        std::stringstream name;
        name << typeid(this).name() << "@" << std::to_string(pointer);
        return name.str();
    }
};
