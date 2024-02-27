//
// Created by student on 29.05.23.
//
#include "model/typedefs.h"
#include <string>
#include "model/ClientType.h"
using namespace std;
ClientType::ClientType(){}
ClientType::~ClientType(){}

const int ClientType::getMaxArticles() const
{
    return maxArticles;
}
const double ClientType::applyDiscount(double price) const{ return price;}
const string ClientType::getTypeInfo() const
{
    return "\nMaksymalna ilosc wypozyczonych artykulow:"+ this->getMaxArticles();
}