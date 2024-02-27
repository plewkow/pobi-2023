//
// Created by student on 11.06.23.
//

#include <boost/test/unit_test.hpp>

#include "managers/ItemManager.h"
#include "repositories/ItemRepository.h"
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

struct TestSuiteItemManagerFixture {
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
    ItemRepositoryPtr testItemRepository;
    TestSuiteItemManagerFixture() {
        testItemRepository = make_shared<Repository<ItemPtr>>();

    }
    ~TestSuiteItemManagerFixture() {}
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteItemManager, TestSuiteItemManagerFixture)

    BOOST_AUTO_TEST_CASE(ContructorException) {
        BOOST_REQUIRE_THROW(new ItemManager(nullptr), std::logic_error);
    }

    BOOST_AUTO_TEST_CASE(RegisterMusicTest) {
        ItemManager itemManager(testItemRepository);

        ItemPtr testItem = itemManager.registerMusic(testItemID1, testBasePrice1, testItemName1,true,Metal);

        BOOST_TEST(testItem == itemManager.find(testItemID1));
    }
BOOST_AUTO_TEST_CASE(RegisterComicsTest) {
        ItemManager itemManager(testItemRepository);

        ItemPtr testItem = itemManager.registerComics(testItemID1, testBasePrice1, testItemName1,125);

        BOOST_TEST(testItem == itemManager.find(testItemID1));
}
BOOST_AUTO_TEST_CASE(RegisterMovieTest) {
        ItemManager itemManager(testItemRepository);

        ItemPtr testItem = itemManager.registerMovie(testItemID1, testBasePrice1, testItemName1,125,true,SciFi);

        BOOST_TEST(testItem == itemManager.find(testItemID1));
}
BOOST_AUTO_TEST_CASE(RegisterItemTestTheSameID) {
        ItemManager itemManager(testItemRepository);

        ItemPtr testItem = itemManager.registerMovie(testItemID1, testBasePrice1, testItemName1,125,true,SciFi);
        BOOST_REQUIRE_THROW(itemManager.registerMovie(testItemID1, testBasePrice1, testItemName1,125,true,SciFi), std::logic_error);
}
BOOST_AUTO_TEST_CASE(GetAllTest) {
        ItemManager itemManager(testItemRepository);

        vector<ItemPtr> items;

        for (int i = 0; i<5; i++) {

            items.push_back(itemManager.registerMovie(to_string(i), testBasePrice1, testItemName1,125,true,SciFi));

        }


        BOOST_TEST(itemManager.getAll()==items);


}

BOOST_AUTO_TEST_CASE(FindTestNullPtr) {
        ItemManager itemManager(testItemRepository);
        BOOST_TEST(itemManager.find(testItemID1) == nullptr);
}


BOOST_AUTO_TEST_SUITE_END()