#include <iostream>
using namespace std;
#include <vector>
#include <list>

//#include "BubbleSort.hpp"
//#include "SelectionSort.hpp"
#include "Div.hpp"
#include "ListContainer.hpp"
#include "Pow.hpp"
#include "Sub.hpp"
#include "VectorContainer.hpp"
#include "add.hpp"
#include "base.hpp"
#include "container.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "sort.hpp"
#include "Truncate.hpp"
#include "Parenthesies.hpp"
#include "FLoor.hpp"
#include "Ceiling.hpp"
#include "Abs.hpp"
#include "iterator.hpp"
#include "visitor.hpp"


int main() {
  Op* op1 = new Op(1);
  Op* op2 = new Op(2);
  Op* op3 = new Op(3);
  Op* op6 = new Op(6);

  Sub* sub1 = new Sub(op2, op1);
  Paren* p1 = new Paren(sub1);

  Add* add1 = new Add(op6, op3);
  Paren* p2 = new Paren(add1);
  Mult* mult1 = new Mult(p1, p2);
  Trunc* t1 = new Trunc(sub1);

  Sub* sub2 = new Sub(mult1, t1);

  Sub* first = new Sub(sub1, sub2);

  Pow* pow1 = new Pow(add1, op6);

  Paren* second = new Paren(pow1);
  Sub* test = new Sub(first, second);
  cout << "Result: " << test->stringify() << " = " <<  test->evaluate() << endl;
	cout << "PreOrder traversal:" << endl;
    cout << "Stringify first: " << first->stringify() << endl << endl;
    cout << "Stringify second: " << second->stringify() << endl << endl;
	PreorderIterator* pre_it = new PreorderIterator(test);
	for(pre_it->first(); !pre_it->is_done(); pre_it->next()) {
		cout << pre_it->current()->stringify();
		cout << endl;
	}

  cout << "End of sequence" << endl;
  cout << "Number of occurances in the tree:" << endl;

  CountVisitor *cv = new CountVisitor();
  pre_it->first();
	while(pre_it->is_done() == false){
	    pre_it->current()->accept(cv);
	    pre_it->next();
	}
  cout << "Ops:" << cv->op_count() << endl;
  cout << "Rands:" << cv->rand_count() << endl;
  cout << "Adds:" << cv->add_count() << endl;
  cout << "Subs:" << cv->sub_count() << endl;
  cout << "Mults:" << cv->mult_count() << endl;
  cout << "Divs:" << cv->div_count() << endl;
  cout << "Pows:" << cv->pow_count() << endl;
  cout << "Ceils:" << cv->ceil_count() << endl;
  cout << "Floors:" << cv->floor_count() << endl;
  cout << "Abs:" << cv->abs_count() << endl;
  cout << "Parens:" << cv->paren_count() << endl;
  cout << "Truncs:" << cv->trunc_count() << endl;

return 0;
};
