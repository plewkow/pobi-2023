//
// Created by student on 01.06.23.
//
/*
#include <boost/test/unit_test.hpp>
#include <model/Rent.h>
#include <memory>
#include "repositories/RentRepository.h"
#include "repositories/StorageContainer.h"
#include "repositories/Repository.h"
#include <boost/date_time.hpp>
#include <model/Item.h>
#include <model/Client.h>
#include <model/NoMembership.h>
#include "model/Music.h"

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

struct TestSuiteRentRepositoryFixture {

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

    TestSuiteRentRepositoryFixture() {
        testClientType1 =make_shared<NoMembership>();
        testclient = std::make_shared<Client>(testFirstName1, testLastName1, testPersonalID1, testClientType1);
        testitem = std::make_shared<Music>(testItemId, testBasePrice,testItemName,true, Metal );

    }

    ~TestSuiteRentRepositoryFixture() {
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRentRepository,TestSuiteRentRepositoryFixture)


BOOST_AUTO_TEST_CASE(AddRentTest){
        StorageContainer c;
        RentRepository repo=c.getRentRepository();
        shared_ptr<Rent> r1=make_shared<Rent>(testclient,testitem,testRentID,pt::not_a_date_time);
        repo.add(NULL);
        repo.add(r1);
        BOOST_TEST(r1==repo.get(2));

}
BOOST_AUTO_TEST_CASE(findRentTest){
        StorageContainer c;
        RentRepository repo=c.getRentRepository();
        shared_ptr<Rent> r1=make_shared<Rent>(testclient,testitem,testRentID,pt::not_a_date_time);
        repo.add(r1);
        BOOST_TEST(r1==repo.find(testRentID));

}
BOOST_AUTO_TEST_CASE(RemoveRentTest){
        StorageContainer c;
        RentRepository repo=c.getRentRepository();
        shared_ptr<Rent> r1=make_shared<Rent>(testclient,testitem,testRentID,pt::not_a_date_time);
        repo.add(r1);
        BOOST_TEST_REQUIRE(r1==repo.get(2));
        repo.remove(r1);
        BOOST_TEST(repo.get(2)==nullptr);
}
BOOST_AUTO_TEST_CASE(getSizeRentTest)
        {
        StorageContainer c;
        RentRepository repo=c.getRentRepository();
        BOOST_TEST(2==repo.getSize());
        }
BOOST_AUTO_TEST_SUITE_END()
*/