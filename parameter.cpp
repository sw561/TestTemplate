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

		process_arg(name,val);
		printf("%10s: %.4g\n",name.c_str(),val);
	}
	printf("\n");
}

#define FIRST_PARAM(x) if (name == #x) x = val;
#define PARAM(x) else if (name == #x) x = val;
void Parameter::process_arg(const std::string &name,const double val)
{
	FIRST_PARAM(a)
	PARAM(b)
	PARAM(factor)
	else{
		throw ParameterNotFound();
	}
}
