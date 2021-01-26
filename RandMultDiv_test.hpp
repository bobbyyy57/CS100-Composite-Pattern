#ifndef __RAND_MULT_DIV_TEST_HPP__
#define __RAND_MULT_DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "base.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "mult.hpp"

TEST(OpTest, MultEvalNonZero){
	Op* two = new Op(2);
	Op* three = new Op(3);
	Mult* test = new Mult(two, three);
	EXPECT_EQ(test->evaluate(), 8);
}

TEST(OpTest, MultEvalZero){
	Op* zero = new Op(0);
	Op* one = new Op(1);
	Mult* test = new Mult(zero, one);
	EXPECT_EQ(test->evaluate(), 0);
}

TEST(OpTest, MultEvalNeg){
	Op* neg_one = new Op(-1);
	Op* nine = new Op(9);
	Mult* test = new Mult(neg_one, nine);
	EXPECT_EQ(test->evaluate(), 8);
}

#endif//__RAND_MULT_DIV_TEST_HPP__
