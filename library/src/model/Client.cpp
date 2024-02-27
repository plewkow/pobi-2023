//
// Created by student on 29.05.23.
//
#include <iostream>
#include "model/Client.h"
#include <model/typedefs.h>
#include <model/ClientType.h>
#include "exceptions/ParameterException.h"

using namespace std;

Client::Client(const string &Imie,const string &Nazwisko,const string &id, ClientTypePtr clientType)
        :
        firstName(Imie),
        lastName(Nazwisko),
        personalID(id),
        clientType(clientType)
{
    if (firstName.empty()) { throw ParameterException("Invalid firstName (can't be empty)!"); }
    if (lastName.empty()) { throw ParameterException("Invalid lastName (can't be empty)!"); }
    if (personalID.empty()) { throw ParameterException("Invalid personalID (can't be empty)!"); }
    if (clientType==nullptr) {throw ParameterException("Client Type has not been passed");}
}

Client::~Client()
{

}

const string Client::getInfo() const
{
    return "Klient: \n Imie: "+ firstName +"\n Nazwisko: "+ this->lastName  +
           "\n Pesel: "+ this->personalID +"\n ";
}

void Client::setClientType(ClientTypePtr Type)
{
    clientType=Type;
}
const int Client::getMaxArticle() const
{
    return clientType->getMaxArticles();
}
const double Client::applyDiscount(double price) const
{
    return clientType->applyDiscount(price);
}

void Client::setFirstName(const string &Imie)
{
    if (!Imie.empty())
    {
        this->firstName= Imie;
    }
}
void Client::setLastName(const string &Nazwisko)
{
    if (!Nazwisko.empty())
    {
        this->lastName=Nazwisko;
    }
}
const string& Client::getFirstName() const
{
    return firstName;
}
const string& Client::getLastName() const
{
    return lastName;
}
const string& Client::getId() const
{
    return personalID;
}
void Client::setArchive(bool b)
{
    archive=b;
}
const bool Client::isArchive() const
{
    return archive;
}

