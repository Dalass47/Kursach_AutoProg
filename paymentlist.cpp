
// PaymentList.cpp
#include "paymentlist.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <limits>


void PaymentList::addPaymentManually() {
    std::string description;
    double amount;
    std::string date;

    std::cout << "Введите описание заказа: "; // Игнорируем предыдущий символ новой строки
    std::getline(std::cin, description);

    std::cout << "Введите сумму оплаты: ";
    std::cin >> amount;


    std::cout << "Введите дату оплаты в формате DD-MM-YYYY: ";
    std::cin >> date;

    std::string clientName;
    Client client;

    std::cout << "Введите имя заказчика: ";
    std::cin >> clientName;

    try {
        client = clientList.getClientByName(clientName);
        if (client.getName().empty()) {
            // Если имя клиента пустое, это означает, что клиент не был найден
            std::cerr << "Клиента с именем '" << clientName << "' не существует. Возврат в меню." << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Добавленная строка
            std::cin.get();  // Добавленная строка
            return;
        }
    } catch (std::runtime_error& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        // Если произошла ошибка при поиске клиента, также выводим сообщение и возвращаемся в меню
        std::cerr << "Возврат в меню." << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Добавленная строка
        std::cin.get();  // Добавленная строка
        return;
    }

    Payment payment(description, amount, date, client);
    payments.push_back(payment);
    std::cout << "Оплата успешно добавлена." << std::endl;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Добавленная строка
    std::cin.get();  // Добавленная строка
}


void PaymentList::displayPaymentsTable() const {
    std::cout << std::setw(80) << std::setfill('-') << "-" << std::setfill(' ') << std::endl;
    std::cout << std::setw(10) << std::left << "| № заказа"
              << std::setw(15) << std::right << "| Сумма"
              << std::setw(25) << std::left << "| Описание заказа"
              << std::setw(15) << std::right << "| Дата оплаты"
              << std::setw(15) << std::right << "| Имя заказчика" << std::endl;
    std::cout << std::setw(80) << std::setfill('-') << "-" << std::setfill(' ') << std::endl;

    for (const auto& payment : payments) {
        std::cout << std::setw(10) << std::left << payment.getOrderNumber()
                  << std::setw(15) << std::right << payment.getAmount()
                  << std::setw(25) << std::right << payment.getDescription()
                  << std::setw(15) << std::right << payment.getDate()
                  << std::setw(15) << std::right << payment.getClient().getName() << std::endl;
    }

    std::cout << std::setw(80) << std::setfill('-') << "-" << std::setfill(' ') << std::endl;
}

void PaymentList::savePaymentsToFile(const std::string& filename) const {
    std::ofstream file(filename.c_str());
    if (file.is_open()) {
        for (const auto& payment : payments) {
            file << payment.getOrderNumber() << "," << payment.getAmount() << ","
                 << payment.getDescription() << "," << payment.getDate() << ","
                 << payment.getClient().getName() << std::endl;
        }
        file.close();
        std::cout << "Список оплат сохранен в файл." << std::endl;
    } else {
        std::cerr << "Не удалось открыть файл для записи." << std::endl;
    }
}

void PaymentList::loadPaymentsFromFile(const std::string& filename, const std::string& clientsFilename) {
    clientList.loadFromFile(clientsFilename);

    std::ifstream file(filename.c_str());
    if (file.is_open()) {
        payments.clear();
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string orderNumberStr;
            std::string amountStr;
            std::string description;
            std::string dateStr;
            std::string clientName;


            Client client;
            double amount;


            try {
                if (!(std::getline(iss, orderNumberStr, ',') &&
                      std::getline(iss, amountStr, ',') &&
                      std::getline(iss, description, ',') &&
                      std::getline(iss, dateStr, ',') &&
                      std::getline(iss, clientName))) {
                    // Если не удалось считать все поля, выходим из внутреннего цикла
                    continue;
                }

                amount = std::stod(amountStr);


                client = clientList.getClientByName(clientName);


            } catch (std::invalid_argument& e) {
                std::cerr << "Ошибка при преобразовании строки в число: " << e.what() << std::endl;

                continue; // Пропускаем текущую строку и переходим к следующей
            }

            Payment payment(description, amount, dateStr, client);
            payments.push_back(payment);
        }

        file.close();
        std::cout << "Список оплат загружен из файла." << std::endl;
    } else {
        std::cerr << "Не удалось открыть файл для чтения." << std::endl;
    }
}

double PaymentList::calculateTotalIncome() const {
    double totalIncome = 0.0;
    for (const auto& payment : payments) {
        totalIncome += payment.getAmount();
    }
    return totalIncome;
}
