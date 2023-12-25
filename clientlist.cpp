
// ClientList.cpp
#include "clientlist.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdexcept>


void ClientList::addClientManually() {
    std::string name;
    std::string SecondName;
    std::string phone;

    std::cout << "Введите имя нового клиента: ";
    std::cin >> name;

    std::cout << "Введите Фамилию нового клиента: ";
    std::cin >> SecondName;

    std::cout << "Введите номер нового клиента: ";
    std::cin >> phone;

    Client client(name,SecondName, phone);
    clients.push_back(client);
}

void ClientList::displayClients() const {
    for (std::vector<Client>::const_iterator it = clients.begin(); it != clients.end(); ++it) {
        it->displayInfo();
    }
}

void ClientList::saveToFile(const std::string& filename) const {
    std::ofstream file(filename.c_str());
    if (file.is_open()) {
        for (const auto& client : clients) {
            file << client.getName() << "," << client.getSecondName() << "," << client.getPhone() << std::endl;
        }
        file.close();
        std::cout << "Client list saved to file." << std::endl;
    } else {
        std::cerr << "Failed to open file for writing." << std::endl;
    }
}

void ClientList::loadFromFile(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (file.is_open()) {
        clients.clear();
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string name, SecondName, phone;
            if (std::getline(iss, name, ',') && std::getline(iss, SecondName,',') && std::getline(iss, phone)) {
                Client client(name, SecondName, phone);
                clients.push_back(client);
            }
        }
        file.close();
        std::cout << "Список клиентов загружен" << std::endl;
    } else {
        std::cerr << "Failed to open file for reading." << std::endl;
    }
}

void ClientList::searchClientBySName(const std::string& SName) {
    for (const auto& client : clients) {
        if (client.getSecondName() == SName) {
            client.displayInfo();
            return;
        }
    }
    std::cout << "Нет клиента с такой фамилией: " << SName << std::endl;
}

Client ClientList::getClientByName(const std::string& name) const {
    for (const auto& client : clients) {
        if (client.getName() == name) {
            return client;
        }
    }
    // Если клиент не найден, можно вернуть объект-заглушку или бросить исключение
    // Например:
    throw std::runtime_error("Client not found");
}

