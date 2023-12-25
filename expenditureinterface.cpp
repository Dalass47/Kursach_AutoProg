#include "expenditureinterface.h"
#include "ExpenseList.h"
#include <iostream>
#include <limits>

void ExpenditureInterface::processChoice() {
    int choice3 = 0;
    ExpenseList expenseList; // �������� �� ����������� ���� � ��� �����
    expenseList.loadExpensesFromFile("expenses.txt");


    while (true) {
        system("cls");
        std::cout << "AutoProg ������ � ���������:\n";
        std::cout << "1. �������� ������\n";
        std::cout << "2. ������� ��� �������\n";
        std::cout << "9. �����\n";

        std::cin >> choice3;


        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice3) {
            case 1:
                expenseList.addExpenseManually();
                expenseList.saveExpensesToFile("expenses.txt");
                break;

            case 2:
                system("cls");
                expenseList.displayExpensesTable();
                std::cout << "������� Enter ��� �����������...";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;

            case 9:
                return;
            default:
                std::cout << "�������� �����\n";
        }
    }
}
