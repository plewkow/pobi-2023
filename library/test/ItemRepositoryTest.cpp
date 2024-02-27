//
// Created by student on 01.06.23.
//
/*
#include <boost/test/unit_test.hpp>
#include <model/Comics.h>
#include <model/Movie.h>
#include <model/Music.h>
#include "model/Item.h"
#include <memory>
#include "repositories/ItemRepository.h"
#include "repositories/StorageContainer.h"
#include "repositories/Repository.h"

struct TestSuiteItemRepositoryFixture {

    const std::string testItemID1 = "12356";
    const int testBasePrice1 = 50;
    const std::string testItemName1  = "Kizo - Huragan";


    TestSuiteItemRepositoryFixture() {

    }

    ~TestSuiteItemRepositoryFixture() {
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteItemRepository,TestSuiteItemRepositoryFixture)


BOOST_AUTO_TEST_CASE(AddItemTest){
        StorageContainer c;
        ItemRepository repo=c.getItemRepository();
        shared_ptr<Item> i1=make_shared<Music>(testItemID1, testBasePrice1, testItemName1,true,Metal);
        repo.add(NULL);
        repo.add(i1);
        BOOST_TEST(i1==repo.get(3));

}
BOOST_AUTO_TEST_CASE(findItemTest){
        StorageContainer c;
        ItemRepository repo=c.getItemRepository();
        shared_ptr<Item> i1=make_shared<Music>(testItemID1, testBasePrice1, testItemName1,true,Metal);
        repo.add(i1);
        BOOST_TEST(i1==repo.find(testItemID1));

}
BOOST_AUTO_TEST_CASE(RemoveItemTest){
        StorageContainer c;
        ItemRepository repo=c.getItemRepository();
        shared_ptr<Item> i1=make_shared<Music>(testItemID1, testBasePrice1, testItemName1,true,Metal);
        repo.add(i1);
        BOOST_TEST_REQUIRE(i1==repo.get(3));
        repo.remove(i1);
        BOOST_TEST(repo.get(3)==nullptr);
}
BOOST_AUTO_TEST_CASE(getSizeItemTest)
        {
                StorageContainer c;
        ItemRepository repo=c.getItemRepository();;
        BOOST_TEST(3==repo.getSize());
        }
BOOST_AUTO_TEST_SUITE_END()
*/