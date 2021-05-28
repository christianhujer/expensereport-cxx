#ifndef EXPENSEREPORT_H
#define EXPENSEREPORT_H

#include <list>
#include "Expense.h"

extern void printReport(std::list<Expense> expenses);
extern void printReport(std::list<Expense> &expenses, const char *time);

#endif
