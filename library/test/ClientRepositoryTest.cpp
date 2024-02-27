//
// Created by student on 01.06.23.
//
/*
#include <boost/test/unit_test.hpp>
#include <model/Client.h>
#include <model/ClientType.h>
#include <model/NoMembership.h>
#include <memory>
#include "repositories/ClientRepository.h"
#include "repositories/StorageContainer.h"
#include "repositories/Repository.h"

struct TestSuiteClientRepositoryFixture {

    const std::string testFirstName1 = "John";
    const std::string testLastName1 = "Abruzzi";
    const std::string testPersonalID1 = "0123456789";
    shared_ptr<ClientType> testClientType1;

    TestSuiteClientRepositoryFixture() {
      testClientType1 =make_shared<NoMembership>();

    }

    ~TestSuiteClientRepositoryFixture() {
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClientRepository,TestSuiteClientRepositoryFixture)


BOOST_AUTO_TEST_CASE(AddClientTest){
    StorageContainer c;
     ClientRepository repo=c.getClientRepository();
     shared_ptr<Client> c1=make_shared<Client>(testFirstName1,testLastName1,testPersonalID1,testClientType1);
     repo.add(NULL);
     repo.add(c1);
     BOOST_TEST(c1==repo.get(2));

}
BOOST_AUTO_TEST_CASE(findClientTest){
        StorageContainer c;
        ClientRepository repo=c.getClientRepository();
        shared_ptr<Client> c1=make_shared<Client>(testFirstName1,testLastName1,testPersonalID1,testClientType1);
        repo.add(c1);
       BOOST_TEST(c1==repo.find(testPersonalID1));

}
BOOST_AUTO_TEST_CASE(RemoveClientTest){
        StorageContainer c;
        ClientRepository repo=c.getClientRepository();
        shared_ptr<Client> c1=make_shared<Client>(testFirstName1,testLastName1,testPersonalID1,testClientType1);
        repo.add(c1);
        BOOST_TEST_REQUIRE(c1==repo.get(2));
        repo.remove(c1);
        BOOST_TEST(repo.get(2)==nullptr);
}
BOOST_AUTO_TEST_CASE(getSizeClientTest)
        {
        StorageContainer c;
        ClientRepository repo=c.getClientRepository();
        BOOST_TEST(2==repo.getSize());
        }
BOOST_AUTO_TEST_SUITE_END()
*/