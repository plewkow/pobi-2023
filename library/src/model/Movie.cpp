//
// Created by student on 30.05.23.
//
#include <model/Movie.h>

using namespace std;
string displayEnumMovie(movieGenre genre)
{
    switch (genre)
    {
        case Horror:
            return "Horror";
        case SciFi:
            return "SciFi";
        case Comedy:
            return "Comedy";
        case Historical:
            return "Historical";
        case Action:
            return "Action";
    }
    return "brak gatunku";
}
Movie::Movie(const string &itemId, const int &cena, const string &nazwa, const int &minutes,const bool &casette,movieGenre genre )
        :
        Item(itemId,cena,nazwa),
        minutes(minutes),
        casette(casette),
        genre(genre)
{
}
Movie::~Movie()
{}
const string Movie::getInfo() const
{
    string kaseta;
    if(casette==true)
        kaseta="tak";
    else
        kaseta="nie";
    return this->Item::getInfo() + " Film:\n Film na kasecie: " + kaseta + "\n Dlugosc filmu(min): "+ to_string(minutes) +"\n Gatunek: "+ displayEnumMovie(genre) +"\n\n";
}
const double Movie::getActualPrice() const
{
    if(casette==true)
        return basePrice -5;

    return basePrice*(1+0.1*genre);

}
const string Movie::getMovieGenre() const
{
    return displayEnumMovie(genre);
}
const bool& Movie::isCasette() const
{
    return casette;
}
const int& Movie::getMovieMinutes() const
{
    return minutes;
}
