//
// Created by student on 31.05.23.
//
#include <vector>
#include "managers/ClientManager.h"
#include "exceptions/ParameterException.h"
#include <fstream>
#include <iostream>
#include "model/Client.h"
#include "repositories/Repository.h"

using namespace std;

ClientManager::ClientManager(ClientRepositoryPtr repo)
:
clientRepo(repo)
{
    if (repo==nullptr) { throw ParameterException("RepositoryPtr cant be nullptr!"); }
}

ClientManager::~ClientManager(){}

const string ClientManager::report() const{
    return clientRepo->report();
}
const vector<ClientPtr> ClientManager::getAll() const
{
    return clientRepo->getAll();
}
ClientPtr ClientManager::registerClient(const string &Imie,const string &Nazwisko,const string &id, ClientTypePtr clientType)
{
    ClientPtr nowy=make_shared<Client>(Imie,Nazwisko,id,clientType);
    clientRepo->add(nowy);
    //ClientRepository w metodzie add sprawdza czy client o takim id przypadkiem juz nie istnieje w repozytorium
return nowy;
}
const ClientPtr ClientManager::find(string const &id) const
{
    return clientRepo->find(id);
}

void ClientManager::saveToFile(const std::string &str, const std::string &filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << str;
        file.close();
    } else {
        cout << "Nie można otworzyć pliku: " << filename << std::endl;
    }
}