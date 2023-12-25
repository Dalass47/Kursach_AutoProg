#ifndef CLIENTLIST_H
#define CLIENTLIST_H

#include "Client.h"
#include <vector>
#include <string>

class ClientList {
public:
    void addClientManually();
    void displayClients() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    void searchClientBySName(const std::string& Sname);
    Client getClientByName(const std::string& name) const;

private:
    std::vector<Client> clients;

};

#endif // CLIENTLIST_H
