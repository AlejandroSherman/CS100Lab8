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
    Base* get_left() {return value;}
    Base* get_right() {return nullptr;}
    Iterator* create_iterator() {
    return new UnaryIterator(this);
    }
};
    #endif
