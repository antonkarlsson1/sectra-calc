# Sectra Calc

A relatively simple calculator built with an object oriented approach. Supports the operations add, subtract and multiply with lazy evaluation.

## Setup

### Compile

How to compile the program


-   Compiling on Windows:

    -   g++ -std=gnu++11 -Wall Calculator.cc Expression.cc Operator.cc Operand.cc -o calculator.exe

-   Compiling on Linux:

    -   make            -   Compiles the program

    -   make clean   -   Cleans up the repository by removing .o files and executables


### Running the calculator

-   Run on Windows:

     Read from the standard input:

    -   calculator.exe

     Read from a textfile:

    -   calculator.exe [filepath]

-   Run on Linux:


     Read from standard input:

    -   make check                                    -   Compiles and runs the executable

         or

    -   calculator

     Read from textfile:

    -   make test INPUT="filename"      -       Compiles and runs the executable with "filename" as argument. The file must be put into the folder "Input".

         or

    -   calculator [filepath]

## Limitations & Assumptions

-   Assumes the input is on the form [Register] [Operation] [Value] where:
    
     [Register]   -   Word/character that consists of atleast 1 non-digit.  

     [Operation] supports the following:
     -  Add
     -  Subtract
     -  Multiplication

     [Value]    -   Can be either an integer, double or a Register as described above.

-   The calculator supports all numbers that can be fit into 32-bits.

-   The calculator is case-insensitive

-   Supports operations on the form:
      - A add 1
      - A add A
    
     In this specific case A will be updated to the value 2.

- Cycles
     If there are cycles on the form:
     -  A add B
     -  B add A
     -  A add 1

     My calculator throws an exception and further makes those registers unable to be evaluated.

-   Classes can be easily expanded for further implementation of new operators and operands.
