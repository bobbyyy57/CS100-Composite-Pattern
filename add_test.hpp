#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"

#include "add.hpp"

//Adding Nonzero Numbers 
TEST(AddTest, AddingNonzeroNumbers) {
    Add* test = new Add(4, 6);
    EXPECT_EQ(test->evaluate(), 10);
}

//Adding Negative Numbers
TEST(AddTest, AddingNegativeNumbers) {
    Add* test = new Add(-4,-6);
    EXPECT_EQ(test->evaluate(),-10);
}

//Adding Large Numbers
TEST(AddTest, AddingLargeNumbers) {
    Add* test = new Add(123456789,-123456789);
    EXPECT_EQ(test->evaluate(),0);
}

//Adding Doubles
TEST(AddTest, AddingDoubles) {
    Add* test = new Add(9.81,5.34);
    EXPECT_EQ(test->evaluate(),15.15);
}

#endif //__ADD_TEST_HPP__
