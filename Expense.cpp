// Expense.cpp
#include "Expense.h"
#include <iostream>
#include <iomanip>

Expense::Expense(const std::string& category, double amount, const std::string& date)
    : category(category), amount(amount), date(date) {}

std::string Expense::getCategory() const {
    return category;
}

double Expense::getAmount() const {
    return amount;
}

std::string Expense::getDate() const {
    return date;
}

void Expense::displayInfo() const {
    std::cout << std::setw(15) << std::left << category
              << std::setw(10) << std::right << amount
              << std::setw(12) << std::right << date << std::endl;
}
