TestTemplate
============

Template Files for writing code which includes tests and run-time determined parameters which are accessible throughout the program. There are also run-time and compile-time debug options. In addition python scripts are provided for easy testing, running and parameter sampling including checks for previously computed data and previously generated plots.

demo.h and demo.cpp demonstrate how to write your code which requires testing. Exceptions should inherit from std::exception. Functions for debugging purposes should be called using a macro as demonstrated. demo_test.cpp explains how to write and call the tests using the TestSuite class (in test.cpp). Note that if your file names do not begin with "demo" then you will need to update the sources variable in "Makefile" to reflect this. 

debug.h test.h and test.cpp are generic. The preprocessor definition "DEBUG" in debug.h can be commented out, if you want to remove debug options at compile time.

parameter.h and parameter.cpp are also generic. They define the parameters of your program using the variables in param_list.txt which have to be written in the format "%type %name %value", where value is the default value. This is done using automatic code generation (generate.py) and preprocessor include directives. The values can be altered after compilation using an input file. demo.cpp and main.cpp both demonstrate how these parameters can be accessed within your program.

main.cpp contains the program's main function; it calls the functions in demo.cpp and defines a global variable 'debug'.

The executable "main" takes up to three arguments. The first argument is compulsory and specifies the output file. The second argument is optional (defualt is 0) and specifies the debug variable. If it is greater than zero the run-time diagnostic function(s) will be run for every function call. Note that if debugging has been switched off at compile time (by removing the preprocessor variable DEBUG in debug.h), this second variable will do nothing. The final argument is also optional and specifies the input file which is used to update variables in the parameter class. If no input file is given, then the default parameter values from param_list.txt are used.

The python script test.py compiles and runs the tests. It will compile and run "name_test" for each command line argument "name". If no arguments are given it will run all the tests whose names are specified in the code.

Finally the class in program.py allows the user to run the program with a range of parameters, as demonstrated in script.py. The parameters which need to be modified from the default values and their names (which must match the names used in the c++ program) are stored in a dictionary. The Program class in program.py then creates an input file with the given parameters, and calls the program with the input file. The data can then be retrieved for post-computation analysis using the data(self) method.

Note that the python scripts will also check if the particular set of parameters has been used before, and will retrieve the previously computed data if it is available. This feature can be overridden by setting the argument overwrite to "True". The wrapper function in analysis.py provides a similar functionality; it will not re-plot data if the plots already exist.
