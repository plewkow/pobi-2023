//
// Created by student on 29.05.23.
//

#ifndef OOPPROJECT_CLIENTTYPE_H
#define OOPPROJECT_CLIENTTYPE_H

#include "model/typedefs.h"

using namespace std;

class ClientType
{
private:
    const int maxArticles=0;
    mutable int discount;
public:
    ClientType();
    virtual ~ClientType();
    virtual const int getMaxArticles() const;
    virtual const double applyDiscount(double price) const;
    virtual const string getTypeInfo() const;
};

#endif //OOPPROJECT_CLIENTTYPE_H
