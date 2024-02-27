//
// Created by student on 29.05.23.
//

#ifndef OOPPROJECT_ITEM_H
#define OOPPROJECT_ITEM_H
#include <model/typedefs.h>
#include <string>

using namespace std;

class Item
{
    protected:
    const string itemId;
    mutable int basePrice;
    mutable string itemName;
    mutable bool rented;

public:
    Item(const string &itemId, const int &cena, const string &nazwa);
    virtual ~Item()=0;

    virtual const string getInfo() const;
    void setRented(bool b);
    void setItemName(const string &nazwa);
    virtual void setBasePrice(const int &Cena);

    const string &getId() const;
    const int &getBasePrice() const;
    const string &getItemName() const;
    const bool &isRented() const;

    const double getActualPrice() const;
};
#endif //OOPPROJECT_ITEM_H
