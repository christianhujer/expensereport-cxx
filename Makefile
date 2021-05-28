CPPFLAGS:=-MMD
CXXFLAGS:=-W -Wall -pedantic -Werror

.PHONY: all
all: test_main
	./test_main

test_main: CC:=g++
test_main: test_main.o test_ExpenseReport.o Expense.o ExpenseReport.o

test_main.o: catch.hpp

catch.hpp:
	wget https://raw.githubusercontent.com/catchorg/Catch2/v2.x/single_include/catch2/catch.hpp

.PHONY: clean
clean::
	$(RM) *.[adios]

-include *.d
