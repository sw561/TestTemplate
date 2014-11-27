TestTemplate
============

Template Files for writing code which includes tests, run-time parameters and run-time debug options.

The files beginning with "demo" demonstrate how to structure the code which requires testing. Note that if your files do not begin with "demo" then you will need to update the sources variable in "Makefile" to reflect this.

demo.cpp contains the functions which require testing, and diagnosis functions to be run if run-time checking is required. demo_test.cpp defines and calls a collection of functions and reports on which ones behave as expected or otherwise.

main.cpp is for your actual program, it calls the functions in demo.cpp and defines a global variable 'debug'.

debug.h test.h and test.cpp are generic and can be copied to your real project without editing.

parameter.h and parameter.cpp define the parameters of your program. They need to be declared in parameter.h. In the constructor of the parameter class, you can store the default values for these parameters. The process_arg() function is written with the help of macros, and tells the program how to interpret an input file in order to update any of those parameters.

There are two bash scripts for convenience that demonstrate how to compile and run the program and the tests respectively.

./run.sh compiles and runs the program and takes three optional argument. The first argument specifies the debug variable. If it is greater than zero the run-time diagnostic function(s) will be run for every function call. The second variable specifies the input file which is used to update variables in the parameter class. The third variable is the name of an output file.

./test.sh compiles and runs the test script.
