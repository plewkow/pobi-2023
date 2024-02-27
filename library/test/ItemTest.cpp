//
// Created by student on 31.05.23.
//

#include <boost/test/unit_test.hpp>
#include <model/Item.h>
#include <model/Music.h>
#include <model/Movie.h>
#include <model/Comics.h>

struct TestSuiteItemFixture {
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

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteItem,TestSuiteItemFixture)

    BOOST_AUTO_TEST_CASE(MusicConstructorTest) {
        Music m(testItemID1, testBasePrice1, testItemName1,true,Metal);
        BOOST_TEST(testItemID1 == m.getId());
        BOOST_TEST(testBasePrice1 == m.getBasePrice());
        BOOST_TEST(testItemName1 == m.getItemName());
        BOOST_TEST(true==m.isVinyl());
        BOOST_TEST("Metal"==m.getMusicGenre());

    }
BOOST_AUTO_TEST_CASE(MovieConstructorTest) {
        Movie m(testItemID1, testBasePrice1, testItemName1,testminutes1,true,SciFi);
        BOOST_TEST(testItemID1 == m.getId());
        BOOST_TEST(testBasePrice1 == m.getBasePrice());
        BOOST_TEST(testItemName1 == m.getItemName());
        BOOST_TEST(true==m.isCasette());
        BOOST_TEST("SciFi"==m.getMovieGenre());
        BOOST_TEST(testminutes1==m.getMovieMinutes());
    }
BOOST_AUTO_TEST_CASE(ComicsConstructorTest) {
        Comics c(testItemID1, testBasePrice1, testItemName1,testpagesnumber1);
        BOOST_TEST(testItemID1 == c.getId());
        BOOST_TEST(testBasePrice1 == c.getBasePrice());
        BOOST_TEST(testItemName1 == c.getItemName());
        BOOST_TEST(testpagesnumber1==c.getPagesNumber());

     }
    BOOST_AUTO_TEST_CASE(ItemSetter1Test) {
            Music m(testItemID1, testBasePrice1, testItemName1,true,Metal);
        m.setItemName(testItemName2);
        BOOST_TEST(testItemName2 == m.getItemName());
        m.setItemName("");
        BOOST_TEST(testItemName2 == m.getItemName());
    }
    BOOST_AUTO_TEST_CASE(ItemSetter2Test) {
        Music m(testItemID1, testBasePrice1, testItemName1,true,Metal);
        m.setBasePrice(testBasePrice2);
        BOOST_TEST(testBasePrice2 == m.getBasePrice());
        m.setBasePrice(-345);
        BOOST_TEST(testBasePrice2== m.getBasePrice());
    }
    BOOST_AUTO_TEST_CASE(MusicGetActualPrice1Test){
            Music m(testItemID1, testBasePrice1, testItemName1, true, Metal);
            BOOST_TEST(testBasePrice1+30==m.getActualPrice());
    }
     BOOST_AUTO_TEST_CASE(MusicGetActualPrice2Test){
        Music m(testItemID1, testBasePrice1, testItemName1, false, Metal);
        BOOST_TEST(testBasePrice1*1.2==m.getActualPrice());
    }
    BOOST_AUTO_TEST_CASE(MovieGetActualPrice1Test){
            Movie m(testItemID1, testBasePrice1, testItemName1,testminutes1,true,SciFi);
        BOOST_TEST(testBasePrice1-5==m.getActualPrice());
    }
BOOST_AUTO_TEST_CASE(MovieGetActualPrice2Test){
        Movie m(testItemID1, testBasePrice1, testItemName1,testminutes1,false,SciFi);
        BOOST_TEST(testBasePrice1*1.4==m.getActualPrice());
   }
BOOST_AUTO_TEST_CASE(ComicsGetActualPrice1Test){
        Comics c(testItemID1, testBasePrice1, testItemName1,testpagesnumber1);
        BOOST_TEST(testBasePrice1==c.getActualPrice());
}
BOOST_AUTO_TEST_CASE(ComicsGetActualPrice2Test){
        Comics c(testItemID1, testBasePrice1, testItemName1,testpagesnumber2);
        BOOST_TEST(testBasePrice1+10==c.getActualPrice());
}
BOOST_AUTO_TEST_CASE(ComicsGetActualPrice3Test){
        Comics c(testItemID1, testBasePrice1, testItemName1,testpagesnumber3);
        BOOST_TEST(testBasePrice1+20==c.getActualPrice());
}


BOOST_AUTO_TEST_SUITE_END()