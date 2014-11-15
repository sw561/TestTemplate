#include <iostream>
#include "debug.h"
#include "demo.h"

#define DIAGNOSE_ADD(x,y,z) if (debug>0) diagnose_add(x,y,z);

int add(int a, int b)
{
	int z = a+b;

	DIAGNOSE_ADD(a,b,z);
		
	return z;
}

void diagnose_add(int a, int b, int z)
{
	std::cout << "Checking..." << std::endl;
	if (z-b != a){
		std::cout << "add(" << a << "," << b << ") returned " << z << std::endl;
		throw(1);
	}
}
