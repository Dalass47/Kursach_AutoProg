// clientinterface.h
#ifndef CLIENTINTERFACE_H
#define CLIENTINTERFACE_H

#include <iostream>
#include "ClientList.h"

class ClientInterface {
public:
    void ClientInt();

private:
    ClientList clientList;  // Объект ClientList как член класса
};

#endif // CLIENTINTERFACE_H
