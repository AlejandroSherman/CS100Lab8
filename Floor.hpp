#ifndef __FLOOR_HPP__
#define __FLOOR_HPP__

#include "base.hpp"
#include "Decorator.hpp"


class Base;

class Floor : public Decorator {
    protected:
    public:
    Floor (Base* input) : Decorator() {value = input;}
    double evaluate(){return floor(value->evaluate());}
    std::string stringify(){};
};
    #endif
