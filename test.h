#include <string>
#include <iostream>

#ifndef TEST_H
#define TEST_H

#define TEST_INIT()\
std::cout << "Testing functions in " << __FILE__ << " ..." << std::endl;\
struct Suite suite;\
suite.any_fail = false;\
suite.count = 0;\
suite.count_passed = 0;

#define TEST_FINALIZE()\
if (suite.any_fail){\
	std::cout << suite.count_passed << " out of " << suite.count << " tests passed." << std::endl;}\
else{\
	std::cout << "All tests were successful." << std::endl;}\
std::cout << std::endl;

#define TEST(x,y) test(x,y,suite);

struct Suite{
	bool any_fail;
	int count;
	int count_passed;
};

void test(const std::string &s, bool (*f)(void), struct Suite &suite);

#endif
