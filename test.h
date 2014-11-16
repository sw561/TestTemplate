#ifndef TEST_H
#define TEST_H

#include <string>

class TestSuite{
	public:
		TestSuite(const std::string&);
		~TestSuite();
		void test(const std::string&, bool (*f)(void));
	private:
		int count;
		int count_passed;
};

#endif
