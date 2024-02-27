//
// Created by student on 30.05.23.
//

#ifndef OOPPROJECT_NOMEMBERSHIP_H
#define OOPPROJECT_NOMEMBERSHIP_H
#include "model/typedefs.h"
#include <model/ClientType.h>

using namespace std;

class NoMembership : public ClientType
{
private:
    const int maxArticles=1;
public:
    NoMembership();
    ~NoMembership();
    const int getMaxArticles() const;
    const double applyDiscount(double price) const;
    const string getTypeInfo() const;
};

#endif //OOPPROJECT_NOMEMBERSHIP_H
