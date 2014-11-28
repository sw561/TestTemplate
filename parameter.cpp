#include "parameter.h"
#include <fstream>
#include <sstream>
#include <cstdio>

Parameter::Parameter(const std::string &s)
{
	// Default Values can be placed here or in input.txt.
	factor = 1;
	a = 3;
	b = 4;

	if (s=="_.txt") return;

	std::ifstream input;
	std::string line, name;
	double val;

	// Open input file
	input.open(s.c_str());

	printf("Using the following parameters, or default values where unspecified\n");
	while (std::getline(input,line))
	{
		std::istringstream line_stream(line);
		line_stream >> name >> val;

		printf("%10s: %7.4f\n",name.c_str(),val);
		process_arg(name,val);
	}
	printf("\n");
}

#define FIRST_PARAM(x) if (name == #x) x = val;
#define PARAM(x) else FIRST_PARAM(x)
void Parameter::process_arg(const std::string &name,const double val)
{
	// Instructions for processing lines in input file
	// These can be written simply for each parameter with the macros
	FIRST_PARAM(a)
	PARAM(b)
	PARAM(factor)
	else{ throw ParameterNotFound(); }

	// If a parameter is not processed using the above macros 
	// then an exception will be thrown
}
