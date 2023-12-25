// PaymentList.h
#pragma once

#include <vector>
#include <string>
#include "ClientList.h"
#include "Payment.h"


class PaymentList {
private:
    std::vector<Payment> payments;
    ClientList clientList;

public:
    void addPaymentManually();
    void displayPaymentsTable() const;
    void savePaymentsToFile(const std::string& filename) const;
    void loadPaymentsFromFile(const std::string& filename, const std::string& clientsFilename);
    double calculateTotalIncome() const;
};
