//
// Created by student on 11.06.23.
//

#ifndef SHAREDPROJECT_ITEMMANAGER_H
#define SHAREDPROJECT_ITEMMANAGER_H

#include <string>
#include <vector>
#include <model/typedefs.h>
#include "repositories/Repository.h"
#include "model/Music.h"
#include "model/Movie.h"
#include "model/Comics.h"
#include "model/Item.h"



class ItemManager
{
    ItemRepositoryPtr itemRepo;
public:
    ItemManager(ItemRepositoryPtr repo);
    ~ItemManager();
    const string report() const;
    const vector<ItemPtr> getAll() const;
    ItemPtr registerMusic(const string &itemId, const int &cena, const string &nazwa, const bool &vinyl,musicGenre genre);
    ItemPtr registerMovie(const string &itemId, const int &cena, const string &nazwa, const int &minutes,const bool &casette,movieGenre genre );
    ItemPtr registerComics(const string &itemId, const int &cena, const string &nazwa, const int &pages);
    void removeItem(const string &id);
    const ItemPtr find(const string &id) const;
    const vector<ItemPtr> getAllAvilable() const;
    const vector<ItemPtr> getAllNotAvilable() const;
    void saveToFile(const std::string& str, const std::string& filename);
};


#endif //SHAREDPROJECT_ITEMMANAGER_H
