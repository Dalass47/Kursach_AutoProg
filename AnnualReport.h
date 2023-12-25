#ifndef ANNUALREPORT_H
#define ANNUALREPORT_H

#include <vector>
#include <string>

class AnnualReport {
public:
    AnnualReport();

    void loadIncomeAndExpenses(const std::string& incomeFilename, const std::string& expensesFilename);
    void displayAnnualReport() const;

private:
    std::vector<double> incomes;
    std::vector<double> expenses;

    void loadFromFile(const std::string& filename, std::vector<double>& data) const;
    double calculateTotalAmount(const std::vector<double>& data) const;
};

#endif // ANNUALREPORT_H
