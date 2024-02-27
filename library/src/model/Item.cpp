//
// Created by student on 29.05.23.
//
#include <iostream>
#include <string>
#include "model/Item.h"
#include <model/typedefs.h>
#include "exceptions/ParameterException.h"
using namespace std;
Item::Item(const string &itemId,const int &cena, const string &nazwa)
        :
        itemId(itemId),
        itemName(nazwa),
        basePrice(cena),
        rented(false)

{
    if (basePrice <0) { throw ParameterException("Invalid basePrice!"); }
    if (nazwa.empty()) { throw ParameterException("Invalid name (can't be empty)!"); }
    if (itemId.empty()) { throw ParameterException("Invalid ItemId (can't be empty)!"); }
}
Item::~Item()
{

}
const string Item::getInfo() const
{
    string dostepnosc;
    if(rented == true)
        dostepnosc="nie";
    else
        dostepnosc="tak";
    return " Przedmiot: " + itemName +" \n Id: "+ itemId +"\n Cena: "+ to_string(basePrice)  +"\n Dostepnosc: "+ dostepnosc +"\n";
}
void Item::setItemName(const string &nazwa)
{
    if(!nazwa.empty())
    {
        this->itemName=nazwa;
    }
}
void Item::setBasePrice(const int &Cena)
{
    if (Cena >= 0)
    {
        this->basePrice=Cena;
    }

}
const string& Item::getItemName() const
{
    return itemName;
}
const int& Item::getBasePrice() const
{
    return basePrice;
}
const string& Item::getId() const
{
    return itemId;
}
const bool& Item::isRented() const
{
    return rented;
}
const double Item::getActualPrice() const
{
    return this->getBasePrice();
}
void Item::setRented(bool b)
{
    rented=b;
}