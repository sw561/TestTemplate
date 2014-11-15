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

int main()
{
	TEST_INIT()

	TEST("Add zero",&test1)
	TEST("Random",&test2)
	TEST("Zeros",&test3)
	
	TEST_FINALIZE()

	return 0;
}
