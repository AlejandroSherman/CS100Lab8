#ifndef __TRUNCATE_HPP__
#define __TRUNCATE_HPP__

#include "base.hpp"
#include "Decorator.hpp"


class Base;

class Trunc : public Decorator {
    protected:
    public:
    Trunc (Base* input) : Decorator() {value = input;}
    double evaluate(){return value->evaluate();}
    std::string stringify(){
      Op* temp = new Op(value->evaluate());
      return temp->stringify();
    }
};
    #endif
