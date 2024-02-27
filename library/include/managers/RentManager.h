//
// Created by student on 11.06.23.
//

#ifndef SHAREDPROJECT_RENTMANAGER_H
#define SHAREDPROJECT_RENTMANAGER_H
#include <string>
#include <vector>
#include <model/typedefs.h>
#include "repositories/Repository.h"
#include "model/Rent.h"
#include "model/Client.h"



class RentManager
{
    RentRepositoryPtr rentRepo;
public:
    RentManager(RentRepositoryPtr repo);
    ~RentManager();
    RentPtr rentItem( ClientPtr client, ItemPtr item,const string &id, const pt::ptime &time);
    void returnItem(ItemPtr item,const pt::ptime &time);
    const vector<RentPtr> getAllClientRents(ClientPtr client);
    const RentPtr getItemRent(ItemPtr item) const;
    const string report() const;
    const RentPtr find(const string &id) const;
    const vector<RentPtr> getAllArchiveRents() const;
    const vector<RentPtr> getAllCurrentRents() const;
    const vector<RentPtr> getAll() const;
    void saveToFile(const std::string& str, const std::string& filename);
    const int getRentCost(const string &id) const;
};

#endif //SHAREDPROJECT_RENTMANAGER_H
