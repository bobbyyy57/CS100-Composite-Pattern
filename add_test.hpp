#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"

#include "add.hpp"
#include "sub.hpp"
#include "pow.hpp"

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
    EXPECT_EQ(test->stringify(),"(4.000000 + 6.000000)");
}

//Adding Negative Numbers
TEST(AddTest, AddingNegativeNumbers) {
    Base* num1 = new Op(-4);
    Base* num2 = new Op(-6);
    Add* test = new Add(num1, num2); 
    EXPECT_EQ(test->evaluate(),-10);
    EXPECT_EQ(test->stringify(),"(-4.000000 + -6.000000)");
}

//Adding Large Numbers
TEST(AddTest, AddingLargeNumbers) {
    Base* num1 = new Op(123456789);
    Base* num2 = new Op(123456789);
    Add* test = new Add(num1, num2);
    EXPECT_EQ(test->evaluate(),246913578);
    EXPECT_EQ(test->stringify(),"(123456789.000000 + 123456789.000000)");
}

//Adding Doubles
TEST(AddTest, AddingDoubles) {
    Base* num1 = new Op(14.76);
    Base* num2 = new Op(87.21);
    Add* test = new Add(num1, num2); 
    EXPECT_EQ(test->evaluate(),101.97);
    EXPECT_EQ(test->stringify(),"(14.760000 + 87.210000)");
}

//Parameters: Pow and Sub
TEST(AddTest, PowandSub) {
     Base* num1 = new Op(3);
     Base* num2 = new Op(7);
     Base* num3 = new Op(5);
     Base* num4 = new Op(2);
     Pow* arg1 = new Pow(num1, num2);
     Sub* arg2 = new Sub(num3, num4);
     Add* test = new Add(arg1, arg2);
     EXPECT_EQ(test->evaluate(), 2190);
     EXPECT_EQ(test->stringify(),"(2187.000000 + 3.000000)");
}

//Sub and Sub
TEST(AddTest, SubandSub) {
     Base* num1 = new Op(3);
     Base* num2 = new Op(7);
     Base* num3 = new Op(5);
     Base* num4 = new Op(2);
     Sub* arg1 = new Sub(num1, num2);
     Sub* arg2 = new Sub(num3, num4);
     Add* test = new Add(arg1, arg2);
     EXPECT_EQ(test->evaluate(), -1);
     EXPECT_EQ(test->stringify(),"(-4.000000 + 3.000000)");
}


#endif //__ADD_TEST_HPP__
