#include "AnnualReport.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stdexcept>

AnnualReport::AnnualReport() {
    // Конструктор, если необходимо выполнить какую-то инициализацию
}

void AnnualReport::loadIncomeAndExpenses(const std::string& incomeFilename, const std::string& expensesFilename) {
    loadFromFile(incomeFilename, incomes);
    loadFromFile(expensesFilename, expenses);
}

void AnnualReport::displayAnnualReport() const {
    double totalIncome = calculateTotalAmount(incomes);
    double totalExpenses = calculateTotalAmount(expenses);
    double netProfit = totalIncome - totalExpenses;

    std::cout << "Годовой отчет:" << std::endl;
    std::cout << std::setw(25) << std::left << "Всего доходов:" << std::setw(15) << std::right << std::fixed << std::setprecision(2) << totalIncome << std::endl;
    std::cout << std::setw(25) << std::left << "Всего расходов:" << std::setw(15) << std::right << std::fixed << std::setprecision(2) << totalExpenses << std::endl;
    std::cout << std::setw(25) << std::left << "Чистая прибыль:" << std::setw(15) << std::right << std::fixed << std::setprecision(2) << netProfit << std::endl;

    // Добавим разделительную линию для улучшенного визуального восприятия
    std::cout << std::setw(40) << std::setfill('-') << "-" << std::setfill(' ') << std::endl;
}

void AnnualReport::loadFromFile(const std::string& filename, std::vector<double>& data) const {
    std::ifstream file(filename.c_str());
    if (file.is_open()) {
        data.clear();
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string field;

            // Пропускаем первое поле (Testing)
            std::getline(iss, field, ',');

            // Читаем сумму денег
            if (std::getline(iss, field, ',')) {
                try {
                    double amount = std::stod(field);
                    data.push_back(amount);
                } catch (std::invalid_argument& e) {
                    std::cerr << "Ошибка при преобразовании строки в число: " << e.what() << std::endl;
                }
            }
        }
        file.close();
    } else {
        std::cerr << "Не удалось открыть файл '" << filename << "' для чтения." << std::endl;
    }
}

double AnnualReport::calculateTotalAmount(const std::vector<double>& data) const {
    double total = 0.0;
    for (double amount : data) {
        total += amount;
    }
    return total;
}
