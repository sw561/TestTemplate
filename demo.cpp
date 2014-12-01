#include <iostream>
#include "demo.h"
#include "debug.h"
#include "parameter.h"

#ifdef DEBUG
#define DIAGNOSE_ADD(x,y,z) if (debug>0) diagnose_add(x,y,z);
#else
#define DIAGNOSE_ADD(x,y,z)
#endif

int add(const int a, const int b)
{
	static const int factor = Parameter::inst()->factor;
	int z = (a+b) * factor;
	
	DIAGNOSE_ADD(a,b,z);
	if (a>0 && b>0){
		if (z < std::min(a,b)) throw OverflowError();
	}
	else if (a<0 && b<0){
		if (z > std::max(a,b)) throw OverflowError();
	}
		
	return z;
}

void diagnose_add(int a, int b, int z)
{
	std::cout << "add(" << a << "," << b << ") returned " << z << std::endl;
}
