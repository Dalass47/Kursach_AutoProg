
#include <iostream>
#include <interface.h>
#include <clientinterface.h>
//#include <expenditureinterface.h>
#include <Paymentinterface.h>
//#include "AnnualReport.h"
#include <limits>



void Interface::UserInterface() {
    setlocale(LC_ALL, "");
    int choice = 0;
    bool exitProgramm = false;
    ClientInterface inter;
    //ExpenditureInterface expenditureInter;
    PaymentInterface PInter;
    //AnnualReport annualReport;


    while (!exitProgramm) {
        std::cout << "AutoProg ����������:\n";
        std::cout << "1. ������ � ��������� \n";
        std::cout << "2. ������ � ������ \n";
        std::cout << "3. ������ � ��������� \n";
        std::cout << "4. ������� ������� ����� \n";
        std::cout << "9. ����� �� ��������� \n";

        std::cin >> choice;
        switch (choice) {
            case 1:
                inter.ClientInt();
                break;

            case 2:
                PInter.PaymentInt();
                break;
            case 3:
               // expenditureInter.processChoice();
                std::cin >> choice;

                break;
            case 4:{
                system("cls");
               // annualReport.loadIncomeAndExpenses("payments.txt", "expenses.txt");
                //annualReport.displayAnnualReport();
                std::cout << "������� Enter ��� �����������...";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;}
            case 9:
                exitProgramm = true;
                break;
            default:
                std::cout << "�������� �����\n";
                continue;
        }


    }

}
