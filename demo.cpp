#include <iostream>
#include "demo.h"
#include "debug.h"
#include "parameter.h"

#define DIAGNOSE_ADD(x,y,z) if (debug>0) diagnose_add(x,y,z);

int add(const int a, const int b)
{
	static const Parameter * param = Parameter::inst();
	int z = (a+b) * param->factor;
	
	DIAGNOSE_ADD(a,b,z);
	if (z < std::min(a,b)){
		throw OverflowError();
	}
		
	return z;
}

void diagnose_add(int a, int b, int z)
{
	std::cout << "add(" << a << "," << b << ") returned " << z << std::endl;
}
