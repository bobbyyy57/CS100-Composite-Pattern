#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"

#include "add.hpp"

//Adding Nonzero Numbers 
TEST(AddTest, EvaluateNonzeroNumbers) {
    Base* num1 = new Op(4);
    Base* num2 = new Op(6);
    Add* test = new Add(num1, num2);
    EXPECT_EQ(test->evaluate(), 10);
}

TEST(AddTest, StringNonzeroNumbers) {
    Base* num1 = new Op(4);
    Base* num2 = new Op(6);
    Add* test = new Add(num1, num2);
    EXPECT_EQ(test->stringify(),"10");
}

//Adding Negative Numbers
TEST(AddTest, AddingNegativeNumbers) {
    Base* num1 = new Op(-4);
    Base* num2 = new Op(-6);
    Add* test = new Add(num1, num2); 
    EXPECT_EQ(test->evaluate(),-10);
}

//Adding Large Numbers
TEST(AddTest, AddingLargeNumbers) {
    Base* num1 = new Op(123456789);
    Base* num2 = new Op(-123456789);
    Add* test = new Add(num1, num2);
    EXPECT_EQ(test->evaluate(),0);
}

//Adding Doubles
TEST(AddTest, AddingDoubles) {
    Base* num1 = new Op(14.76);
    Base* num2 = new Op(87.21);
    Add* test = new Add(num1, num2); 
    EXPECT_EQ(test->evaluate(),101.97);
}

#endif //__ADD_TEST_HPP__
