
#include "PaymentList.h"
#include <iostream>
#include <limits>
#include <PaymentInterface.h>
//#include "AnnualReport.h"
#include "ExpenseList.h"

void PaymentInterface::PaymentInt() {
    int choice4 = 0;

    PaymentList paymentList;





    paymentList.loadPaymentsFromFile("payments.txt", "clients.txt");

    while (true) {
        system("cls");
        std::cout << "AutoProg ������ � ��������:\n";
        std::cout << "1. �������� �����\n";
        std::cout << "2. ������� ��� ������\n";
        std::cout << "9. �����\n";

        std::cin >> choice4;


        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice4) {
            case 1:
            paymentList.addPaymentManually();
                paymentList.savePaymentsToFile("payments.txt");
            break;


            case 2:
            system("cls");
                paymentList.displayPaymentsTable();
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
