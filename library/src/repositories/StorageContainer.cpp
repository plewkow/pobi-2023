//
// Created by student on 01.06.23.
//


#include "repositories/StorageContainer.h"
#include <boost/date_time.hpp>
#include <model/Client.h>
#include <model/Item.h>
#include <model/Rent.h>
#include <model/Music.h>
#include <model/Movie.h>
#include <model/Comics.h>
#include <model/Membership.h>
#include <model/DiamondMembership.h>
#include <memory>
#include <repositories/ClientRepository.h>
#include <repositories/RentRepository.h>
#include <repositories/ItemRepository.h>
#include <repositories/Repository.h>
#include "model/typedefs.h"

StorageContainer::StorageContainer(){

    ClientTypePtr clienttype1 =make_shared<Membership>();
    ClientTypePtr clienttype2 =make_shared<DiamondMembership>();

    ClientPtr c1 =make_shared<Client>("Piotr","Lewkowicz","123",clienttype1);
    clientRepo->add(c1);
    ClientPtr c2 =make_shared<Client>("skul","Burgir","321",clienttype2);
    clientRepo->add(c2);
    ItemPtr i1 =make_shared<Music>("765",342,"MrJocker",true,HipHop);
    itemRepo->add(i1);
    ItemPtr i2 =make_shared<Movie>("567",100,"back to future",200,false,SciFi);
    itemRepo->add(i2);
    ItemPtr i3 =make_shared<Comics>("987",65,"spiderman",400);
    itemRepo->add(i3);
    RentPtr r1 =make_shared<Rent>(c1,i1,"1",pt::not_a_date_time);
    rentRepo->add(r1);
    pt::ptime then = pt::ptime(gr::date(2023,5,13),pt::hours(9)+pt::minutes(25));
    RentPtr r2 =make_shared<Rent>(c2,i2,"2",then);
    rentRepo->add(r2);
}
StorageContainer::~StorageContainer(){

};

ClientRepositoryPtr StorageContainer::getClientRepository()
{
    return clientRepo;
}
RentRepositoryPtr StorageContainer::getRentRepository()
{
    return rentRepo;
}
ItemRepositoryPtr StorageContainer::getItemRepository()
{
    return itemRepo;
}