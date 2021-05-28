#include "catch.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include "ExpenseReport.h"

TEST_CASE("empty expense report") {
    std::list<Expense> emptyList;
    std::string expected = "Expenses Fri May 21 11:00:00 2021\n"
                      "Meal expenses: 0\n"
                      "Total expenses: 0\n";
    std::stringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());
    printReport(emptyList, "Fri May 21 11:00:00 2021");
    std::string actual = buffer.str();
    std::cout.rdbuf(old);
    REQUIRE(expected == actual);
}

TEST_CASE("characterization test of original behavior") {
    std::list<Expense> expenses;
    expenses.push_back(Expense { BREAKFAST, 1000 });
    expenses.push_back(Expense { BREAKFAST, 1001 });
    expenses.push_back(Expense { DINNER, 5000 });
    expenses.push_back(Expense { DINNER, 5001 });
    expenses.push_back(Expense { CAR_RENTAL, 3000 });
    std::string expected = "Expenses Fri May 21 11:00:00 2021\n"
                           "Breakfast\t1000\t \n"
                           "Breakfast\t1001\tX\n"
                           "Dinner\t5000\t \n"
                           "Dinner\t5001\tX\n"
                           "Car Rental\t3000\t \n"
                           "Meal expenses: 12002\n"
                           "Total expenses: 15002\n";
    std::stringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());
    printReport(expenses, "Fri May 21 11:00:00 2021");
    std::string actual = buffer.str();
    std::cout.rdbuf(old);
    REQUIRE(expected == actual);
}
