//
// Created by student on 01.06.23.
//

#ifndef SHAREDPROJECT_RENTREPOSITORY_H
#define SHAREDPROJECT_RENTREPOSITORY_H
/*
#include <string>
#include <vector>
#include <model/typedefs.h>
#include <model/Rent.h>

using namespace std;

class Rent;

class RentRepository
{
private:
    mutable vector <RentPtr> rentRepositoryList;
public:
    RentRepository();
    ~RentRepository();
    const RentPtr get(const int &id) const;
    void add(const RentPtr rent);
    void remove(const RentPtr rent);
    const string report() const;
    const int getSize() const;
    const RentPtr find(const string &i) const;
    const vector<RentPtr> getAll() const;
    //vector<RentPtr> findBy(RentPredicate predicate) const;
    //bool findAll(const RentPtr &ptr);
};
/*
#include "repositories/Repository.h"

#include <model/typedefs.h>
class Rent;
class RentRepository : public Repository<RentPtr> {
public:
  RentRepository();
   ~RentRepository();
};*/
#endif //SHAREDPROJECT_RENTREPOSITORY_H
