#include <iostream>
#include <sstream>
#include <fstream>
#include "demo.h"
#include "parameter.h"

// Global variable used to toggle run-time debugging
short unsigned int debug;

int main(int argc, char* argv[])
{
	const Parameter * param;
	std::streambuf *coutbuf;

	// Process command line arguments
 	if (argc==2){
		param = Parameter::inst(argv[1]);
		debug = 0;
	}
	else if (argc==3){
		param = Parameter::inst(argv[1]);
	}
	else if (argc==4){
		param = Parameter::inst(argv[1]);

		std::istringstream(argv[3]) >> debug;
	}
	else{
 		std::cout << "No input file name" << std::endl;
		std::cout << "Using default: input.txt" << std::endl;
		param = Parameter::inst();
		debug = 0;
	}
	
	// Your program:

	std::cout << add(param->a,param->b) << std::endl;

	return 0;
}
