//
// Created by student on 30.05.23.
//

#ifndef SHAREDPROJECT_COMICS_H
#define SHAREDPROJECT_COMICS_H
#include <model/Item.h>

using namespace std;

class Comics :public Item
{
    const int pagesNumber;
public:
    Comics(const string &itemId, const int &cena, const string &nazwa, const int &pages);
    ~Comics();
    const string getInfo() const;
    const double getActualPrice() const;
    const int &getPagesNumber() const;
};
#endif //SHAREDPROJECT_COMICS_H
