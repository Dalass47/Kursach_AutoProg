#include "clientinterface.h"
#include <cstdlib> // ��� ������������� ������� system
#include <limits>

void ClientInterface::ClientInt() {
    setlocale(LC_ALL, "");
    int choice1 = 0;
    clientList.loadFromFile("clients.txt");

    while (true) {
        system("cls"); // ������� ������ (Windows)
        std::cout << "AutoProg ������ � ���������:\n";
        std::cout << "1. ������ �������\n";
        std::cout << "2. ������ ���� ��������\n";
        std::cout << "3. ����� �������\n";
        std::cout << "9. �����\n";

        std::cin >> choice1;

        switch (choice1) {
            case 1:
                clientList.addClientManually();
                clientList.saveToFile("clients.txt");
                break;
            case 2:
                clientList.displayClients();
                std::cout << "������� Enter ��� �����������...";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.get();
                break;
            case 3:{
                std::string SName;
                std::cout << "������� ������� ������� ��� ������: ";
                std::cin >> SName;
                clientList.searchClientBySName(SName);
                std::cout << "������� Enter ��� �����������...";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.get();
                break;}
            case 9:
                return;  // ������� �� ������, ���� ������������ ������ "�����"
            default:
                std::cout << "�������� �����\n";
        }
    }
}
