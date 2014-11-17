#ifndef TEST_H
#define TEST_H

#include <string>
#include <iostream>

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
		void test(const std::string&, const T&, const T&);

		// Printing values
		template<typename T>
		void print(const T&, const T&);
		
	private:
		int count;
		int count_passed;
};

template<typename T>
void TestSuite::test(const std::string &s, T (*f)(void), const T &ans)
{
	test(s,f(),ans);
}

template<typename T>
void TestSuite::test(const std::string &s, const T &res, const T &ans)
{
	bool pass = ( res==ans );
	test(s,pass);
	if (!pass) {print(res,ans);}
}

template<typename T>
void TestSuite::print(const T &res, const T &ans)
{
	std::cout << "Return value:   " << res << std::endl;
	std::cout << "Expected value: " << ans << std::endl << std::endl;
}

#endif
