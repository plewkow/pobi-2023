//
// Created by student on 31.05.23.
//
/*
#include <string>
#include "repositories/ClientRepository.h"
#include <model/typedefs.h>
#include <model/Client.h>
#include "exceptions/LogicException.h"

using namespace std;


ClientRepository::ClientRepository()
{

}
ClientRepository::~ClientRepository()
{

}
const ClientPtr ClientRepository::find(const string &id) const
{
    int i=clientRepositoryList.size()-1;
    for(i;i>=0;i--)
    {
        if(clientRepositoryList[i]->getPersonalID()==id)
            return clientRepositoryList[i];
    }

    return NULL;
}
const ClientPtr ClientRepository::get(const int &i) const
{
    if(i>=clientRepositoryList.size())
        return NULL;
    return clientRepositoryList[i];
}
void ClientRepository::add(const ClientPtr client) {
    if (client != NULL) {
        if (!(this->find(client->getPersonalID()) == NULL)) {
            throw LogicException("Client with this ID already exists in repository");
        }
            clientRepositoryList.push_back(client);
    }
}
void ClientRepository::remove(const ClientPtr client)
{
    if(client!=NULL)
    {
        int i=clientRepositoryList.size()-1;
        for(i;i>=0;i--)
        {
            if(clientRepositoryList[i]==client)
                clientRepositoryList.erase(clientRepositoryList.begin()+i);
        }
    }
}
const string ClientRepository::report() const
{
    string s="";
    int i=clientRepositoryList.size()-1;
    for(i;i>=0;i--)
    {
        s+=get(i)->getClientInfo();
    }
    return s;
}
const int ClientRepository::getSize() const
{
    return clientRepositoryList.size();
}
const vector<ClientPtr> ClientRepository::getAll() const
{
    return clientRepositoryList;
}
/*vector<ClientPtr> ClientRepository::findBy(ClientPredicate predicate) const {
    vector<ClientPtr> found;
    for (unsigned int i = 0; i < clientRepositoryList.size(); i++) {
        ClientPtr client = getClientRepo(i);
        if (client != nullptr && predicate(client)) {
            found.push_back(client);
        }
    }
    return found;
}

bool ClientRepository::findAll(const ClientPtr &ptr)
{
    return true;
}*//*
#include "repositories/ClientRepository.h"
ClientRepository::ClientRepository() {}

ClientRepository::~ClientRepository() {}*/

//
// Created by student on 31.05.23.
//
/*
#include <string>
#include "repositories/ClientRepository.h"
#include <model/typedefs.h>
#include <model/Client.h>
#include "exceptions/LogicException.h"

using namespace std;

ClientRepository::ClientRepository()
{

}

ClientRepository::~ClientRepository()
{

}

const ClientPtr ClientRepository::find(const string &id) const
{
    for (const auto& client : clientRepositoryList)
    {
        if (client->getPersonalID() == id)
            return client;
    }
    return nullptr;
}

const ClientPtr ClientRepository::get(const int &i) const
{
    if (i >= clientRepositoryList.size())
        return nullptr;
    return clientRepositoryList[i];
}

void ClientRepository::add(const ClientPtr client)
{
    if (client != nullptr)
    {
        if (find(client->getPersonalID()) != nullptr)
        {
            throw LogicException("Client with this ID already exists in repository");
        }
        clientRepositoryList.push_back(client);
    }
}

void ClientRepository::remove(const ClientPtr client)
{
    if (client != nullptr)
    {
        for (auto it = clientRepositoryList.begin(); it != clientRepositoryList.end(); ++it)
        {
            if (*it == client)
            {
                clientRepositoryList.erase(it);
                break;
            }
        }
    }
}

const string ClientRepository::report() const
{
    string s = "";
    for (const auto& client : clientRepositoryList)
    {
        s += client->getClientInfo();
    }
    return s;
}

const int ClientRepository::getSize() const
{
    return clientRepositoryList.size();
}

const vector<ClientPtr> ClientRepository::getAll() const
{
    return clientRepositoryList;
}
*/