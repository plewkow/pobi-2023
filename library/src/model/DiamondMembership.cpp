//
// Created by student on 30.05.23.
//
#include "model/typedefs.h"
#include "model/DiamondMembership.h"
#include <string>

DiamondMembership::DiamondMembership(){}
DiamondMembership::~DiamondMembership(){}

const int DiamondMembership::getMaxArticles() const
{
    return maxArticles;
}
const double DiamondMembership::applyDiscount(double price) const{
    if(price<12.5)
        return price*0.9;
    else if(price<25.0)
        return  price*0.8;
    else if(price<50.0)
        return price*0.7;
    else
        return price*0.6;
}
const string DiamondMembership::getTypeInfo() const
{
    return "Diamond:"+ this->ClientType::getTypeInfo();
}