#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include "iterator.hpp"
#include "visitor.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

class Op : public Base {
    public:
        Op(double value) : Base() {
     val = value;
     str = std::to_string(val);
     str.erase(str.find_last_not_of('0') + 1, std::string::npos);
     str.erase(str.find_last_not_of('.') + 1, std::string::npos);
 }
        virtual double evaluate() { return val; }
        virtual std::string stringify() { return str; }
        Base* get_left() {return nullptr;}
        Base* get_right() {return nullptr;}
        Iterator* create_iterator() {
        Iterator* it = new NullIterator(this);
        return it;
        }
        void accept(CountVisitor* vis) {
        vis->visit_op();
        }

    protected:
    double val;
    std::string str;
};

#endif //__OP_HPP__
