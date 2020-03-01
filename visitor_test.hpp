#ifndef _VISITOR_TEST_HPP
#define _VISITOR_TEST_HPP

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

TEST(CountVisitorTest, SimpleTree) {
  Op* op1 = new Op(3);
  Op* op2 = new Op(5);
  Op* op3 = new Op(2);
  Op* op4 = new Op(1);
	Sub* first = new Sub( op1, op2);
	Div* second = new Div( op3, op4);

	Add* dummy = new Add(first,second);
	CountVisitor *test1 = new CountVisitor();
	PreorderIterator *test2 = new PreorderIterator(dummy);
	test2->first();
	while(test2->is_done() == false){
	    test2->current()->accept(test1);
	    test2->next();
	}
	EXPECT_EQ(test1->sub_count(), 1);
	EXPECT_EQ(test1->div_count(), 1);
	EXPECT_EQ(test1->op_count(), 4);
}


#endif
