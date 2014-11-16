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
	int z = add(3,4);
	std::cout << "Answer: " << z << std::endl;

	return 0;
}
