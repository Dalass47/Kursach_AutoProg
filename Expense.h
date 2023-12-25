// Expense.h
#pragma once

#include <string>

class Expense {
private:
    std::string category;
    double amount;
    std::string date;

public:
    Expense(const std::string& category, double amount, const std::string& date);

    std::string getCategory() const;
    double getAmount() const;
    std::string getDate() const;

    void displayInfo() const;
};
