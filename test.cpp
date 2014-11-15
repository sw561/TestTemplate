#include "test.h"

void test(const std::string &s, bool (*f)(void), struct Suite &suite)
{
	suite.count++;
	bool pass = f();
	if (pass){
		suite.count_passed++;
	}
	else{
		std::cout << s << " failed." << std::endl;
	}

	suite.any_fail = suite.any_fail || !pass;
}
