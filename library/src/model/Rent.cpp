//
// Created by student on 29.05.23.
//
#include <iostream>
#include <string>
#include "model/Client.h"
#include "model/Item.h"
#include "model/Rent.h"
#include <boost/date_time.hpp>
#include <model/typedefs.h>
#include "exceptions/ParameterException.h"


using namespace std;
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

Rent::Rent( ClientPtr client, ItemPtr item,const string &id, const pt::ptime &time)
        :
        client(client),
        item(item),
        rentId(id),
        archive(false)
{
    //item->rentedTrue();
    if(time==pt::not_a_date_time)
        begineTime=pt::second_clock::local_time();
    else
        begineTime=time;
    if(item->isRented()==true)
    {
        throw ParameterException("Item is Rented");
    }
    else
    {
        this->item->setRented(true);
    }


    if (client == nullptr) {throw ParameterException("ClientPtr is null");}
    if (item == nullptr) {throw ParameterException("ClientPtr is null");}
    if (rentId.empty()) { throw ParameterException("Invalid RentID (can't be empty)!");}
}
Rent::~Rent()
{}


const string Rent::getInfo() const
{
    std::stringstream ss1;
    ss1 << begineTime;
    string s1=ss1.str();
    std::stringstream ss2;
    ss2 << endTime;
    string s2=ss2.str();
    return this->client->getInfo()  + this->item->getInfo() + "ID: " +
           rentId + "\nRozpoczecie wypozyczenia: " + s1 +"\n Koniec wypozyczenia: " +
           s2+"\n\n";
}

const ClientPtr Rent::getClient() const
{
    return this->client;
}
const ItemPtr Rent::getItem() const
{
    return this->item;
}
const string& Rent::getId() const
{
    return rentId;
}
const pt::ptime Rent::getBeginTime() const
{
    return begineTime;

}
const pt::ptime Rent::getEndTime() const
{

    return endTime;
}
void Rent::endRent(const pt::ptime &time)
{
    if(endTime==pt::not_a_date_time)
    {
        if (time == pt::not_a_date_time)
            endTime = pt::second_clock::local_time();
        else if (time <= begineTime)
            endTime = begineTime;
        else
            endTime = time;

        double cost=item->getActualPrice()*getRentDays();
        this->rentCost=this->client->applyDiscount(cost);
      this->item->setRented(false);

    }

}
const int Rent::getRentDays() const
{
    if(endTime==pt::not_a_date_time)
        return 0;
    pt::time_period period(begineTime,endTime);
    int RentHours=period.length().hours();
    if(period.length().hours()==0&&period.length().minutes()==0&&period.length().seconds()<=59)
        return 0;

    if(!(RentHours%24==0))
        return RentHours/24+1;
    else
        return RentHours/24;

}
const int& Rent::getRentCost() const
{
    return rentCost;
}
const bool Rent::isArchive() const
{
    return archive;
}
void Rent::setArchive(bool b)
{
    archive=b;
}
