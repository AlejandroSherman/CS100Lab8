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

TEST(CountVisitorTest, SimpleTree1) {
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
TEST(CountVisitorTest, SimpleTree2) {
	Op* op3 = new Op(3);
	Op* opN5 = new Op(-5);
	Op* op11 = new Op(11);
	Op* op0 = new Op(0);
	Add* first = new Add(op3, opN5);
	Mult* second = new Mult(op11, op0);

	Sub* dummy = new Sub(first, second);
	CountVisitor* test1 = new CountVisitor();
	PreorderIterator* test2 = new PreorderIterator(dummy);
	test2->first();
	while (test2->is_done() == false) {
		test2->current()->accept(test1);
		test2->next();
	}
	EXPECT_EQ(test1->add_count(), 1);
	EXPECT_EQ(test1->mult_count(), 1);
	EXPECT_EQ(test1->op_count(), 4);
}
TEST(CountVisitorTest, SimpleTree3) {
	Op* op3 = new Op(3);
	Op* opN5 = new Op(-5);
	Op* op11 = new Op(11);
	Op* op0 = new Op(0);
	
	Op* op5 = new Op(5);
	Op* op2 = new Op(2);
	Op* op1 = new Op(1);
	Op* op121 = new Op(121);

	Sub* sub1 = new Sub(op1, op2);
	Div* div1 = new Div(op121, op11);

	Add* add1 = new Add(op3, opN5);
	Mult* mult1 = new Mult(op11, op0);

	Sub* first = new Sub(sub1, div1);
	Pow* second = new Pow(add1, mult1);

	Sub* dummy = new Sub(first, second);
	CountVisitor* test1 = new CountVisitor();
	PreorderIterator* test2 = new PreorderIterator(dummy);
	test2->first();
	while (test2->is_done() == false) {
		test2->current()->accept(test1);
		test2->next();
	}
	EXPECT_EQ(test1->add_count(), 1);
	EXPECT_EQ(test1->sub_count(), 2);
	EXPECT_EQ(test1->mult_count(), 1);
	EXPECT_EQ(test1->div_count(), 1);
	EXPECT_EQ(test1->pow_count(), 1);
	EXPECT_EQ(test1->op_count(), 8);
}
TEST(CountVisitorTest, SimpleTree4) {
	Op* op3 = new Op(3);
	Op* opN5 = new Op(-5);
	Op* op11 = new Op(11);
	Op* op0 = new Op(0);

	Op* op5 = new Op(5);
	Op* op2 = new Op(2);
	Op* op1 = new Op(1);
	Op* op121 = new Op(121);

	Op* op1000 = new Op(1000);

	Sub* sub1 = new Sub(op1, op2);
	Div* div1 = new Div(op121, op11);

	Add* add1 = new Add(op3, opN5);
	Mult* mult1 = new Mult(op11, op0);

	Sub* first = new Sub(sub1, div1);
	Pow* second = new Pow(add1, mult1);

	Sub* dummy = new Sub(first, second);
	Sub* dummy2 = new Sub(first, op1000);

	CountVisitor* test1 = new CountVisitor();
	PreorderIterator* test2 = new PreorderIterator(dummy);
	CountVisitor* test3 = new CountVisitor();
	PreorderIterator* test4 = new PreorderIterator(dummy2);
	test2->first();
	test4->first();
	while (test2->is_done() == false) {
		test2->current()->accept(test1);
		test2->next();
	}
	while (test4->is_done() == false) {
		test4->current()->accept(test3);
		test4->next();
	}
	EXPECT_EQ(test1->add_count(), 1);
	EXPECT_EQ(test1->sub_count(), 2);
	EXPECT_EQ(test1->mult_count(), 1);
	EXPECT_EQ(test1->div_count(), 1);
	EXPECT_EQ(test1->pow_count(), 1);
	EXPECT_EQ(test1->op_count(), 8);
	EXPECT_EQ(test3->add_count(), 0);
	EXPECT_EQ(test3->sub_count(), 2);
	EXPECT_EQ(test3->mult_count(), 0);
	EXPECT_EQ(test3->div_count(), 1);
	EXPECT_EQ(test3->pow_count(), 0);
	EXPECT_EQ(test3->op_count(), 5);
}
TEST(CountVisitorTest, SimpleTree5) {
	Op* op1 = new Op(1);
	Op* op2 = new Op(2);
	Op* op3 = new Op(3);
	Op* op6 = new Op(6);

	Sub* sub1 = new Sub(op2, op1); //2 op, 1 sub
	Paren* p1 = new Paren(sub1);	//1 paren 1 sub 2 op	

	Add* add1 = new Add(op6, op3); //1 add, 2 op
	Paren* p2 = new Paren(add1); //1 paren, 1 add, 2 op
	Mult* mult1 = new Mult(p1, p2); //1 mult, 2 paren, 1 sub, 1 add, 4 op
	Trunc* t1 = new Trunc(sub1); //1 trunc, 1 sub, 2 op
								
	Sub* sub2 = new Sub(mult1, t1);//1 mult, 2 paren, 3 sub, 1 add, 6 op, 1 trunc

	Sub* first = new Sub(sub1, sub2);//1 mult, 2 paren, 5 sub, 1 add, 8 op, 1 trunc 

	Pow* second = new Pow(add1, op6);//1 mult, 2 paren, 5 sub, 2 add, 11 op, 1 trunc, 1 pow

	Sub* dummy = new Sub(first, second);
	CountVisitor* test1 = new CountVisitor();
	PreorderIterator* test2 = new PreorderIterator(dummy);
	test2->first();
	while (test2->is_done() == false) {
		test2->current()->accept(test1);
		test2->next();
	}
	EXPECT_EQ(test1->add_count(), 2);
	EXPECT_EQ(test1->sub_count(), 5);
	EXPECT_EQ(test1->mult_count(), 1);
	EXPECT_EQ(test1->div_count(), 0);
	EXPECT_EQ(test1->pow_count(), 1);
	EXPECT_EQ(test1->paren_count(), 2);
	EXPECT_EQ(test1->trunc_count(), 1);

	EXPECT_EQ(test1->op_count(), 11);
}
#endif
