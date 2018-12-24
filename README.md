# graph_in_pgm
c++ module to make a graph of *.pgm image format from c++ mathematical expression in one variable.

run the following commands

$ git clone http://github.com/kunaltawatia/graph_in_pgm

$ cd graph_in_pgm

$ chmod +x run.sh

$ ./run.sh

Now files are ready to be used...

To make it work go into define_method and run command in the following syntax and make sure the expression is readable by c++ compilers and only in x variable.

$ ./main "x*cos(x)" 

To test stack_method go into it and run commands (only polynomials are allowed)

$ ./graph "x* x - 2* x + 1"
or
$./graph "x* x* x"
