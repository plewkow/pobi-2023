//
// Created by student on 30.05.23.
//

#ifndef OOPPROJECT_MEMBERSHIP_H
#define OOPPROJECT_MEMBERSHIP_H
#include "model/typedefs.h"
#include <model/ClientType.h>

using namespace std;

class Membership : public ClientType
{
private:
    const int maxArticles=3;
public:
    Membership();
    ~Membership();
    const int getMaxArticles() const;
    const double applyDiscount(double price) const;
    const string getTypeInfo() const;
};


#endif //OOPPROJECT_MEMBERSHIP_H
