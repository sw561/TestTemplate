#include <iostream>
#include <sstream>
#include "demo.h"

short unsigned int debug;

void process_args(int argc, char* argv[])
{
	if (argc>1){
		std::istringstream(argv[1]) >> debug;
	}
	else{
		debug = 0;
	}
}

int main(int argc, char* argv[])
{
	process_args(argc, argv);

	int z = add(3,4);
	std::cout << "Answer: " << z << std::endl;

	return 0;
}
