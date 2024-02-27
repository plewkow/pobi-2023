//
// Created by student on 31.05.23.
//

#ifndef OOPPROJECT_CLIENTREPOSITORY_H
#define OOPPROJECT_CLIENTREPOSITORY_H
/*
#include <string>
#include <vector>
#include <model/typedefs.h>
#include <model/Client.h>

using namespace std;

class Client;

class ClientRepository
{
private:
    mutable vector <ClientPtr> clientRepositoryList;
public:
    ClientRepository();
    ~ClientRepository();

    const ClientPtr get(const int &i) const;
    const ClientPtr find(const string &id) const;
    void add(const ClientPtr client);
    void remove(const ClientPtr client);
    const string report() const;
    const int getSize() const;
    const vector<ClientPtr> getAll() const;

   // vector<ClientPtr> findBy(ClientPredicate predicate) const;
   // bool findAll(const ClientPtr &ptr);
};

/*#include "repositories/Repository.h"

#include <model/typedefs.h>
class Client;
class ClientRepository : public Repository<ClientPtr> {
public:
    ClientRepository();
    ~ClientRepository();
};*/

#endif //OOPPROJECT_CLIENTREPOSITORY_H
