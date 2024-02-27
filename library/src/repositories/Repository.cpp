//
// Created by student on 08.06.23.
//

#include "repositories/Repository.h"
#include "exceptions/LogicException.h"
#include "exceptions/ParameterException.h"
#include "model/Client.h"
#include "model/Item.h"
#include "model/Rent.h"
#include <model/typedefs.h>



using namespace std;

template<class T>
Repository<T>::Repository()  = default;

template<class T> Repository<T>::~Repository() {}


template <class T>
T Repository<T>::find(const string& id) const {
    for (auto it = objects.rbegin(); it != objects.rend(); ++it) {
        if ((*it)->getId() == id)
            return *it;
    }
    return nullptr;
}

template<class T> T Repository<T>::get(const int& i) const {
    if (i >=objects.size())
        return nullptr;
    return objects[i];
}

template<class T> void Repository<T>::add(T item) {
    if (item != nullptr)
        if (!(this->find(item->getId()) == nullptr)) {
            throw LogicException("This ID already exists in repository");
        }

    objects.push_back(item);
}

template<class T> void Repository<T>::remove(T item) {
    if (item != nullptr) {
        int i = objects.size() - 1;
        for (i; i >= 0; i--) {
            if (objects[i] == item)
                objects.erase(objects.begin() + i);
        }
    }
}

template<class T> const string Repository<T>::report() const {
    string s = "";
    int i = objects.size() - 1;
    for (i; i >= 0; i--) {
        s += objects[i]->getInfo();
    }
    return s;
}

template<class T> const int Repository<T>::getSize() const {
    return objects.size();
}
template<class T> const vector<T> Repository<T>::getAll() const
{
    return objects;
}

template
        class Repository<ClientPtr>;

template
class Repository<ItemPtr>;

template
class Repository<RentPtr>;
