
// Client.cpp
#include "Client.h"
#include <iostream>

Client::Client(std::string name, std::string SecondName, std::string Phone) : name(name),SecondName(SecondName), Phone(Phone) {}

void Client::displayInfo() const {
    std::cout << "Name: " << name << ", SecondName: " << SecondName << ", Phone: " << Phone << std::endl;
}
