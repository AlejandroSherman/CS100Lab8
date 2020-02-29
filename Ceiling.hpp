#ifndef __CEILING_HPP__
#define __CEILING_HPP__

#include "base.hpp"
#include "Decorator.hpp"


class Base;

class Ceil : public Decorator {
    protected:
    public:
    Ceil (Base* input) : Decorator() {value = input;}
    double evaluate(){return ceil(value->evaluate());}
    std::string stringify(){};
    Base* get_left() {return value;}
    Base* get_right() {return nullptr;}
    Iterator* create_iterator() {
    return new UnaryIterator(this);
    }
};
    #endif
