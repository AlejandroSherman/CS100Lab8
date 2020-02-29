#ifndef __PARENTHESIES_HPP__
#define __PARENTHESIES_HPP__

#include "base.hpp"
#include "Decorator.hpp"


class Base;

class Paren : public Decorator {
    protected:
    public:
    Paren (Base* input) : Decorator() {value = input;}
    double evaluate(){ return value->evaluate();}
    std::string stringify(){
      string result = "(" + value->stringify() + ")";
      return result;
    }
};
    #endif
