#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>

enum Type
{
    BREAKFAST, DINNER, CAR_RENTAL
};

class Expense
{
public:
    Type type;
    int amount;
    bool isOverLimit() const;
    std::string getName() const;
    bool isMeal() const;
};

#endif
