//
// Created by student on 08.06.23.
//

#ifndef SHAREDPROJECT_REPOSITORY_H
#define SHAREDPROJECT_REPOSITORY_H
#include <string>
#include <vector>
#include "model/typedefs.h"

using namespace std;

template<class T> class Repository {
protected:
    vector<T> objects;
public:
    Repository();
    virtual ~Repository();

    T find(const string& id) const;
    T get(const int& i) const;
    void add(T item);
    void remove(T item);
    const string report() const;
    const int getSize() const;
    const vector<T> getAll() const;

};


#endif //SHAREDPROJECT_REPOSITORY_H

