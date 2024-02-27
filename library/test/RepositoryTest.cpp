//
// Created by student on 19.06.23.
//
#include <boost/test/unit_test.hpp>
#include <model/Comics.h>
#include <model/Movie.h>
#include <model/Music.h>
#include "model/Item.h"
#include <memory>
#include "model/Client.h"
#include "model/Rent.h"
#include "repositories/Repository.h"
#include "model/typedefs.h"
#include "repositories/StorageContainer.h"
#include "model/NoMembership.h"



struct TestSuiteRepositoryFixture {

    const std::string testItemID1 = "12356";
    const int testBasePrice1 = 50;
    const std::string testItemName1  = "Kizo - Huragan";
    const std::string testFirstName1 = "John";
    const std::string testLastName1 = "Abruzzi";
    const std::string testPersonalID1 = "0123456789";
    const std::string testItemName = "KIZO-Plyta";
    const int testBasePrice =70;
    const std::string testItemId ="123";
    const std::string testRentID= "567";
    ClientPtr testclient;
    ItemPtr testitem;
    shared_ptr<ClientType> testClientType1;
    TestSuiteRepositoryFixture() {
        testClientType1 =make_shared<NoMembership>();

        testclient = std::make_shared<Client>(testFirstName1, testLastName1, testPersonalID1, testClientType1);
        testitem = std::make_shared<Music>(testItemId, testBasePrice,testItemName,true, Metal );

    }

    ~TestSuiteRepositoryFixture() {
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRepository,TestSuiteRepositoryFixture)


BOOST_AUTO_TEST_CASE(AddItemTest){
        StorageContainer c;
        ItemRepositoryPtr repoI=c.getItemRepository();
        RentRepositoryPtr repoR=c.getRentRepository();
        ClientRepositoryPtr repoC=c.getClientRepository();
        ItemPtr i1=make_shared<Music>(testItemID1, testBasePrice1, testItemName1,true,Metal);
        ClientPtr c1=make_shared<Client>(testFirstName1,testLastName1,testPersonalID1,testClientType1);
        RentPtr r1=make_shared<Rent>(testclient,testitem,testRentID,pt::not_a_date_time);
       repoI->add(NULL);
       repoR->add(NULL);
       repoC->add(NULL);
        repoI->add(i1);
        repoR->add(r1);
        repoC->add(c1);
        BOOST_TEST(i1==repoI->get(3));
        BOOST_TEST(r1==repoR->get(2));
       BOOST_TEST(c1==repoC->get(2));

}
BOOST_AUTO_TEST_CASE(findItemTest){
        StorageContainer c;
        ItemRepositoryPtr repoI=c.getItemRepository();
        RentRepositoryPtr repoR=c.getRentRepository();
        ClientRepositoryPtr repoC=c.getClientRepository();
        shared_ptr<Item> i1=make_shared<Music>(testItemID1, testBasePrice1, testItemName1,true,Metal);
        shared_ptr<Client> c1=make_shared<Client>(testFirstName1,testLastName1,testPersonalID1,testClientType1);
        shared_ptr<Rent> r1=make_shared<Rent>(testclient,testitem,testRentID,pt::not_a_date_time);
        repoI->add(i1);
        repoR->add(r1);
        repoC->add(c1);
        BOOST_TEST(i1==repoI->find(testItemID1));
        BOOST_TEST(r1==repoR->find(testRentID));
        BOOST_TEST(c1==repoC->find(testPersonalID1));

}
BOOST_AUTO_TEST_CASE(RemoveItemTest){
        StorageContainer c;
        ItemRepositoryPtr repoI=c.getItemRepository();
        RentRepositoryPtr repoR=c.getRentRepository();
        ClientRepositoryPtr repoC=c.getClientRepository();
        shared_ptr<Item> i1=make_shared<Music>(testItemID1, testBasePrice1, testItemName1,true,Metal);
        shared_ptr<Client> c1=make_shared<Client>(testFirstName1,testLastName1,testPersonalID1,testClientType1);
        shared_ptr<Rent> r1=make_shared<Rent>(testclient,testitem,testRentID,pt::not_a_date_time);
        repoI->add(i1);
        repoR->add(r1);
        repoC->add(c1);
        BOOST_TEST_REQUIRE(i1==repoI->get(3));
        BOOST_TEST_REQUIRE(r1==repoR->get(2));
        BOOST_TEST_REQUIRE(c1==repoC->get(2));
        repoI->remove(i1);
        repoR->remove(r1);
        repoC->remove(c1);
        BOOST_TEST(repoI->get(3)==nullptr);
        BOOST_TEST(repoR->get(2)==nullptr);
        BOOST_TEST(repoC->get(2)==nullptr);
}
BOOST_AUTO_TEST_CASE(getSizeItemTest)
        {
                StorageContainer c;
        ItemRepositoryPtr repoI=c.getItemRepository();
        RentRepositoryPtr repoR=c.getRentRepository();
        ClientRepositoryPtr repoC=c.getClientRepository();
        BOOST_TEST(3==repoI->getSize());
        BOOST_TEST(2==repoR->getSize());
        BOOST_TEST(2==repoC->getSize());
        }
BOOST_AUTO_TEST_SUITE_END()
