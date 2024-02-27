//
// Created by student on 01.06.23.
//
/*
#include <string>
#include "repositories/RentRepository.h"
#include <model/typedefs.h>
#include "exceptions/LogicException.h"
using namespace std;


RentRepository::RentRepository()
{

}
RentRepository::~RentRepository()
{

}
const RentPtr RentRepository::find(const string &id) const
{
    int i=rentRepositoryList.size()-1;
    for(i;i>=0;i--)
    {
        if(rentRepositoryList[i]->getRentId()==id)
            return rentRepositoryList[i];
    }
    return NULL;
}
const RentPtr RentRepository::get(const int &i) const
{
    if(i>=rentRepositoryList.size())
        return NULL;
    return rentRepositoryList[i];
}
void RentRepository::add(const RentPtr rent)
{
    if(rent!=NULL) {
        if (!(this->find(rent->getRentId()) == NULL)) {
            throw LogicException("Rent with this ID already exists in repository");
        }

        rentRepositoryList.push_back(rent);
    }
}
void RentRepository::remove(const RentPtr rent)
{
    if(rent!=NULL)
    {
        int i=rentRepositoryList.size()-1;
        for(i;i>=0;i--)
        {
            if(rentRepositoryList[i]==rent)
                rentRepositoryList.erase(rentRepositoryList.begin()+i);
        }
    }
}
const string RentRepository::report() const
{
    string s="";
    int i=rentRepositoryList.size()-1;
    for(i;i>=0;i--)
    {
        s+=get(i)->getRentInfo();
    }
    return s;
}
const int RentRepository::getSize() const
{
    return rentRepositoryList.size();
}
const vector<RentPtr> RentRepository::getAll() const
{
    return rentRepositoryList;
}
/*vector<RentPtr> RentRepository::findBy(RentPredicate predicate) const {
    vector<RentPtr> found;
    for (unsigned int i = 0; i < rentRepositoryList.size(); i++) {
        RentPtr rent = getRentRepo(i);
        if (rent != nullptr && predicate(rent)) {
            found.push_back(rent);
        }
    }
    return found;
}

bool RentRepository::findAll(const RentPtr &ptr)
{
    return true;
}*//*
#include "repositories/RentRepository.h"

RentRepository::RentRepository() {}

RentRepository::~RentRepository() {}*/

//
// Created by student on 01.06.23.
//
/*
#include <string>
#include "repositories/RentRepository.h"
#include <model/typedefs.h>
#include "exceptions/LogicException.h"

using namespace std;

RentRepository::RentRepository()
{

}

RentRepository::~RentRepository()
{

}

const RentPtr RentRepository::find(const string &id) const
{
    for (const auto& rent : rentRepositoryList)
    {
        if (rent->getRentId() == id)
            return rent;
    }
    return nullptr;
}

const RentPtr RentRepository::get(const int &i) const
{
    if (i >= rentRepositoryList.size())
        return nullptr;
    return rentRepositoryList[i];
}

void RentRepository::add(const RentPtr rent)
{
    if (rent != nullptr)
    {
        if (find(rent->getRentId()) != nullptr)
        {
            throw LogicException("Rent with this ID already exists in repository");
        }
        rentRepositoryList.push_back(rent);
    }
}

void RentRepository::remove(const RentPtr rent)
{
    if (rent != nullptr)
    {
        for (auto it = rentRepositoryList.begin(); it != rentRepositoryList.end(); ++it)
        {
            if (*it == rent)
            {
                rentRepositoryList.erase(it);
                break;
            }
        }
    }
}

const string RentRepository::report() const
{
    string s = "";
    for (const auto& rent : rentRepositoryList)
    {
        s += rent->getRentInfo();
    }
    return s;
}

const int RentRepository::getSize() const
{
    return rentRepositoryList.size();
}

const vector<RentPtr> RentRepository::getAll() const
{
    return rentRepositoryList;
}

*/