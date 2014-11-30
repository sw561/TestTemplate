#include <iostream>
#include <sstream>
#include <cstdio>
#include <stdlib.h>
#include "demo.h"
#include "parameter.h"

// Global variable used to toggle run-time debugging
short unsigned int debug;

int main(int argc, char* argv[])
{
	const Parameter * param;
	FILE *outfile;

	// Process command line arguments
	// Output file
 	if (argc>=2) outfile = fopen(argv[1],"w");
	else{ std::cout << "No output file specified." << std::endl; throw(0);}
	
	// Debug variable
	if (argc>=3) std::istringstream(argv[2]) >> debug;
	else debug = 0;

	// Parameter file
	if (argc>=4) param = Parameter::inst(argv[3]);
	else param = Parameter::inst();
//--------------------------------------------------//
	
	// Your program:
	int z = add(param->a,param->b);
	fprintf(outfile,"%d\n",z);

	fclose(outfile);
	return 0;
}
