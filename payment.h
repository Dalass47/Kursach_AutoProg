#ifndef PAYMENT
#define PAYMENT

#endif // PAYMENT

// Payment.h
#pragma once

#include <string>
#include "Client.h"

class Payment {
private:
    static int nextOrderNumber;
    int orderNumber;
    std::string description;
    double amount;
    std::string date;
    Client client;

public:
    Payment(const std::string& description, double amount, const std::string& date, const Client& client);

    int getOrderNumber() const;
    std::string getDescription() const;
    double getAmount() const;
    std::string getDate() const;
    const Client& getClient() const;

    void displayInfo() const;
};
