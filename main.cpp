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
	Op* op3 = new Op(2);
	Add* add = new Add(op1, op2);
  Op* op4 = new Op(4);
	Sub* sub = new Sub(add, op4);
  Trunc* trunc = new Trunc(sub);
  cout << trunc->evaluate() << endl;

	cout << "PreOrder traversal:" << endl;
	PreorderIterator* pre_it = new PreorderIterator(trunc);
	for(pre_it->first(); !pre_it->is_done(); pre_it->next()) {
		cout << pre_it->current()->stringify();
		cout << endl;
	}


return 0;
};
