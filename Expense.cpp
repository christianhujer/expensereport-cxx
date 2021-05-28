#include "Expense.h"

bool Expense::isOverLimit() const {
    return (type == DINNER && amount > 5000) ||
           (type == BREAKFAST && amount > 1000);
}

std::string Expense::getName() const
{
    switch (type) {
        case DINNER:
            return "Dinner";
        case BREAKFAST:
            return "Breakfast";
        case CAR_RENTAL:
            return "Car Rental";
        default:
            return "";
    }
}

bool Expense::isMeal() const
{
    return type == BREAKFAST || type == DINNER;
}

