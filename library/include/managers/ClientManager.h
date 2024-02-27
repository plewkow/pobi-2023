//
// Created by student on 31.05.23.
//

#ifndef OOPPROJECT_CLIENTMANAGER_H
#define OOPPROJECT_CLIENTMANAGER_H

#include <string>
#include <vector>
#include <model/typedefs.h>
#include "repositories/Repository.h"
#include "model/Client.h"


class ClientManager
{
    ClientRepositoryPtr clientRepo;
public:
ClientManager(ClientRepositoryPtr repo);
~ClientManager();
const string report() const;
const vector<ClientPtr> getAll() const;
ClientPtr registerClient(const string &Imie,const string &Nazwisko,const string &id, ClientTypePtr clientType);
const ClientPtr find(string const &id) const;
void saveToFile(const std::string& str, const std::string& filename);


};


#endif //OOPPROJECT_CLIENTMANAGER_H
