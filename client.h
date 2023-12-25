// Client.h
#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
public:
    // Конструктор с параметрами
    Client(std::string name, std::string SecondName, std::string Phone);

    // Конструктор по умолчанию
    Client() : name(""), SecondName(""), Phone("") {}

    void displayInfo() const;

    std::string getName() const {
        return name;
    }

    std::string getSecondName() const {
        return SecondName;
    }

    std::string getPhone() const {
        return Phone;
    }

private:
    std::string name;
    std::string SecondName;
    std::string Phone;
};

#endif // CLIENT_H
