CC = g++

CFLAGS = -std=gnu++11 -Wall -pedantic -Wold-style-cast -Woverloaded-virtual -g

TARGET = Calculator.cc Expression.cc Operator.cc Operand.cc

TEST = test1 test2

calculator: Calculator.o Expression.o Operator.o Operand.o
	$(CC) $(CFLAGS) $^ -o $@

Calculator.o: Calculator.cc
	$(CC) $(CFLAGS) -c Calculator.cc

Expression.o: Expression.cc
	$(CC) $(CFLAGS) -c Expression.cc

Operator.o: Operator.cc
	$(CC) $(CFLAGS) -c Operator.cc

Operand.o: Operand.cc
	$(CC) $(CFLAGS) -c Operand.cc

#

check:  calculator
	./calculator

test: calculator
	./calculator Input/$(INPUT)

# make sure that 'clean' or TEST is not run accidentally
.PHONY: clean 

clean:
	\rm *.o calculator
