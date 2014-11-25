#include "demo.h"
#include "test.h"
#include "cmath"

short unsigned int debug=0;

// Returns true for pass, otherwise returns false
bool test1()
{
	return add(2,2) == 4;
}

// Returns the expected result.
int test2()
{
	return add(-5,100);
}

// Test the throwing/catching of an exception
bool test3()
{
	int a = pow(2,30);
	int b = pow(2,30);
	try{
		add(a,b);}
	catch (OverflowError& e){
		return true;}
	return false;
}

int main()
{
	TestSuite s(__FILE__);

	// Can pass a bool which is expected to be true
	s.test("First test",add(5,5)==10);

	// Or two objects which are expected to be equal
	// The test function is templated so any types may be passed,
	// providing the type of the 2nd and 3rd argument is the same
	// and that == has been implemented for that type.
	s.test("Second test",add(5,1),6);

	// Can also pass the address of a test function
	// which is expected to return true.
	// If the test fails, then the test function will
	// be re-run with run-time checking enabled (debug=1).
	s.test("2+2",&test1);

	// Again, if the test function returns an object
	// then give the expected output as a third function parameter
	s.test("Add 100",&test2,95);

	// Can check that exceptions are thrown when expected
	s.test("Overflow Test",&test3);

	return 0;
}
