#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"

#include "sub.hpp"

//Subtracting Nonzero Numbers 
TEST(SubTest, SubtractingNonzeroNumbers) {
    Base* num1 = new Op(6);
    Base* num2 = new Op(4);
    Sub* test = new Sub(num1, num2);
    EXPECT_EQ(test->evaluate(), 2);
}

//Negative Difference
TEST(SubTest, NegativeDifference) {
    Base* num1 = new Op(4);
    Base* num2 = new Op(6);
    Sub* test = new Sub(num1, num2);
    EXPECT_EQ(test->evaluate(),-2);
}

//Subtracting Negative Numbers
TEST(SubTest, SubtractingNegativeNumbers) {
    Base* num1 = new Op(-4);
    Base* num2 = new Op(-6);
    Sub* test = new Sub(num1, num2);
    EXPECT_EQ(test->evaluate(),2);
}

//Subtracting Big Numbers
TEST(SubTest, SubtractingBigNumbers) {
    Base* num1 = new Op(123456789);
    Base* num2 = new Op(1412450879);
    Sub* test = new Sub(num1, num2);
    EXPECT_EQ(test->evaluate(),-1288994090);
}

#endif //__SUB_TEST_HPP__
