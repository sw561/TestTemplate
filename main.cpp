#include <iostream>
#include <sstream>
#include "demo.h"
#include "parameter.h"

// Global variable used to toggle run-time debugging
short unsigned int debug;

int main(int argc, char* argv[])
{
	const Parameter * param;

	// Process command line arguments
 	if (argc<2){
 		std::cout << "No input file name" << std::endl;
		std::cout << "Using default: input.txt" << std::endl;
		param = Parameter::inst();

		debug = 0;
 	}
 	else if (argc==2){
		param = Parameter::inst(argv[1]);
		debug = 0;
	}
	else{
		param = Parameter::inst(argv[1]);
		std::istringstream(argv[2]) >> debug;
	}
	
	// Your program:

	std::cout << add(param->a,param->b) << std::endl;

	return 0;
}
