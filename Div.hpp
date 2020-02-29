#ifndef _DIV_HPP_
#define _DIV_HPP_

#include "op.hpp"
using namespace std;
class Div : public Base {
	public:
		Div( Base* left, Base* right) : Base()
		{
			left_child = left;
	    right_child = right;
			lstring = left -> stringify();
			rstring = right -> stringify();
			ldouble = left -> evaluate();
			rdouble = right -> evaluate();
		}
		virtual double evaluate()
		{
			return(ldouble / rdouble);
		}
		virtual string stringify()
		{
			return (lstring + " / " + rstring);
		}
		Base* get_left() {return left_child;}
		Base* get_right() {return right_child;}
		Iterator* create_iterator() {
		Iterator* it = new BinaryIterator(this);
		return it;
		}
	private:
		string lstring;
		string rstring;
		double ldouble;
		double rdouble;
		Base* left_child;
    Base* right_child;
};

#endif
