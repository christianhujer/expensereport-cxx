CPPFLAGS:=-MMD
CXXFLAGS:=-W -Wall -pedantic -Werror

.PHONY: all
all: ExpenseReport.o

.PHONY: clean
clean::
	$(RM) *.[adios]

-include *.d
