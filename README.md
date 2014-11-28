TestTemplate
============

Template Files for writing code which includes tests, run-time parameters and run-time debug options.

The files beginning with "demo" demonstrate how to structure the code which requires testing. Note that if your files do not begin with "demo" then you will need to update the sources variable in "Makefile" to reflect this.

demo.cpp contains the functions which require testing, and diagnosis functions to be run if run-time checking is required. demo_test.cpp defines and calls a collection of functions and reports on which ones behave as expected or otherwise.

debug.h test.h and test.cpp are generic and can be copied to your real project without editing.

parameter.h and parameter.cpp define the parameters of your program. They need to be declared in parameter.h. In the constructor of the parameter class, you can store the default values for these parameters. The process_arg() function is written with the help of macros, and tells the program how to interpret the input file in order to update any parameters.

main.cpp is for your actual program, it calls the functions in demo.cpp and defines a global variable 'debug'.

There are two bash scripts for convenience that demonstrate how to compile and run the program and the tests respectively.

./run.sh compiles and runs the program and takes up to three arguments. The first argument is compulsory and specifies the output file. The second argument is optional (defualt is 0) and specifies the debug variable. If it is greater than zero the run-time diagnostic function(s) will be run for every function call. The final argument is also optional and specifies the input file which is used to update variables in the parameter class. If no input file is given, then the default parameter values in parameter.cpp are used.

./test.sh compiles and runs the test script.

Finally script.py allows the user to call the program with a range of parameters. The parameters which need to be modified from the default values and their names (which must match the names used in the c++ program) are stored in a dictionary. The Program class in program.py then creates an input file with the given parameters, and calls the program with the given input file. The data can then be retrieved for post-computation analysis using the data(self) method.

Note that the Program class will also check if the particular set of parameters has been used before, and will retrieve the previously computed data if that is available.
