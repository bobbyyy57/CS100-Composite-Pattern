#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"

#include "add.hpp"

//Adding Nonzero Numbers 
TEST(AddTest, AddingNonzeroNumbers) {
    Add* test = new Add(4, 6);
    EXPECT_EQ(test->evaluate(), 10);
}

#endif //__ADD_TEST_HPP__
