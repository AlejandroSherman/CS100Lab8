#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "op.hpp"
#include <iostream>
#include <string>

class Mult : public Base {
    public:
   Mult( Base* left, Base* right) : Base() {
   left_child = left;
   right_child = right;
   lnum = left->evaluate();
   rnum = right->evaluate();
   lhs = left->stringify();
   rhs = right->stringify();
}
      virtual double evaluate () {return (lnum * rnum) ;}
      virtual std::string stringify() {return lhs + " * " + rhs;}
      Base* get_left() {return left_child;}
      Base* get_right() {return right_child;}
      Iterator* create_iterator() {
      Iterator* it = new BinaryIterator(this);
      return it;
      }
  private:
    std::string lhs;
    std::string rhs;
    double lnum;
    double rnum;
    Base* left_child;
    Base* right_child;
};

#endif
