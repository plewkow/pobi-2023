//
// Created by student on 30.05.23.
//
#include "model/typedefs.h"
#include "model/NoMembership.h"
#include <string>

NoMembership::NoMembership(){}
NoMembership::~NoMembership(){}

const int NoMembership::getMaxArticles() const
{
    return maxArticles;
}
const double NoMembership::applyDiscount(double price) const{
    return price;
}
const string NoMembership::getTypeInfo() const
{
    return "NoMembership:"+ this->ClientType::getTypeInfo();
}