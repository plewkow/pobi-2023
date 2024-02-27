//
// Created by student on 30.05.23.
//

#ifndef SHAREDPROJECT_MUSIC_H
#define SHAREDPROJECT_MUSIC_H
#include <model/Item.h>

using namespace std;

enum musicGenre
{
    Jazz=1,
    Metal=2,
    Classical=3,
    HipHop=5,
    POP=8,
};

class Music :public Item
{
    const bool vinyl;
    const musicGenre genre;
public:
    Music(const string &itemId, const int &cena, const string &nazwa, const bool &vinyl,musicGenre genre);
    ~Music();
    const string getInfo() const;
    const double getActualPrice() const;
    const string getMusicGenre() const;
    const bool &isVinyl() const;
};
#endif //SHAREDPROJECT_MUSIC_H
