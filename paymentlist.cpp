
// PaymentList.cpp
#include "paymentlist.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <limits>


void PaymentList::addPaymentManually() {
    std::string description;
    double amount;
    std::string date;

    std::cout << "������� �������� ������: "; // ���������� ���������� ������ ����� ������
    std::getline(std::cin, description);

    std::cout << "������� ����� ������: ";
    std::cin >> amount;


    std::cout << "������� ���� ������ � ������� DD-MM-YYYY: ";
    std::cin >> date;

    std::string clientName;
    Client client;

    std::cout << "������� ��� ���������: ";
    std::cin >> clientName;

    try {
        client = clientList.getClientByName(clientName);
        if (client.getName().empty()) {
            // ���� ��� ������� ������, ��� ��������, ��� ������ �� ��� ������
            std::cerr << "������� � ������ '" << clientName << "' �� ����������. ������� � ����." << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ����������� ������
            std::cin.get();  // ����������� ������
            return;
        }
    } catch (std::runtime_error& e) {
        std::cerr << "������: " << e.what() << std::endl;
        // ���� ��������� ������ ��� ������ �������, ����� ������� ��������� � ������������ � ����
        std::cerr << "������� � ����." << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ����������� ������
        std::cin.get();  // ����������� ������
        return;
    }

    Payment payment(description, amount, date, client);
    payments.push_back(payment);
    std::cout << "������ ������� ���������." << std::endl;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ����������� ������
    std::cin.get();  // ����������� ������
}


void PaymentList::displayPaymentsTable() const {
    std::cout << std::setw(80) << std::setfill('-') << "-" << std::setfill(' ') << std::endl;
    std::cout << std::setw(10) << std::left << "| � ������"
              << std::setw(15) << std::right << "| �����"
              << std::setw(25) << std::left << "| �������� ������"
              << std::setw(15) << std::right << "| ���� ������"
              << std::setw(15) << std::right << "| ��� ���������" << std::endl;
    std::cout << std::setw(80) << std::setfill('-') << "-" << std::setfill(' ') << std::endl;

    for (const auto& payment : payments) {
        std::cout << std::setw(10) << std::left << payment.getOrderNumber()
                  << std::setw(15) << std::right << payment.getAmount()
                  << std::setw(25) << std::right << payment.getDescription()
                  << std::setw(15) << std::right << payment.getDate()
                  << std::setw(15) << std::right << payment.getClient().getName() << std::endl;
    }

    std::cout << std::setw(80) << std::setfill('-') << "-" << std::setfill(' ') << std::endl;
}

void PaymentList::savePaymentsToFile(const std::string& filename) const {
    std::ofstream file(filename.c_str());
    if (file.is_open()) {
        for (const auto& payment : payments) {
            file << payment.getOrderNumber() << "," << payment.getAmount() << ","
                 << payment.getDescription() << "," << payment.getDate() << ","
                 << payment.getClient().getName() << std::endl;
        }
        file.close();
        std::cout << "������ ����� �������� � ����." << std::endl;
    } else {
        std::cerr << "�� ������� ������� ���� ��� ������." << std::endl;
    }
}

void PaymentList::loadPaymentsFromFile(const std::string& filename, const std::string& clientsFilename) {
    clientList.loadFromFile(clientsFilename);

    std::ifstream file(filename.c_str());
    if (file.is_open()) {
        payments.clear();
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string orderNumberStr;
            std::string amountStr;
            std::string description;
            std::string dateStr;
            std::string clientName;


            Client client;
            double amount;


            try {
                if (!(std::getline(iss, orderNumberStr, ',') &&
                      std::getline(iss, amountStr, ',') &&
                      std::getline(iss, description, ',') &&
                      std::getline(iss, dateStr, ',') &&
                      std::getline(iss, clientName))) {
                    // ���� �� ������� ������� ��� ����, ������� �� ����������� �����
                    continue;
                }

                amount = std::stod(amountStr);


                client = clientList.getClientByName(clientName);


            } catch (std::invalid_argument& e) {
                std::cerr << "������ ��� �������������� ������ � �����: " << e.what() << std::endl;

                continue; // ���������� ������� ������ � ��������� � ���������
            }

            Payment payment(description, amount, dateStr, client);
            payments.push_back(payment);
        }

        file.close();
        std::cout << "������ ����� �������� �� �����." << std::endl;
    } else {
        std::cerr << "�� ������� ������� ���� ��� ������." << std::endl;
    }
}

double PaymentList::calculateTotalIncome() const {
    double totalIncome = 0.0;
    for (const auto& payment : payments) {
        totalIncome += payment.getAmount();
    }
    return totalIncome;
}
