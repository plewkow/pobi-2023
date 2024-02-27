//
// Created by student on 30.05.23.
//

#ifndef SHAREDPROJECT_MOVIE_H
#define SHAREDPROJECT_MOVIE_H
#include <model/Item.h>

using namespace std;

enum movieGenre
{
    Historical=1,
    Horror=2,
    SciFi=4,
    Comedy=5,
    Action=6,
};

class Movie :public Item
{
    const int minutes;
    const bool casette;
    const movieGenre genre;
public:
    Movie(const string &itemId, const int &cena, const string &nazwa, const int &minutes, const bool &casette,movieGenre genre);
    ~Movie();
    const string getInfo() const;
    const double getActualPrice() const;
    const int &getMovieMinutes() const;
    const string getMovieGenre() const;
    const bool &isCasette() const;
};
#endif //SHAREDPROJECT_MOVIE_H
