//
// Created by student on 31.05.23.
//
#include <boost/test/unit_test.hpp>
#include <model/Client.h>
#include <model/ClientType.h>
#include <model/DiamondMembership.h>
#include <model/Membership.h>
#include <model/NoMembership.h>
#include "model/typedefs.h"
#include <memory>

struct TestSuiteClientFixture {

    const std::string testFirstName1 = "John";
    const std::string testFirstName2 = "Fernando";

    const std::string testLastName1 = "Abruzzi";
    const std::string testLastName2 = "Sucre";

    const std::string testPersonalID1 = "0123456789";
    const std::string testPersonalID2 = "0987654321";

    shared_ptr<ClientType> testClientType1;
    shared_ptr<ClientType> testClientType2;
    shared_ptr<ClientType> testClientType3;

    TestSuiteClientFixture() {
        testClientType1=make_shared<NoMembership>();
        testClientType2=make_shared<Membership>();
        testClientType3=make_shared<DiamondMembership>();
    }

    ~TestSuiteClientFixture() {

    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient,TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(ClientConstructorTest) {
        Client c(testFirstName1, testLastName1, testPersonalID1, testClientType1);
        BOOST_TEST(testFirstName1 == c.getFirstName());
        BOOST_TEST(testLastName1 == c.getLastName());
        BOOST_TEST(testPersonalID1 == c.getId());
    }

    BOOST_AUTO_TEST_CASE(ContructorTestExceptions) {
        BOOST_REQUIRE_THROW(Client c("", testLastName1, testPersonalID1,testClientType1), std::logic_error);
        BOOST_REQUIRE_THROW(Client c(testFirstName1, "", testPersonalID1,testClientType1), std::logic_error);
        BOOST_REQUIRE_THROW(Client c(testFirstName1, testLastName1, "",testClientType1), std::logic_error);
        BOOST_REQUIRE_THROW(Client c(testFirstName1, testLastName1, testPersonalID1, nullptr), std::logic_error);
    }

    BOOST_AUTO_TEST_CASE(ClientSetter1Test) {
        Client c(testFirstName1, testLastName1, testPersonalID1, testClientType1);
        c.setFirstName(testFirstName2);
        BOOST_TEST(testFirstName2 == c.getFirstName());
        c.setFirstName("");
        BOOST_TEST(testFirstName2 == c.getFirstName());
    }

    BOOST_AUTO_TEST_CASE(ClientSetter2Test) {
        Client c(testFirstName1, testLastName1, testPersonalID1, testClientType1);
        c.setLastName(testLastName2);
        BOOST_TEST(testLastName2 == c.getLastName());
        c.setLastName("");
        BOOST_TEST(testLastName2 == c.getLastName());
    }
    BOOST_AUTO_TEST_CASE(ClientTypeTest){
        Client c(testFirstName1, testLastName1, testPersonalID1, testClientType1);
        c.setClientType(testClientType1);
        BOOST_TEST(c.getMaxArticle()==1);
        BOOST_TEST(c.applyDiscount(100)==100);
        c.setClientType(testClientType2);
        BOOST_TEST(c.getMaxArticle()==3);
        BOOST_TEST(c.applyDiscount(100)==98);
        c.setClientType(testClientType3);
        BOOST_TEST(c.getMaxArticle()==10);
        BOOST_TEST(c.applyDiscount(10.0)==9.0);
        BOOST_TEST(c.applyDiscount(12.5)==10.0);
        BOOST_TEST(c.applyDiscount(25.0)==17.5);
        BOOST_TEST(c.applyDiscount(50.0)==30.0);
    }
BOOST_AUTO_TEST_SUITE_END()