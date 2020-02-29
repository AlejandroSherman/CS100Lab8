#ifndef __ABS_HPP__
#define __ABS_HPP__

#include "base.hpp"
#include "Decorator.hpp"


class Base;

class Abs : public Decorator {
    protected:
    public:
    Abs (Base* input) : Decorator() {value = input;}
    double evaluate(){return abs(value->evaluate());}
    std::string stringify(){};
};
    #endif
