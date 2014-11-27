#include <iostream>
#include <sstream>
#include <cstdio>
#include "demo.h"
#include "parameter.h"

// Global variable used to toggle run-time debugging
short unsigned int debug;

int main(int argc, char* argv[])
{
	const Parameter * param;
	FILE *outfile;

	// Process command line arguments
 	if (argc==2){
		std::istringstream(argv[1]) >> debug;
		param = Parameter::inst();
	}
	else if (argc==3){
		std::istringstream(argv[1]) >> debug;
		param = Parameter::inst(argv[2]);
	}
	else if (argc==4){
		std::istringstream(argv[1]) >> debug;
		param = Parameter::inst(argv[2]);
		outfile = fopen(argv[3],"w");
	}
	else{
 		std::cout << "No input file name" << std::endl;
		std::cout << "Using default parameters" << std::endl;
		param = Parameter::inst();
		debug = 0;
	}
	
	// Your program:
	int z = add(param->a,param->b);
	if (argc==4){
		fprintf(outfile,"%d\n",z);
	}
	else{
		std::cout << z << std::endl;
	}

	if (argc==4) fclose(outfile);
	return 0;
}
