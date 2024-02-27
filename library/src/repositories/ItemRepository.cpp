//
// Created by student on 01.06.23.
//
/*
#include <string>
#include "repositories/ItemRepository.h"
#include <model/typedefs.h>
#include "exceptions/LogicException.h"
using namespace std;


ItemRepository::ItemRepository()
{

}
ItemRepository::~ItemRepository()
{

}
const ItemPtr ItemRepository::find(const string &id) const
{
    int i=itemRepositoryList.size()-1;
    for(i;i>=0;i--)
    {
        if(itemRepositoryList[i]->getItemId()==id)
            return itemRepositoryList[i];
    }
    return NULL;
}
const ItemPtr ItemRepository::get(const int &i) const
{
    if(i>=itemRepositoryList.size())
        return NULL;
    return itemRepositoryList[i];
}
void ItemRepository::add(const ItemPtr item)
{
    if(item!=NULL) {
        if (!(this->find(item->getItemId()) == NULL)) {
            throw LogicException("Item with this ID already exists in repository");
        }

        itemRepositoryList.push_back(item);
    }
}
void ItemRepository::remove(const ItemPtr item)
{
    if(item!=NULL)
    {
        int i=itemRepositoryList.size()-1;
        for(i;i>=0;i--)
        {
            if(itemRepositoryList[i]==item)
                itemRepositoryList.erase(itemRepositoryList.begin()+i);
        }
    }
}
const string ItemRepository::report() const
{
    string s="";
    int i=itemRepositoryList.size()-1;
    for(i;i>=0;i--)
    {
        s+=get(i)->getItemInfo();
    }
    return s;
}
const int ItemRepository::getSize() const
{
    return itemRepositoryList.size();
}
const vector<ItemPtr> ItemRepository::getAll() const
{
    return itemRepositoryList;
}
 */
 /*
#include "repositories/ItemRepository.h"


ItemRepository::ItemRepository() {}

ItemRepository::~ItemRepository() {}*/
/*
#include <string>
#include "repositories/ItemRepository.h"
#include <model/typedefs.h>
#include "exceptions/LogicException.h"

using namespace std;

ItemRepository::ItemRepository()
{

}

ItemRepository::~ItemRepository()
{

}

const ItemPtr ItemRepository::find(const string &id) const
{
    for (const auto& item : itemRepositoryList)
    {
        if (item->getItemId() == id)
            return item;
    }
    return nullptr;
}

const ItemPtr ItemRepository::get(const int &i) const
{
    if (i >= itemRepositoryList.size())
        return nullptr;
    return itemRepositoryList[i];
}

void ItemRepository::add(const ItemPtr item)
{
    if (item != nullptr)
    {
        if (find(item->getItemId()) != nullptr)
        {
            throw LogicException("Item with this ID already exists in repository");
        }
        itemRepositoryList.push_back(item);
    }
}

void ItemRepository::remove(const ItemPtr item)
{
    if (item != nullptr)
    {
        for (auto it = itemRepositoryList.begin(); it != itemRepositoryList.end(); ++it)
        {
            if (*it == item)
            {
                itemRepositoryList.erase(it);
                break;
            }
        }
    }
}

const string ItemRepository::report() const
{
    string s = "";
    for (const auto& item : itemRepositoryList)
    {
        s += item->getItemInfo();
    }
    return s;
}

const int ItemRepository::getSize() const
{
    return itemRepositoryList.size();
}

const vector<ItemPtr> ItemRepository::getAll() const
{
    return itemRepositoryList;
}

*/