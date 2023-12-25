// ExpenseList.h
#pragma once

#include "Expense.h"
#include <vector>

class ExpenseList {
private:
    std::vector<Expense> expenses;

public:
    // Метод добавления расхода вручную
    void addExpenseManually();

    // Метод отображения всех расходов
    void displayExpenses() const;

    // Метод сохранения расходов в файл
    void saveExpensesToFile(const std::string& filename) const;

    // Метод загрузки расходов из файла
    void loadExpensesFromFile(const std::string& filename);

    void displayExpensesTable() const;
    double calculateTotalExpenses() const;
};
