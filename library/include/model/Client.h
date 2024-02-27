//
// Created by student on 29.05.23.
//

#ifndef OOPPROJECT_CLIENT_H
#define OOPPROJECT_CLIENT_H
#include <string>
#include <vector>
#include <model/typedefs.h>
#include <model/ClientType.h>
#include <model/Rent.h>
#include <memory>

using namespace std;

class ClientType;
class Rent;
class Client
{
    const string personalID;
    mutable string firstName;
    mutable string lastName;
    mutable ClientTypePtr clientType;
    mutable bool archive;
public:
    Client(const string &Imie,const string &Nazwisko,const string &id, ClientTypePtr clientType);
    ~Client();


    const string getInfo() const;


    void setFirstName(const string &Imie);
    void setLastName(const string &Nazwisko);
    void setClientType(ClientTypePtr clientType);

    const int getMaxArticle() const;
    const double applyDiscount(double price) const;
    const string &getFirstName() const;
    const string &getLastName() const;
    const string &getId() const;
    void setArchive(bool b);
    const bool isArchive() const;


};
#endif //OOPPROJECT_CLIENT_H
