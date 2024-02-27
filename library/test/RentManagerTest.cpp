//
// Created by student on 11.06.23.
//
#include <boost/test/unit_test.hpp>

#include "managers/RentManager.h"
#include "repositories/Repository.h"
#include "model/Rent.h"
#include "model/Client.h"
#include "model/Item.h"
#include <model/Music.h>
#include <model/Movie.h>
#include <model/Comics.h>
#include "managers/ClientManager.h"
#include "repositories/ClientRepository.h"
#include "model/Client.h"
#include "model/ClientType.h"
#include "model/DiamondMembership.h"
#include "model/Membership.h"
#include "model/NoMembership.h"
#include "model/typedefs.h"
#include <memory>
#include <sstream>
#include "repositories/StorageContainer.h"
#include "repositories/Repository.h"
#include <vector>
#include <boost/date_time.hpp>
#include <boost/uuid/uuid_generators.hpp>

struct TestSuiteRentManagerFixture {
    const std::string testFirstName = "Jan";
    const std::string testLastName = "Nowak";
    const std::string testPersonalID1 = "0123456789";
    const std::string testPersonalID2 = "0123456789";
    const std::string testItemID1 = "12356";
    const std::string testItemID2 = "45667";
    //const std::string testItemID3 = "45668";
    const int testBasePrice1 = 50;
    const int testBasePrice2 = 30;
    //const int testBasePrice3 = 20.0;
    const std::string testItemName1  = "Kizo - Huragan";
    const std::string testItemName2  = "F&F";
    //const std::string testItemName3  = "SpiderMan";
    const int testminutes1 =90;
    const int testminutes2 =150;
    const int testpagesnumber1 =499;
    const int testpagesnumber2 =500;
    const int testpagesnumber3 =1000;
    std::shared_ptr<ClientType> testClientType1;
    ClientPtr testClient1;
    ClientPtr testClient2;
    ItemPtr testItem;
    ItemPtr testItem2;
    boost::posix_time::ptime testTime;
    RentRepositoryPtr testRentRepository;

    TestSuiteRentManagerFixture() {
        testClientType1 = std::make_shared<DiamondMembership>();
        testRentRepository = make_shared<Repository<RentPtr>>();
        testClient1 = std::make_shared<Client>(testFirstName, testLastName, testPersonalID1, testClientType1);
        testClient2 = std::make_shared<Client>(testFirstName, testLastName, testPersonalID2, testClientType1);
        testItem =std::make_shared<Comics>("123",123,"sadas",123);
        testItem2=std::make_shared<Comics>("1",122,"sadas",12);
        testTime = boost::posix_time::second_clock::local_time();

    }
    ~TestSuiteRentManagerFixture(){}
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRentManager, TestSuiteRentManagerFixture)

    BOOST_AUTO_TEST_CASE(ConstructorException) {
        BOOST_REQUIRE_THROW(new RentManager(nullptr), std::logic_error);
    }

    BOOST_AUTO_TEST_CASE(RentItemTest) {
        RentManager rManager(testRentRepository);

        RentPtr testRent = rManager.rentItem(testClient1,testItem,testItemID1,testTime);

        BOOST_TEST(rManager.find(testItemID1) == testRent);
    }

    BOOST_AUTO_TEST_CASE(RentItemTestWhenAlreadyRented) {
        RentManager rManager(testRentRepository);
        RentPtr testRent = rManager.rentItem(testClient1,testItem,testItemID1,testTime);
        BOOST_REQUIRE_THROW(rManager.rentItem(testClient2,testItem,testItemID2,testTime), std::logic_error);
    }

    BOOST_AUTO_TEST_CASE(ReturnItemTest) {
        RentManager rManager(testRentRepository);
        RentPtr testRent = rManager.rentItem(testClient1,testItem,testItemID1,testTime);
        BOOST_TEST_REQUIRE(rManager.getAllCurrentRents()[0]==testRent);
        rManager.returnItem(testItem,pt::not_a_date_time);

        BOOST_TEST(rManager.getAllArchiveRents()[0]==testRent);
    }
    BOOST_AUTO_TEST_CASE(findItemRentTestNullPtr) {
            RentManager rManager(testRentRepository);
            BOOST_TEST(rManager.find("1") == nullptr);
    }
BOOST_AUTO_TEST_CASE(getAllTest) {
        RentManager rManager(testRentRepository);

        vector<RentPtr> rents;


        rents.push_back(rManager.rentItem(testClient1,testItem,testItemID1,testTime));
        rents.push_back(rManager.rentItem(testClient1,testItem2,testItemID2,testTime));

        BOOST_TEST(rManager.getAll()==rents);


}
BOOST_AUTO_TEST_CASE(getAllCurrentTest) {
        RentManager rManager(testRentRepository);

        vector<RentPtr> rents;


        rents.push_back(rManager.rentItem(testClient1,testItem,testItemID1,testTime));
        rents.push_back(rManager.rentItem(testClient1,testItem2,testItemID2,testTime));
        rManager.returnItem(testItem,pt::not_a_date_time);
        rents.erase(rents.begin());
        BOOST_TEST(rManager.getAllCurrentRents()==rents);


}
BOOST_AUTO_TEST_CASE(getAllArchiveTest) {
        RentManager rManager(testRentRepository);

        vector<RentPtr> rents;


        rents.push_back(rManager.rentItem(testClient1,testItem,testItemID1,testTime));
        rents.push_back(rManager.rentItem(testClient1,testItem2,testItemID2,testTime));
        rManager.returnItem(testItem,pt::not_a_date_time);
        rents.erase(rents.begin()+1);
        BOOST_TEST(rManager.getAllArchiveRents()==rents);


}
BOOST_AUTO_TEST_CASE(getRentCostTest) {
        RentManager rManager(testRentRepository);
        RentPtr testRent = rManager.rentItem(testClient1,testItem,testItemID1,testTime);
        BOOST_REQUIRE_THROW(rManager.getRentCost(testItemID1),std::logic_error);
        pt::ptime then = pt::ptime(gr::date(2025,7,13),pt::hours(9)+pt::minutes(25));
        rManager.returnItem(testItem,then);
        BOOST_TEST(rManager.getRentCost(testItemID1)==testRent->getRentCost());
}
BOOST_AUTO_TEST_SUITE_END()