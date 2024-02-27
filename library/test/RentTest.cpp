//
// Created by student on 01.06.23.
//
#include <boost/test/unit_test.hpp>
#include <model/Rent.h>
#include <boost/date_time.hpp>
#include "model/Music.h"
#include <model/ClientType.h>
#include <model/NoMembership.h>
#include <model/Membership.h>
#include <model/DiamondMembership.h>
#include <model/Movie.h>
#include <model/Comics.h>
#include <model/Item.h>
#include <model/Client.h>
#include <memory>


namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

struct TestSuiteRentFixture {
    const std::string testFirstName = "Jon";
    const std::string testLastName = "Arbuckle";
    const std::string testPersonalID = "0123456789";
    const std::string testItemName = "KIZO-Plyta";
    const int testBasePrice =70;
    const std::string testItemId ="123";
    const std::string testRentID= "567";
    ClientPtr testclient;
    ItemPtr testitem;
    shared_ptr<ClientType> testClientType1;
    shared_ptr<ClientType> testClientType2;

    TestSuiteRentFixture() {
        testClientType1 = std::make_shared<Membership>();
        testClientType2 = std::make_shared<NoMembership>();
        testclient = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testClientType1);
        testitem = std::make_shared<Music>(testItemId, testBasePrice,testItemName,true, Metal ); }

    ~TestSuiteRentFixture() {

    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRent,TestSuiteRentFixture)

BOOST_AUTO_TEST_CASE(RentConstructorTest){
        Rent r(testclient,testitem,testRentID,pt::not_a_date_time);
        BOOST_TEST(testclient == r.getClient());
        BOOST_TEST(testitem == r.getItem());
        BOOST_TEST(testRentID== r.getId());
        //BOOST_TEST(testclient->getCurrentRent()==&r);
        //BOOST_TEST(true==testvehicle->isRented());
}
BOOST_AUTO_TEST_CASE(ParameterConstrutorTestDefaultBeginTime) {

        Rent *r = new Rent(testclient,testitem,testRentID, pt::not_a_date_time);

        pt::ptime now = pt::second_clock::local_time(); //hope this takes no longer than 59 secs...
        BOOST_TEST_REQUIRE(!r->getBeginTime().is_not_a_date_time()); //if this isn't met, the next check doesn't make sense...
        pt::time_period skew = pt::time_period(r->getBeginTime(), now);
        BOOST_TEST((skew.length().hours()==0 && skew.length().minutes()==0));

        delete r;
}
BOOST_AUTO_TEST_CASE(ParameterConstrutorTestGivenBeginTime){
        pt::ptime now = pt::second_clock::local_time();
        pt::ptime then = pt::ptime(gr::date(2015,5,13),pt::hours(9)+pt::minutes(25));
        Rent *r1 = new Rent(testclient,testitem,testRentID, then);
        BOOST_TEST_REQUIRE(!r1->getBeginTime().is_not_a_date_time());
        pt::time_period skew1 = pt::time_period(r1->getBeginTime(), now);
        BOOST_TEST((r1->getBeginTime()==then));
        BOOST_TEST((skew1.length().hours()>0 || skew1.length().minutes()>0));

        delete r1;
}
BOOST_AUTO_TEST_CASE(endRentDefaultTest){
        Rent r(testclient,testitem,testRentID,pt::not_a_date_time);
        BOOST_TEST_REQUIRE(r.getEndTime()==pt::not_a_date_time);
        r.endRent(pt::not_a_date_time);
        pt::ptime now=pt::second_clock::local_time();
        BOOST_TEST((r.getEndTime()==now));
        pt::ptime then = pt::ptime(gr::date(2025,7,13),pt::hours(9)+pt::minutes(25));
        BOOST_TEST((r.getEndTime()==now));

}
BOOST_AUTO_TEST_CASE(endRentGivenPastTest){
        Rent r(testclient,testitem,testRentID,pt::not_a_date_time);
        pt::ptime then = pt::ptime(gr::date(2015,5,13),pt::hours(9)+pt::minutes(25));
        r.endRent(then);
        BOOST_TEST((r.getEndTime()==r.getBeginTime()));
}
BOOST_AUTO_TEST_CASE(endRentGivenFutureTest){
        Rent r(testclient,testitem,testRentID,pt::not_a_date_time);
        pt::ptime then = pt::ptime(gr::date(2025,7,13),pt::hours(9)+pt::minutes(25));
        r.endRent(then);
        BOOST_TEST((r.getEndTime()==then));
}
BOOST_AUTO_TEST_CASE(RentDaysTestRentNotEnded){
        Rent r(testclient,testitem,testRentID,pt::not_a_date_time);
        BOOST_TEST(r.getRentDays()==0);
}
BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedWithinMinute){
        pt::ptime start = pt::ptime(gr::date(2023, 5, 13), pt::hours(9)+pt::minutes(25)+pt::seconds(0));
        pt::ptime end = pt::ptime(gr::date(2023, 5, 13), pt::hours(9)+pt::minutes(25)+pt::seconds(59));
        Rent r(testclient,testitem,testRentID,start);
        r.endRent(end);
        BOOST_TEST(r.getRentDays()==0);
}
BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedAfter1m){
        pt::ptime start = pt::ptime(gr::date(2023, 5, 13), pt::hours(9)+pt::minutes(25)+pt::seconds(0));
        pt::ptime end = pt::ptime(gr::date(2023, 5, 13), pt::hours(9)+pt::minutes(26)+pt::seconds(0));
        Rent r(testclient,testitem,testRentID,start);
        r.endRent(end);
        BOOST_TEST(r.getRentDays()==0);
}
BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedAfter23h59m){
        pt::ptime start = pt::ptime(gr::date(2023, 5, 13), pt::hours(0)+pt::minutes(0)+pt::seconds(0));
        pt::ptime end = pt::ptime(gr::date(2023, 5, 13), pt::hours(23)+pt::minutes(59)+pt::seconds(0));
        Rent r(testclient,testitem,testRentID,start);
        r.endRent(end);
        BOOST_TEST(r.getRentDays()==1);
}
BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedAfter24h0m){
        pt::ptime start = pt::ptime(gr::date(2023, 5, 13), pt::hours(0)+pt::minutes(0)+pt::seconds(0));
        pt::ptime end = pt::ptime(gr::date(2023, 5, 14), pt::hours(0)+pt::minutes(0)+pt::seconds(0));
        Rent r(testclient,testitem,testRentID,start);
        r.endRent(end);
        BOOST_TEST(r.getRentDays()==1);
}
BOOST_AUTO_TEST_CASE(getRentCostTest){
        Rent r(testclient,testitem,testRentID,pt::not_a_date_time);
        pt::ptime then = pt::ptime(gr::date(2023, 5, 13), pt::hours(9)+pt::minutes(25)+pt::seconds(0));
        BOOST_TEST(r.getRentCost()==0);
        r.endRent(then);
        BOOST_TEST(r.getRentCost()==testclient->applyDiscount(testBasePrice*r.getRentDays()));

}


BOOST_AUTO_TEST_SUITE_END()
