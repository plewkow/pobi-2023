//
// Created by student on 11.06.23.
//
#include <vector>
#include "managers/RentManager.h"
#include "exceptions/ParameterException.h"
#include "model/Client.h"
#include <boost/date_time.hpp>
#include <fstream>
#include <iostream>
#include "exceptions/LogicException.h"
#include "model/Rent.h"
#include "model/Client.h"
#include "repositories/Repository.h"

using namespace std;
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

RentManager::RentManager(RentRepositoryPtr repo)
        :
        rentRepo(repo)
{
    if (repo==nullptr) { throw ParameterException("RepositoryPtr cant be nullptr!"); }
}

RentManager::~RentManager(){}
RentPtr RentManager::rentItem( ClientPtr client, ItemPtr item,const string &id, const pt::ptime &time){

    if(rentRepo->find(id)==nullptr)
    {
        RentPtr nowy=make_shared<Rent>(client,item,id,time);
        rentRepo->add(nowy);
        return nowy;
    }
    else
    {
        throw LogicException("Rent with this ID already exists");
    }
}
const string RentManager::report() const{
    return rentRepo->report();
}
const vector<RentPtr> RentManager::getAll() const
{
    return rentRepo->getAll();
}
void RentManager::returnItem(ItemPtr item,const pt::ptime &time){
    for(int i=getAllCurrentRents().size()-1;i>=0;i--)
    {
        ClientPtr client;

        if(getAllCurrentRents()[i]->getItem()==item) {
            getAllCurrentRents()[i]->endRent(time);
           client=getAllCurrentRents()[i]->getClient();

           bool archiveclient=true;

            for(int j=getAllCurrentRents().size()-1;j>=0;j--)
            {
                if(getAllCurrentRents()[j]->getClient()==client)
                {
                    archiveclient=false;
                }
            }
            if(archiveclient==true)
                getAllCurrentRents()[i]->getClient()->setArchive(true);

            getAllCurrentRents()[i]->setArchive(true);

        }


    }
}
const vector<RentPtr> RentManager::getAllArchiveRents() const
{
    vector<RentPtr> znalezione;
    for(int i=rentRepo->getAll().size()-1;i>=0;i--)
    {
        if(rentRepo->getAll()[i]->isArchive()==true)
            znalezione.push_back(rentRepo->getAll()[i]);
    }
    return znalezione;
}
const vector<RentPtr> RentManager::getAllCurrentRents() const
{
    vector<RentPtr> znalezione;
    for(int i=rentRepo->getAll().size()-1;i>=0;i--)
    {
        if(rentRepo->getAll()[i]->isArchive()==false)
            znalezione.push_back(rentRepo->getAll()[i]);
    }
    return znalezione;
}
const vector<RentPtr> RentManager::getAllClientRents(ClientPtr client){
    vector<RentPtr> znalezione;
    for(int i=rentRepo->getAll().size()-1;i>=0;i--)
    {
        if(rentRepo->getAll()[i]->getClient()==client) {
            znalezione.push_back(rentRepo->getAll()[i]);

        }
    }
    return znalezione;
}
const RentPtr RentManager::getItemRent(ItemPtr item) const
{
    for(int i=getAllCurrentRents().size()-1;i>=0;i--)
    {
        if(getAllCurrentRents()[i]->getItem()==item)
            return getAllCurrentRents()[i];
    }
    return nullptr;
}
const RentPtr RentManager::find(const string &id) const
{
    return rentRepo->find(id);
}

void RentManager::saveToFile(const std::string &str, const std::string &filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << str;
        file.close();
    } else {
        std::cout << "Nie można otworzyć pliku: " << filename << std::endl;
    }
}
const int RentManager::getRentCost(const string &id) const
{
    if(rentRepo->find(id)->isArchive()==true)
    {
        return this->find(id)->getRentCost();
    }
    else
    {
        throw LogicException("Rent didn't end yet!");
    }

}
