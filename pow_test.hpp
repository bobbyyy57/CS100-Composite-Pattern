#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "gtest/gtest.h"

#include "pow.hpp"
#include "add.hpp"

//Power Nonzero Numbers 
TEST(PowTest, PowerNonezeroNumbers ) {
     Base* num1 = new Op(6);
     Base* num2 = new Op(4);
     Pow* test = new Pow(num1, num2);
     EXPECT_EQ(test->evaluate(), 1296);
     EXPECT_EQ(test->stringify(),"(6.000000 ** 4.000000)");
}

//Negative Power
TEST(PowTest, NegativePower) {
     Base* num1 = new Op(2);
     Base* num2 = new Op(-3);
     Pow* test = new Pow(num1, num2);
     EXPECT_EQ(test->evaluate(), .125);    
     EXPECT_EQ(test->stringify(),"(2.000000 ** -3.000000)");
}       

//Decimal Power
TEST(PowTest, DecimalPower) {
     Base* num1 = new Op(2);
     Base* num2 = new Op(1.2);
     Pow* test = new Pow(num1, num2);
     EXPECT_NEAR(test->evaluate(), 2.2974, 1e-5);
     EXPECT_EQ(test->stringify(),"(2.000000 ** 1.200000)");
}

//Power 0
TEST(PowTest, ZeroPower) {
     Base* num1 = new Op(2);
     Base* num2 = new Op(0);
     Pow* test = new Pow(num1, num2);
     EXPECT_DOUBLE_EQ(test->evaluate(), 1);
     EXPECT_EQ(test->stringify(),"(2.000000 ** 0.000000)");
}

//Infinity 
TEST(PowTest, InfinityPower) {
     Base* num1 = new Op(1000);
     Base* num2 = new Op(1000);
     Pow* test = new Pow(num1, num2);
     EXPECT_EQ(isnan(test->evaluate()), true);
     EXPECT_EQ(test->stringify(),"(1000.000000 ** 1000.000000)");
}


//Parameters: Add and Add
TEST(PowTest, AddandAdd) {
     Base* num1 = new Op(1);
     Base* num2 = new Op(2);
     Base* num3 = new Op(3);
     Base* num4 = new Op(4);
     Add* arg1 = new Add(num1, num2);
     Add* arg2 = new Add(num3, num4);
     Pow* test = new Pow(arg1, arg2);
     EXPECT_EQ(test->evaluate(), 2187);
     EXPECT_EQ(test->stringify(),"(3.000000 ** 7.000000)");
}
                       
/*
TEST(PowTest, AddandSub) {
     Base* num1 = new Op(1);
     Base* num2 = new Op(2);
     Base* num3 = new Op(3);
     Base* num4 = new Op(4);
     Add* arg1 = new Add(num1, num2);
     Add* arg2 = new Add(num3, num4);
     Pow* test = new Pow(arg1, arg2);
     EXPECT_EQ(test->evaluate(), 2187);
    // EXPECT_EQ(test->stringify(),"1.08673");
}
*/

#endif //__POW_TEST_HPP__
