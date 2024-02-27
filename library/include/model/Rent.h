//
// Created by student on 29.05.23.
//

#ifndef OOPPROJECT_RENT_H
#define OOPPROJECT_RENT_H
#include <model/typedefs.h>
#include <boost/date_time.hpp>

class Client;
class Item;

using namespace std;
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

class Rent {
private:
    ClientPtr const client;
    ItemPtr const item;
    const string rentId;
    mutable pt::ptime begineTime = pt::not_a_date_time;
    mutable pt::ptime endTime = pt::not_a_date_time;
    mutable int rentCost = 0;
    mutable bool archive;

public:
    Rent(ClientPtr client, ItemPtr item,const string &id,const pt::ptime &time);
    ~Rent();

    const string getInfo() const;

    void endRent(const pt::ptime &time);

    const pt::ptime getBeginTime()const;
    const pt::ptime getEndTime()const;
    const ClientPtr getClient() const;
    const ItemPtr getItem() const;
    const string &getId() const;
    const int getRentDays() const;
    const int &getRentCost() const;
    const bool isArchive() const;
    void setArchive(bool b);
};
#endif //OOPPROJECT_RENT_H
