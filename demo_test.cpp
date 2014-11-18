#include "demo.h"
#include "test.h"

short unsigned int debug=0;

// Returns true for pass, otherwise returns false
bool test1()
{
	return add(0,3) == 3;
}

// Returns true for pass, otherwise returns false
bool test2()
{
	return add(0,0)==0;
}

/* Returns the expected result. */
int test3()
{
	return add(5,100);
}

int main()
{
	TestSuite s(__FILE__);

	// The test function can be passed as a pointer
	s.test("Add zero",&test1);

	// The result of the test function can also be called explicitly 
	s.test("Zeros",test2());

	// If the test function returns a value
	// pass the expected result as the third argument
	s.test("Random",&test3,105);

	// Again, the result can be passed explicitly
	int z = add(5,5);
	s.test("Bogey test",z,10);

	// The test function is templated so any types may be passed,
	// providing the type of the 2nd and 3rd argument is the same
	// and that == has been implemented for that type.

	return 0;
}
