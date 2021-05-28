#include <chrono>
#include <iostream>
#include <iterator>
#include "ExpenseReport.h"

using namespace std;

void printReportHeader(const char *time);
void printReportBody(list<Expense> &expenses);
void printDetail(const Expense &expense);
const char *getOverExpenseLimitMarker(const Expense &expense);
void printReportSummary(list<Expense> &expenses);
int sumMealExpenses(list<Expense> &expenses);
int sumTotalExpenses(list<Expense> &expenses);

bool isMeal(const Expense &expense);

void printReport(list<Expense> expenses)
{
    auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());
    const char *time = ctime(&now);
    printReport(expenses, time);
}

void printReport(list<Expense> &expenses, const char *time)
{
    printReportHeader(time);
    printReportBody(expenses);
    printReportSummary(expenses);
}

void printReportHeader(const char *time)
{
    cout << "Expenses " << time << '\n';
}

void printReportBody(list<Expense> &expenses)
{
    for (auto & expense : expenses)
        printDetail(expense);
}

void printDetail(const Expense &expense)
{
    string expenseName = expense.getName();
    string overExpenseLimitMarker = getOverExpenseLimitMarker(expense);
    cout << expenseName << '\t' << expense.amount << '\t' << overExpenseLimitMarker << '\n';
}

const char *getOverExpenseLimitMarker(const Expense &expense)
{
    return expense.isOverLimit() ? "X" : " ";
}

void printReportSummary(list<Expense> &expenses)
{
    cout << "Meal expenses: " << sumMealExpenses(expenses) << '\n';
    cout << "Total expenses: " << sumTotalExpenses(expenses) << '\n';
}

int sumMealExpenses(list<Expense> &expenses)
{
    int mealExpenses = 0;
    for (auto & expense : expenses)
        if (expense.isMeal())
            mealExpenses += expense.amount;
    return mealExpenses;
}

int sumTotalExpenses(list<Expense> &expenses)
{
    int total = 0;
    for (auto & expense : expenses)
        total += expense.amount;
    return total;
}
