#ifndef __RAND_MULT_DIV_TEST_HPP__
#define __RAND_MULT_DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "base.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "mult.hpp"
#include "div.hpp"
#include <cmath>

//UNTI TETS FOR RAND CLASS//
TEST(RandTest, RandEvalCorrect){
	Rand* test = new Rand();
	EXPECT_TRUE((test->evaluate() <=100)&&(test->evaluate()>=0));
}
//END OF RAND TEST


//UNIT TEST FOR MULT CLASS
TEST(MultTest, MultEvalNonZero){
	Op* two = new Op(2);
	Op* three = new Op(3);
	Mult* test = new Mult(two, three);
	EXPECT_EQ(test->stringify(), "(2.000000 * 3.000000)");
	EXPECT_EQ(test->evaluate(), 6);
}

TEST(MultTest, MultEvalZero){
	Op* zero = new Op(0);
	Op* three = new Op(3);
	Mult* test = new Mult(zero, three);
	EXPECT_EQ(test->evaluate(), 0);
}

TEST(MultTest, MultEvalNeg){
	Op* neg_one = new Op(-1);
	Op* three = new Op(3);
	Mult* test = new Mult(neg_one, three);
	EXPECT_EQ(test->evaluate(), -3);
}

TEST(MultTest, MultEvalNegPos){
	Op* neg_one = new Op(-1);
	Op* neg_three = new Op(-3);
	Mult* test = new Mult(neg_one, neg_three);
	EXPECT_EQ(test->evaluate(), 3);
}
TEST(MultTest, MultEvalBig){
	Op* big_one = new Op(35);
	Op* big_two = new Op(98);
	Mult* test = new Mult(big_one, big_two);
	EXPECT_EQ(test->evaluate(), 3430);
	EXPECT_EQ(test->stringify(),"(35.000000 * 98.000000)");
}
TEST(MultTest, MultEvalInf){
	Op* big = new Op(9800000000000000000);
	Op* big2 = new Op(9800000000000000000);
	Mult* test = new Mult(big, big2);
	EXPECT_EQ(test->evaluate(), 9.604e+37);
//	EXPECT_EQ(test->stringify, ())
}
TEST(MultTest, MultEvalDecimals){
	Base* decimal1 = new Op(1.8);
	Base* decimal2 = new Op(3.6);
	Mult* test = new Mult(decimal1, decimal2);
	EXPECT_EQ(test->stringify(), "(1.800000 * 3.600000)");
	EXPECT_EQ(test->evaluate(), 6.48);
}
//END OF MULT UNIT TEST

//UNIT TEST FOR DIV CLASS
TEST(DivTest, DivEvalWhole){
	Op* three = new Op(3);
	Op* one = new Op(1);
	Div* test = new Div(three, one);
	EXPECT_EQ(test->stringify(), "(3.000000 / 1.000000)");
	EXPECT_EQ(test->evaluate(), 3);
}

TEST(DivTest, DivEvalNeg){
	Op* neg_one = new Op(-1);
	Op* three = new Op(3);
	Div* test = new Div(three, neg_one);
	EXPECT_EQ(test->evaluate(), -3);
}

TEST(DivTest, DivEvalDecimal){
	Op* three = new Op(3);
	Op* two = new Op(2);
	Div* test = new Div(three, two);
	EXPECT_EQ(test->evaluate(), 1.5);
	EXPECT_EQ(test->stringify(), "(3.000000 / 2.000000)");
}
TEST(DivTest, DivEvalInfiniteDecimals){
	Op* three = new Op(3);
	Op* one = new Op(1);
	Div* test = new Div(one, three);
	EXPECT_EQ(test->stringify(), "(1.000000 / 3.000000)" );
	EXPECT_NEAR(test->evaluate(),0.333333, 0.333 );
}
TEST(DivTest, DivEvalZero){
	Op* one = new Op(1);
	Op* zero = new Op(0);
	Div* test = new Div(one, zero);
	EXPECT_EQ(isnan(test->evaluate()), true);
	EXPECT_EQ(test->stringify(), "(1.000000 / 0.000000)");
}
//END OF DIV TESTS//

TEST(MultyTest, DivMultEval){
	Op* one = new Op(1);
	Op* three = new Op(3);
	Mult* multy = new Mult(one, three);
	Div* divy = new Div(multy, three);
	EXPECT_EQ(divy->evaluate(), 1);
	EXPECT_EQ(divy->stringify(), "(3.000000 / 3.000000)");
}




#endif//__RAND_MULT_DIV_TEST_HPP__
