#ifndef __PARENTHESIES_HPP__
#define __PARENTHESIES_HPP__

#include "base.hpp"
#include "Decorator.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

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
    Base* get_left() {return value;}
    Base* get_right() {return nullptr;}
    Iterator* create_iterator() {
    return new UnaryIterator(this);
    }
    void accept(CountVisitor* vis) {
    vis->visit_paren();
    }
};
    #endif
