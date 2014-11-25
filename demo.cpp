#include <iostream>
#include "demo.h"
#include "debug.h"

#define DIAGNOSE_ADD(x,y,z) if (debug>0) diagnose_add(x,y,z);

int add(int a, int b)
{
	int z = a+b;
	
	if (z < std::min(a,b)){
		DIAGNOSE_ADD(a,b,z);
		throw OverflowError();
	}
		
	return z;
}

void diagnose_add(int a, int b, int z)
{
	std::cout << "add(" << a << "," << b << ") returned " << z << std::endl;
}
