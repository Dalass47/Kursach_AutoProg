// ExpenseList.cpp
#include "ExpenseList.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stdexcept>  // �� �������� �������� ���� ������������ ����
#include <ctime>



void ExpenseList::addExpenseManually() {
    std::string category;
    double amount;
    std::string dateStr;

    std::cout << "������� ��������� �������: ";
    std::cin >> category;

    std::cout << "������� ����� �������: ";
    std::cin >> amount;

    std::cout << "������� ���� ������� � ������� DD-MM-YYYY: ";
    std::cin >> dateStr;

    Expense expense(category, amount, dateStr);
    expenses.push_back(expense);
}

void ExpenseList::displayExpensesTable() const {
    // ����� ������� ������� �������
    std::cout << std::setw(40) << std::setfill('-') << "-" << std::setfill(' ') << std::endl;

    // ����� ��������� �������
    std::cout << std::setw(15) << std::left << "| ���������"
              << std::setw(10) << std::right << "| �����"
              << std::setw(15) << std::right << "| ���� |" << std::endl;

    // ����� �������������� ����� ����� ���������� � �������
    std::cout << std::setw(40) << std::setfill('-') << "-" << std::setfill(' ') << std::endl;

    // ����� ����� �������
    for (const auto& expense : expenses) {
        std::cout << std::setw(15) << std::left << "| " + expense.getCategory()
                  << std::setw(10) << std::right << "| " + std::to_string(expense.getAmount())
                  << std::setw(15) << std::right << "| " + expense.getDate() + " |" << std::endl;
    }

    // ����� ������ ������� �������
    std::cout << std::setw(40) << std::setfill('-') << "-" << std::setfill(' ') << std::endl;
}

void ExpenseList::saveExpensesToFile(const std::string& filename) const {
    std::ofstream file(filename.c_str());
    if (file.is_open()) {
        for (const auto& expense : expenses) {
            file << expense.getCategory() << "," << expense.getAmount() << "," << expense.getDate() << std::endl;
        }
        file.close();
        std::cout << "������ �������� �������� � ����." << std::endl;
    } else {
        std::cerr << "�� ������� ������� ���� ��� ������." << std::endl;
    }
}

void ExpenseList::loadExpensesFromFile(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (file.is_open()) {
        expenses.clear();
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string category;
            std::string amountStr;
            std::string dateStr;

            if (std::getline(iss, category, ',') &&
                std::getline(iss, amountStr, ',') &&
                std::getline(iss, dateStr)) {

                try {
                    // �������������� ������ � double
                    double amount = std::stod(amountStr);
                    // �������� Expense � ����������� �����
                    Expense expense(category, amount, dateStr);
                    expenses.push_back(expense);
                } catch (std::invalid_argument& e) {
                    std::cerr << "������ ��� �������������� ������ � �����: " << e.what() << std::endl;
                }
            }
        }
        file.close();
        std::cout << "������ �������� �������� �� �����." << std::endl;
    } else {
        std::cerr << "�� ������� ������� ���� ��� ������." << std::endl;
    }
}

double ExpenseList::calculateTotalExpenses() const {
    double totalExpenses = 0.0;
    for (const auto& expense : expenses) {
        totalExpenses += expense.getAmount();
    }
    return totalExpenses;
}
