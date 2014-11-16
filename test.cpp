#include "test.h"
#include <iostream>

TestSuite::TestSuite(const std::string &s)
{
	std::cout << "Testing Functions in " << s << " ..." << std::endl;
	any_fail = false;
	count = 0;
	count_passed = 0;
}

TestSuite::~TestSuite()
{
	if (count_passed < count){
		std::cout << count_passed << " out of " << count << " tests were successful." << std::endl;}
	else{
		std::cout << "All tests were successful." << std::endl;}
	std::cout << std::endl;
}

void TestSuite::test(const std::string &s, bool (*f)(void))
{
	count++;
	bool pass = f();
	if (pass){
		count_passed++;
	}
	else{
		std::cout << s << " failed." << std::endl;
	}
}
