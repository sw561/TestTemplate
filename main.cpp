#include <iostream>
#include <sstream>
#include "demo.h"

// Global variable used to toggle run-time debugging
short unsigned int debug;

int main(int argc, char* argv[])
{
	// Process command line arguments
	if (argc>1){
		std::istringstream(argv[1]) >> debug;
	}
	else{
		debug = 0;
	}
	
	// Your program:
	int z = 0;
	// Keep adding one until overflow error is thrown
	// Find the maximum integer value
	while (true)
	{
		try { z=add(z,1); }
		catch (OverflowError& e){ 
			std::cout << "Answer: " << z << std::endl;
			break;
		}
	}

	return 0;
}
