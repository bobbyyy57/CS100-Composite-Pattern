#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include <stdlib.h>

class Rand: public Base{

	double val = rand()%100;
    public:
	Rand(): Base(){}
	virtual double evaluate() {return val;}
	virtual std::string stringify() {return std::to_string(val);}

};
#endif //__RAND_HPP__
