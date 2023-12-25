// ExpenseList.cpp
#include "ExpenseList.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stdexcept>  // Не забудьте добавить этот заголовочный файл
#include <ctime>



void ExpenseList::addExpenseManually() {
    std::string category;
    double amount;
    std::string dateStr;

    std::cout << "Введите категорию расхода: ";
    std::cin >> category;

    std::cout << "Введите сумму расхода: ";
    std::cin >> amount;

    std::cout << "Введите дату расхода в формате DD-MM-YYYY: ";
    std::cin >> dateStr;

    Expense expense(category, amount, dateStr);
    expenses.push_back(expense);
}

void ExpenseList::displayExpensesTable() const {
    // Вывод верхней границы таблицы
    std::cout << std::setw(40) << std::setfill('-') << "-" << std::setfill(' ') << std::endl;

    // Вывод заголовка таблицы
    std::cout << std::setw(15) << std::left << "| Категория"
              << std::setw(10) << std::right << "| Сумма"
              << std::setw(15) << std::right << "| Дата |" << std::endl;

    // Вывод разделительной линии между заголовком и данными
    std::cout << std::setw(40) << std::setfill('-') << "-" << std::setfill(' ') << std::endl;

    // Вывод строк таблицы
    for (const auto& expense : expenses) {
        std::cout << std::setw(15) << std::left << "| " + expense.getCategory()
                  << std::setw(10) << std::right << "| " + std::to_string(expense.getAmount())
                  << std::setw(15) << std::right << "| " + expense.getDate() + " |" << std::endl;
    }

    // Вывод нижней границы таблицы
    std::cout << std::setw(40) << std::setfill('-') << "-" << std::setfill(' ') << std::endl;
}

void ExpenseList::saveExpensesToFile(const std::string& filename) const {
    std::ofstream file(filename.c_str());
    if (file.is_open()) {
        for (const auto& expense : expenses) {
            file << expense.getCategory() << "," << expense.getAmount() << "," << expense.getDate() << std::endl;
        }
        file.close();
        std::cout << "Список расходов сохранен в файл." << std::endl;
    } else {
        std::cerr << "Не удалось открыть файл для записи." << std::endl;
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
                    // Преобразование строки в double
                    double amount = std::stod(amountStr);
                    // Создание Expense с прочитанной датой
                    Expense expense(category, amount, dateStr);
                    expenses.push_back(expense);
                } catch (std::invalid_argument& e) {
                    std::cerr << "Ошибка при преобразовании строки в число: " << e.what() << std::endl;
                }
            }
        }
        file.close();
        std::cout << "Список расходов загружен из файла." << std::endl;
    } else {
        std::cerr << "Не удалось открыть файл для чтения." << std::endl;
    }
}

double ExpenseList::calculateTotalExpenses() const {
    double totalExpenses = 0.0;
    for (const auto& expense : expenses) {
        totalExpenses += expense.getAmount();
    }
    return totalExpenses;
}
