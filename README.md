TestTemplate
============

Template Files for writing code which includes tests and debug options.

The files beginning with "demo" demonstrate how to structure the code which requires testing. Note that if your files do not begin with "demo" then you will need to update the sources variable in "Makefile" to reflect this.

demo.cpp contains the functions which require testing, and diagnosis functions to be run if run-time checking is required. demo_test.cpp defines and calls a collection of functions and reports on which ones behave as expected or otherwise.

main.cpp is for your actual program, it calls the functions in demo.cpp and defines a global variable 'debug'.

debug.h test.h and test.cpp are generic and can be copied to your real project without editing.

There are two bash scripts for convenience that demonstrate how to compile and run the program and the tests respectively.

./run.sh compiles and runs the program and takes an optional argument. If there is no argument or the argument is 0, then no diagnostics are run in the code. Otherwise the corresponging diagnostic function(s) will be run for every function call.

./test.sh compiles and runs the test script.
