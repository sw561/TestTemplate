#ifndef DEMO_H
#define DEMO_H

#include <stdexcept>

int add(int,int);
void diagnose_add(int,int,int);
class OverflowError : public std::exception{
	public:
		virtual const char * what() const throw(){
			return "Overflow Error";}
};

#endif
