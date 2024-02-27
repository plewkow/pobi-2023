//
// Created by student on 11.06.23.
//
#include <vector>
#include "managers/ItemManager.h"
#include "exceptions/ParameterException.h"
#include "iostream"
#include <fstream>
#include "model/Music.h"
#include "model/Movie.h"
#include "model/Comics.h"
#include "model/Item.h"
#include "repositories/Repository.h"

using namespace std;

ItemManager::ItemManager(ItemRepositoryPtr repo)
        :
        itemRepo(repo)
{
    if (repo==nullptr) { throw ParameterException("RepositoryPtr cant be nullptr!"); }
}

ItemManager::~ItemManager(){}

const string ItemManager::report() const{
    return itemRepo->report();
}
const vector<ItemPtr> ItemManager::getAll() const
{
    return itemRepo->getAll();
}
ItemPtr ItemManager::registerMusic(const string &itemId, const int &cena, const string &nazwa, const bool &vinyl,musicGenre genre){
    ItemPtr nowy=make_shared<Music>(itemId,cena,nazwa,vinyl,genre);
    itemRepo->add(nowy);
    return nowy;
    //ClientRepository w metodzie add sprawdza czy client o takim id przypadkiem juz nie istnieje w repozytorium
}
ItemPtr ItemManager::registerMovie(const string &itemId, const int &cena, const string &nazwa, const int &minutes,const bool &casette,movieGenre genre ){
    ItemPtr nowy=make_shared<Movie>(itemId,cena,nazwa,minutes,casette,genre);
    itemRepo->add(nowy);
    return nowy;
    //ClientRepository w metodzie add sprawdza czy client o takim id przypadkiem juz nie istnieje w repozytorium
}
ItemPtr ItemManager::registerComics(const string &itemId, const int &cena, const string &nazwa, const int &pages){
    ItemPtr nowy=make_shared<Comics>(itemId,cena,nazwa,pages);
    itemRepo->add(nowy);
    return nowy;
    //ClientRepository w metodzie add sprawdza czy client o takim id przypadkiem juz nie istnieje w repozytorium
}
void ItemManager::removeItem(const string &id)
{
    itemRepo->remove(itemRepo->find(id));
}

const ItemPtr ItemManager::find(const string &id) const
{
    return itemRepo->find(id);
}
const vector<ItemPtr> ItemManager::getAllAvilable() const{
    vector<ItemPtr> znalezione;
            for(int i=itemRepo->getAll().size()-1;i>=0;i--)
            {
                if(itemRepo->getAll()[i]->isRented()==false)
                    znalezione.push_back(itemRepo->getAll()[i]);
            }
            return znalezione;

}
const vector<ItemPtr> ItemManager::getAllNotAvilable() const{
    vector<ItemPtr> znalezione;
    for(int i=itemRepo->getAll().size()-1;i>=0;i--)
    {
        if(itemRepo->getAll()[i]->isRented()==true)
            znalezione.push_back(itemRepo->getAll()[i]);
    }
    return znalezione;
}

void ItemManager::saveToFile(const std::string &str, const std::string &filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << str;
        file.close();
    } else {
        std::cout << "Nie można otworzyć pliku: " << filename << std::endl;
    }
}