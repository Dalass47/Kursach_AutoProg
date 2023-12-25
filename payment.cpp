
// Payment.cpp
#include "Payment.h"
#include <iostream>
#include <iomanip>

int Payment::nextOrderNumber = 1;

Payment::Payment(const std::string& description, double amount, const std::string& date, const Client& client)
    : orderNumber(nextOrderNumber++), description(description), amount(amount), date(date), client(client) {}

int Payment::getOrderNumber() const {
    return orderNumber;
}

std::string Payment::getDescription() const {
    return description;
}

double Payment::getAmount() const {
    return amount;
}

std::string Payment::getDate() const {
    return date;
}

const Client& Payment::getClient() const {
    return client;
}

void Payment::displayInfo() const {
    std::cout << std::setw(10) << std::left << orderNumber
              << std::setw(20) << std::left << description
              << std::setw(15) << std::right << amount
              << std::setw(15) << std::right << date << std::endl;
}
