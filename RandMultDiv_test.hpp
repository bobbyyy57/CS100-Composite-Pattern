#ifndef __RAND_MULT_DIV_TEST_HPP__
#define __RAND_MULT_DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "base.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "mult.hpp"


TEST(MultTest, MultEvalNonZero){
	Op* two = new Op(2);
	Op* three = new Op(3);
	Mult* test = new Mult(two, three);
//	EXPECT_EQ(test->stringify(), "2.0 * 3.0");
	EXPECT_EQ(test->evaluate(), 6);
}

TEST(MultTest, MultEvalZero){
	Op* zero = new Op(0);
	Op* three = new Op(3);
	Mult* test = new Mult(zero, three);
	EXPECT_EQ(test->evaluate(), 0);
}

#endif//__RAND_MULT_DIV_TEST_HPP__
