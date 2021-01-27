#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"

#include "sub.hpp"
#include "pow.hpp"
#include "add.hpp"

//Subtracting Nonzero Numbers 
TEST(SubTest, SubtractingNonzeroNumbers) {
    Base* num1 = new Op(6);
    Base* num2 = new Op(4);
    Sub* test = new Sub(num1, num2);
    EXPECT_EQ(test->evaluate(), 2);
    EXPECT_EQ(test->stringify(),"(6.000000 - 4.000000)");
}

//Negative Difference
TEST(SubTest, NegativeDifference) {
    Base* num1 = new Op(4);
    Base* num2 = new Op(6);
    Sub* test = new Sub(num1, num2);
    EXPECT_EQ(test->evaluate(),-2);
    EXPECT_EQ(test->stringify(),"(4.000000 - 6.000000)");
}

//Subtracting Negative Numbers
TEST(SubTest, SubtractingNegativeNumbers) {
    Base* num1 = new Op(-4);
    Base* num2 = new Op(-6);
    Sub* test = new Sub(num1, num2);
    EXPECT_EQ(test->evaluate(),2);
    EXPECT_EQ(test->stringify(),"(-4.000000 - -6.000000)");
}

//Subtracting Big Numbers
TEST(SubTest, SubtractingBigNumbers) {
    Base* num1 = new Op(123456789);
    Base* num2 = new Op(1412450879);
    Sub* test = new Sub(num1, num2);
    EXPECT_EQ(test->evaluate(),-1288994090);
    EXPECT_EQ(test->stringify(),"(123456789.000000 - 1412450879.000000)");
}

//Parameters: Pow and Pow
TEST(SubTest, PowandPow) {
     Base* num1 = new Op(3);
     Base* num2 = new Op(7);
     Base* num3 = new Op(5);
     Base* num4 = new Op(2);
     Pow* arg1 = new Pow(num1, num2);
     Pow* arg2 = new Pow(num3, num4);
     Sub* test = new Sub(arg1, arg2);
     EXPECT_EQ(test->evaluate(), 2162);
     EXPECT_EQ(test->stringify(),"(2187.000000 - 25.000000)");
}

//Parameters: Add and Sub
TEST(SubTest, AddandSub) {
     Base* num1 = new Op(3);
     Base* num2 = new Op(7);
     Base* num3 = new Op(5);
     Base* num4 = new Op(2);
     Add* arg1 = new Add(num1, num2);
     Sub* arg2 = new Sub(num3, num4);
     Sub* test = new Sub(arg1, arg2);
     EXPECT_EQ(test->evaluate(), 7);
     EXPECT_EQ(test->stringify(),"(10.000000 - 3.000000)");
}


#endif //__SUB_TEST_HPP__
