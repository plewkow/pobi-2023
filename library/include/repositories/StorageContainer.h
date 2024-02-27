//
// Created by student on 01.06.23.
//

#ifndef SHAREDPROJECT_STORAGECONTAINER_H
#define SHAREDPROJECT_STORAGECONTAINER_H

#include "repositories/ClientRepository.h"
#include "repositories/RentRepository.h"
#include "repositories/ItemRepository.h"
#include "repositories/Repository.h"
#include "model/typedefs.h"

class Client;
class Rent;
class Item;
using namespace std;

class Reposiotry;

class StorageContainer
{
private:
    ClientRepositoryPtr clientRepo;
    RentRepositoryPtr rentRepo;
    ItemRepositoryPtr itemRepo;
public:
    StorageContainer();
    ~StorageContainer();
    ClientRepositoryPtr getClientRepository();
    RentRepositoryPtr getRentRepository();
    ItemRepositoryPtr getItemRepository();
};

#endif //SHAREDPROJECT_STORAGECONTAINER_H
