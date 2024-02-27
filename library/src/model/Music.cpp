//
// Created by student on 30.05.23.
//
#include <model/Music.h>

using namespace std;
string displayEnumMusic(musicGenre genre)
{
    switch (genre)
    {
        case Metal:
            return "Metal";
        case POP:
            return "POP";
        case HipHop:
            return "HipHop";
        case Classical:
            return "Classical";
        case Jazz:
            return "Jazz";
    }
    return "brak gatunku";
}
Music::Music(const string &itemId, const int &cena, const string &nazwa, const bool &vinyl,musicGenre genre)
        :
        Item(itemId,cena,nazwa),
        vinyl(vinyl),
        genre(genre)
{
}
Music::~Music()
{}
const string Music::getInfo() const
{
    string winylowa;
    if(vinyl==true)
        winylowa="tak";
    else
        winylowa="nie";
    return this->Item::getInfo() + " Muzyka:\n Plyta winylowa: " + winylowa + "\n Gatunek: "+ displayEnumMusic(genre) +"\n\n";
}
const double Music::getActualPrice() const
{
    if(vinyl==true)
        return basePrice +30;

    return basePrice*(1+0.1*genre);

}
const string Music::getMusicGenre() const
{
    return displayEnumMusic(genre);
}
const bool& Music::isVinyl() const
{
    return vinyl;
}