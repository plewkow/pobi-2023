//
// Created by student on 30.05.23.
//
#include "model/typedefs.h"
#include "model/Membership.h"
#include <string>

Membership::Membership(){}
Membership::~Membership(){}

const int Membership::getMaxArticles() const
{
    return maxArticles;
}
const double Membership::applyDiscount(double price) const{
    return price-2;
}
const string Membership::getTypeInfo() const
{
    return "Membership:"+ this->ClientType::getTypeInfo();
}