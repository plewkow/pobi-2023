//
// Created by student on 01.06.23.
//

#ifndef SHAREDPROJECT_ITEMREPOSITORY_H
#define SHAREDPROJECT_ITEMREPOSITORY_H
/*
#include <string>
#include <vector>
#include <model/typedefs.h>
#include <model/Item.h>

using namespace std;

class Item;

class ItemRepository
{
private:
    mutable vector <ItemPtr> itemRepositoryList;
public:
    ItemRepository();
    ~ItemRepository();
    const ItemPtr find(const string &i) const;
    void add(const ItemPtr item);
    void remove(const ItemPtr item);
    const ItemPtr get(const int &id) const;
    const string report() const;
    const int getSize() const;
    const vector<ItemPtr> getAll() const;

    //vector<ItemPtr> findBy(ItemPredicate predicate) const;
   // bool findAll(const ItemPtr &ptr);
};

/*
#include "repositories/Repository.h"

#include <model/typedefs.h>
class Item;
class ItemRepository : public Repository<ItemPtr> {
public:
   ItemRepository();
    ~ItemRepository();
};

*/
#endif //SHAREDPROJECT_ITEMREPOSITORY_H
