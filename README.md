TestTemplate
============

Template Files for writing code which includes tests and debug options.

demo.cpp contains the functions which require testing, and the functions to be run if run-time checking is required (names begin with "diagnose_"). demo_test.cpp defines and calls a collection of functions which will return true if the functions behave as expected, or false otherwise.

main.cpp is where the functions in demo.cpp would actually be used in a real project.

debug.h test.h and test.cpp are generic and do not need to be edited for use in a real project.

There are two bash scripts for convenience that compile and run the code automatically.

./run.sh runs the program and takes an optional argument. If there is no argument or the argument is 0, then no diagnostics are run in the code. Otherwise checks will be run for every function call.

./test.sh runs the test scripts and reports which tests passed or failed.
