#include "clientinterface.h"
#include <cstdlib> // Для использования функции system
#include <limits>

void ClientInterface::ClientInt() {
    setlocale(LC_ALL, "");
    int choice1 = 0;
    clientList.loadFromFile("clients.txt");

    while (true) {
        system("cls"); // Очистка экрана (Windows)
        std::cout << "AutoProg Работа с клиентами:\n";
        std::cout << "1. Ввести клиента\n";
        std::cout << "2. Список всех клиентов\n";
        std::cout << "3. Поиск клиента\n";
        std::cout << "9. Назад\n";

        std::cin >> choice1;

        switch (choice1) {
            case 1:
                clientList.addClientManually();
                clientList.saveToFile("clients.txt");
                break;
            case 2:
                clientList.displayClients();
                std::cout << "Нажмите Enter для продолжения...";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.get();
                break;
            case 3:{
                std::string SName;
                std::cout << "Введите фамилию клиента для поиска: ";
                std::cin >> SName;
                clientList.searchClientBySName(SName);
                std::cout << "Нажмите Enter для продолжения...";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.get();
                break;}
            case 9:
                return;  // Возврат из метода, если пользователь выбрал "Назад"
            default:
                std::cout << "Выберите пункт\n";
        }
    }
}
