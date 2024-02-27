// Created by student on 11.06.23.
//

#include <boost/test/unit_test.hpp>

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

struct TestSuiteClientManagerFixture {

    const std::string testFirstName1 = "John";
    const std::string testFirstName2 = "Fernando";

    const std::string testLastName1 = "Abruzzi";
    const std::string testLastName2 = "Sucre";

    const std::string testPersonalID1 = "0123456789";
    const std::string testPersonalID2 = "0987654321";

    shared_ptr<ClientType> testClientType1;
    shared_ptr<ClientType> testClientType2;
    shared_ptr<ClientType> testClientType3;
    ClientRepositoryPtr testClientRepository;

    TestSuiteClientManagerFixture() {
        testClientRepository = make_shared<Repository<ClientPtr>>();
        testClientType1=make_shared<NoMembership>();
        testClientType2=make_shared<Membership>();
        testClientType3=make_shared<DiamondMembership>();

    }

    ~TestSuiteClientManagerFixture() {

    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClientManager, TestSuiteClientManagerFixture)

    BOOST_AUTO_TEST_CASE(ConstructorException) {
        BOOST_REQUIRE_THROW(new ClientManager(nullptr), std::logic_error);
    }

    BOOST_AUTO_TEST_CASE(RegisterClientTest)
    {
        ClientManager cManager(testClientRepository);

        ClientPtr testClient = cManager.registerClient(testFirstName1, testLastName1, testPersonalID1 , testClientType1);

    BOOST_TEST(testClient == cManager.find(testPersonalID1));
    BOOST_TEST(testClient->getFirstName() ==testFirstName1);
    BOOST_TEST(testClient->getLastName() ==testLastName1);
    BOOST_TEST(testClient->getId() ==testPersonalID1);
    }

   BOOST_AUTO_TEST_CASE(RegisterClientTestTheSameID) {
           ClientManager cManager(testClientRepository);

           ClientPtr testClient1 = cManager.registerClient(testFirstName1, testLastName1, testPersonalID1, testClientType1);
           BOOST_REQUIRE_THROW(cManager.registerClient(testFirstName1, testLastName1, testPersonalID1, testClientType1), std::logic_error);
   }

    BOOST_AUTO_TEST_CASE(GetAllTest) {
        ClientManager cManager(testClientRepository);

        vector<ClientPtr> clients;

        for (int i = 0; i<5; i++) {

                clients.push_back(cManager.registerClient(testFirstName1, testLastName1, to_string(i), testClientType1));

        }


            BOOST_TEST(cManager.getAll()==clients);


    }

    BOOST_AUTO_TEST_CASE(FindTestNullPtr) {
        ClientManager cManager(testClientRepository);
        BOOST_TEST(cManager.find(testPersonalID1) == nullptr);
    }
BOOST_AUTO_TEST_SUITE_END()
