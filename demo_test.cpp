#include "demo.h"
#include "test.h"

short unsigned int debug=0;

bool test1()
{
	return add(0,3) == 3;
}

bool test2()
{
	int j = add(5,100);
	if (j == 105) return true;
	return false;
}

bool test3()
{
	return add(0,0)==0;
}

bool test4()
{
	return add(5,5) == 9;
}

int main()
{
	TestSuite s(__FILE__);

	s.test("Add zero",&test1);
	s.test("Random",&test2);
	s.test("Zeros",&test3);
	// s.test("Bogey test",&test4);

	return 0;
}
