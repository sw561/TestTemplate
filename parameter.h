#ifndef PARAMETER_H
#define PARAMETER_H

#include <string>

class Parameter{
	public:
		static const Parameter * inst(const std::string &s){
			static const Parameter * p_ptr = new Parameter(s);
			return p_ptr;
		}
		static const Parameter * inst(){
			static const Parameter * p_ptr = inst("input.txt");
			return p_ptr;
		}
		int a;
		int b;
		double factor;
	private:
		Parameter(const std::string&);
		void process_arg(const std::string&, const double);
};

struct ParameterNotFound {};


#endif
