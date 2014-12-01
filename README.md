TestTemplate
============

Template Files for writing code which includes tests and run-time determined parameters which are accessible throughout the program. There are also run-time and compile-time options. In addition python scripts are provided for easy testing, running and parameter sampling.

demo.h and demo.cpp demonstrate how to write your code which requires testing. Exceptions should inherit from std::exception. Functions which you want to be called only when debugging should be called using a macro as shown. demo_test.cpp explains how to write and call the tests using the TestSuite class (in test.cpp). Note that if your file names do not begin with "demo" then you will need to update the sources variable in "Makefile" to reflect this. 

debug.h test.h and test.cpp are generic and can be copied to your real project without editing. The preprocessor definition "DEBUG" in debug.h can be commented out, if you want to remove debug options at compile time.

parameter.h and parameter.cpp define the parameters of your program. They need to be declared in parameter.h. In the constructor of the parameter class, you can store the default values for these parameters. The process_arg() function is written with the help of macros, and tells the program how to interpret the input file in order to update any parameters. demo.cpp and main.cpp both demonstrate how these parameters can be accessed within your program.

main.cpp contains the program's main function; it calls the functions in demo.cpp and defines a global variable 'debug'.

The executable "main" takes up to three arguments. The first argument is compulsory and specifies the output file. The second argument is optional (defualt is 0) and specifies the debug variable. If it is greater than zero the run-time diagnostic function(s) will be run for every function call. Note that if debugging has been switched off at compile time (by removing the preprocessor variable DEBUG in debug.h), this second variable will do nothing. The final argument is also optional and specifies the input file which is used to update variables in the parameter class. If no input file is given, then the default parameter values in parameter.cpp are used.

The python script test.py compiles and runs the tests. It will compile and run "name_test" for each command line argument "name". If no arguments are given it will run all the tests as specified in the code. run.py will compile and run the program with the default output file "Data/out.txt". Debugging can be switched on by passing a command line argument greater than zero.

Finally script.py allows the user to run the program with a range of parameters. The parameters which need to be modified from the default values and their names (which must match the names used in the c++ program) are stored in a dictionary. The Program class in program.py then creates an input file with the given parameters, and calls the program with the given input file. The data can then be retrieved for post-computation analysis using the data(self) method.

Note that the Program class will also check if the particular set of parameters has been used before, and will retrieve the previously computed data if that is available. This feature can be deactivated by constructing the Program instance with overwrite set to true.
