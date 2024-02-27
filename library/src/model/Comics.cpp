//
// Created by student on 30.05.23.
//
#include <model/Comics.h>

using namespace std;

Comics::Comics(const string &itemId, const int &cena, const string &nazwa, const int &pages)
:
Item(itemId,cena,nazwa),
pagesNumber(pages)
{
}
Comics::~Comics()
{}
const string Comics::getInfo() const
{
    return this->Item::getInfo() + " Komiks:\n Ilosc stron: " + to_string(pagesNumber) + "\n\n";
}
const double Comics::getActualPrice() const
{
    if(pagesNumber<500)
        return basePrice;
    else if(pagesNumber<1000)
        return basePrice + 10;
    else if(pagesNumber>=1000)
        return basePrice + 20;
    else
        return basePrice;
}
const int& Comics::getPagesNumber() const
{
    return pagesNumber;
}