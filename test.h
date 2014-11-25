#ifndef TEST_H
#define TEST_H

#include <string>
#include <iostream>
#include "debug.h"

class TestSuite{
	public:
		TestSuite(const std::string&);
		~TestSuite();

		// Using boolean pass variable
		void test(const std::string&, const bool&);
		void test(const std::string&, bool (*f)(void));

		// Comparing result with expected result
		template<typename T>
		void test(const std::string&, T (*f)(void), const T&);
		template<typename T>
		bool test(const std::string&, const T&, const T&);

		// Rerun with diagnostics
		template<typename T>
		void rerun(T (*f)(void));

	private:
		int count;
		int count_passed;
};

template<typename T>
void TestSuite::test(const std::string &s, T (*f)(void), const T &ans)
{
	T res = f();
	bool pass = test(s,res,ans);
	if (!pass){
		rerun(f);
	}
}

template<typename T>
bool TestSuite::test(const std::string &s, const T &res, const T &ans)
{
	bool pass = ( res==ans );
	test(s,pass);
	if (!pass){
		std::cout << "Return value:   " << res << std::endl;
		std::cout << "Expected value: " << ans << std::endl;
	}
	return pass;
}

template<typename T>
void TestSuite::rerun(T (*f)(void))
{
	debug = 1;
	std::cout << "Rerunning function with diagnostics..." << std::endl;
	f();
	debug = 0;
	std::cout << std::endl;
}
	

#endif
