#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"

class Add  : public Base {
    private:
        double val1;
        double val2;
    public:
        Add(double num1, double num2) : Base() {
                val1 = num1;
                val2 = num2;
        }
        virtual double evaluate() {
                return val1 + val2;
        }
        virtual std::string stringify() {
                 return "(" +  std::to_string(val1) + "+" std::to_string(val2) + ")";
        }
};

#endif //__ADD_HPP__
