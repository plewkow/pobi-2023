//
// Created by student on 30.05.23.
//

#ifndef OOPPROJECT_DIAMONDMEMBERSHIP_H
#define OOPPROJECT_DIAMONDMEMBERSHIP_
#include "model/typedefs.h"
#include <model/ClientType.h>

using namespace std;

class DiamondMembership : public ClientType
{
private:
    const int maxArticles=10;
public:
    DiamondMembership();
    ~DiamondMembership();
    const int getMaxArticles() const;
    const double applyDiscount(double price) const;
    const string getTypeInfo() const;
};
#endif //OOPPROJECT_DIAMONDMEMBERSHIP_H
