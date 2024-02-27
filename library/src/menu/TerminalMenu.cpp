//
// Created by student on 07.06.23.
//

#include "menu/TerminalMenu.h"

#include <iostream>

#include "exceptions/ParameterException.h"
#include "exceptions/LogicException.h"

#include "managers/ClientManager.h"
#include "managers/ItemManager.h"
#include "managers/RentManager.h"
#include "model/typedefs.h"
#include "model/Music.h"
#include "model/Movie.h"
#include "model/Comics.h"

#include "model/Client.h"
#include "model/Item.h"
#include "model/Rent.h"
#include "model/ClientType.h"
#include <model/DiamondMembership.h>
#include <model/Membership.h>
#include <model/NoMembership.h>
#include <fstream>

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

using namespace std;

TerminalMenu::TerminalMenu(const ClientManagerPtr &clientManager, const ItemManagerPtr &itemManager,
                           const RentManagerPtr &rentManager) : clientManager(clientManager), itemManager(itemManager),
                                                                rentManager(rentManager) {}

TerminalMenu::~TerminalMenu() {

}

void TerminalMenu::start() {
    cout << "Witaj w systemie wypozyczalni!" << endl;

    bool exit = false;
    while (!exit) {
        cout
                << "==================================" << endl
                << "1. Zarzadzaj klientami" << endl
                << "2. Zarzadzaj itemami" << endl
                << "3. Zarzadzaj wynajmem" << endl
                << "4. Zapisz na dysk" << endl
                << "0. Zakoncz program" << endl
                << "==================================" << endl;

        char input;
        cin >> input;

        switch (input) {
            // 1. Zarzadzaj klientami
            case '1':
                client();
                break;

                // 2. Zarzadzaj itemami
            case '2':
                item();
                break;

                // 3. Zarzadzaj wynajmem
            case '3':
                rent();
                break;
            case '4':
                dump();
                break;
                // 0. Zakoncz program
            case '0':
                exit = true;
                break;

            default:
                cout << "Bledny wybor!" << endl;
                break;
        }
    }
}

void TerminalMenu::client() {
    bool exit = false;
    while (!exit) {
        cout
                << "==================================" << endl
                << "1. Zarejestruj nowego klienta" << endl
                << "2. Wyswietl informacje o kliencie" << endl
                << "3. Wyswietl informacje o wszystkich klientach" << endl
                << "0. Powrot do menu" << endl
                << "==================================" << endl;

        char input;
        cin >> input;

        switch (input) {
            // 1. Zarejestruj nowego klienta
            case '1': {
                string firstName, lastName, personalID, t, n, m, d;
                shared_ptr<ClientType> Type;

                cout << "Podaj imie: ";
                cin.ignore();
                getline(cin, firstName);
                cout << "Podaj nazwisko: ";
                getline(cin, lastName);
                cout << "Podaj numer pesel: ";
                cin >> personalID;
                cout << "Podaj typ Clienta(n - NoMembership, m - Membership, d - DiamondMembership): ";
                cin >> t;
                if(t == "n")
                {
                    Type = make_shared<NoMembership>();
                }
                else if (t == "m") {
                    Type = make_shared<Membership>();
                }
                else if(t == "d") {
                    Type = make_shared<DiamondMembership>();
                }

                try {
                    clientManager->registerClient(firstName, lastName, personalID,
                                                  Type);
                } catch (ParameterException &e) {
                    cerr << "Parameter error: " << e.what() << endl;
                } catch (LogicException &e) {
                    cerr << "Logic error: " << e.what() << endl;
                }
                break;

            }

                // 2. Wyswietl informacje o kliencie
            case '2': {
                string personalID;
                cout << "Podaj numer pesel klienta: ";
                cin >> personalID;

                ClientPtr client = clientManager->find(personalID);
                if (client == nullptr) {
                    cout << "Podany klient nie istnieje!" << endl;
                    break;
                }

                cout << client->getInfo() << endl;
                break;
            }

               // 3. Wyswietl informacje o wszystkich klientach
            case '3':{
                cout << clientManager->report() << endl;
                break;
            }

                // 0. Powrot do menu
            case '0':
                exit = true;
                break;

            default:
                cout << "Bledny wybor!" << endl;
                break;
        }
    }
}

void TerminalMenu::item() {
    bool exit = false;
    while (!exit) {
        cout << "==================================" << endl
             << "1. Zarejestruj nowy item" << endl
             << "2. Wyswietl informacje o itemie" << endl
             << "3. Wyswietl informacje o wszystkich itemach" << endl
             << "0. Powrot do menu" << endl
             << "==================================" << endl;

        char input;
        cin >> input;

        switch (input) {
            // 1. Zarejestruj nowy item
            case '1':
            {
                int basePrice;
                string itemID, itemName, t, mu, mo, co;
                cout << "Podaj cene: ";
                cin >> basePrice;
                cout << "Podaj nazwe: ";
                cin >> itemName;
                cout << "Podaj itemID ";
                cin >> itemID;
                cout << "Podaj typ Itemu(mu - music, mo - movie, co - comics): ";
                cin >> t;

                if (t == "mu") {
                    cout << "Winyl?(t)";
                    cin >> mu;
                    if (mu == "t") {
                        cout << "Gatunek? (a - metal, b - pop, c - hiphop, d - classical, e - jazz)";
                        cin >> t;
                        musicGenre genre;
                        if (t == "a")
                            genre = Metal;
                        else if (t == "b")
                            genre = POP;
                        else if (t == "c")
                            genre = HipHop;
                        else if (t == "d")
                            genre = Classical;
                        else if (t == "e")
                            genre = Jazz;
                        else {
                            cerr << "Nieprawidłowy gatunek" << endl;
                            return;
                        }

                        try {
                            itemManager->registerMusic(itemID, basePrice, itemName, true, genre);
                        } catch (ParameterException &e) {
                            cerr << "Błąd parametru: " << e.what() << endl;
                        } catch (LogicException &e) {
                            cerr << "Błąd logiczny: " << e.what() << endl;
                        }
                    } else {
                        cout << "Gatunek? (a - metal, b - pop, c - hiphop, d - classical, e - jazz)";
                        cin >> t;
                        musicGenre genre;
                        if (t == "a")
                            genre = Metal;
                        else if (t == "b")
                            genre = POP;
                        else if (t == "c")
                            genre = HipHop;
                        else if (t == "d")
                            genre = Classical;
                        else if (t == "e")
                            genre = Jazz;
                        else {
                            cerr << "Nieprawidłowy gatunek" << endl;
                            return;
                        }

                        try {
                            itemManager->registerMusic(itemID, basePrice, itemName, false, genre);
                        } catch (ParameterException &e) {
                            cerr << "Błąd parametru: " << e.what() << endl;
                        } catch (LogicException &e) {
                            cerr << "Błąd logiczny: " << e.what() << endl;
                        }
                    }
                } else if (t == "mo") {
                    int dl;
                    cout << "Kaseta?(t)";
                    cin >> mo;
                    if (mo == "t") {

                        cout << "Podaj dlugosc filmu";
                        cin >> dl;
                        cout << "Gatunek? (a - horror, b - scifi, c - comedy, d - historical, e - action)";
                        cin >> t;
                        movieGenre genre;
                        if (t == "a")
                            genre = Horror;
                        else if (t == "b")
                            genre = SciFi;
                        else if (t == "c")
                            genre = Comedy;
                        else if (t == "d")
                            genre = Historical;
                        else if (t == "e")
                            genre = Action;
                        else {
                            cerr << "Nieprawidłowy gatunek" << endl;
                            return;
                        }

                        try {
                            itemManager->registerMovie(itemID, basePrice, itemName, dl, true, genre);
                        } catch (ParameterException &e) {
                            cerr << "Błąd parametru: " << e.what() << endl;
                        } catch (LogicException &e) {
                            cerr << "Błąd logiczny: " << e.what() << endl;
                        }
                    } else {
                        cout << "Gatunek? (a - horror, b - scifi, c - comedy, d - historical, e - action)";
                        cin >> t;
                        movieGenre genre;
                        if (t == "a")
                            genre = Horror;
                        else if (t == "b")
                            genre = SciFi;
                        else if (t == "c")
                            genre = Comedy;
                        else if (t == "d")
                            genre = Historical;
                        else if (t == "e")
                            genre = Action;
                        else {
                            cerr << "Nieprawidłowy gatunek" << endl;
                            return;
                        }

                        try {
                            itemManager->registerMovie(itemID, basePrice, itemName, dl, false, genre);
                        } catch (ParameterException &e) {
                            cerr << "Błąd parametru: " << e.what() << endl;
                        } catch (LogicException &e) {
                            cerr << "Błąd logiczny: " << e.what() << endl;
                        }
                    }
                } else if (t == "co") {
                    cout << "Ile stron?";
                    int strony;
                    cin >> strony;
                    try {
                        itemManager->registerComics(itemID, basePrice, itemName, strony);
                    } catch (ParameterException &e) {
                        cerr << "Błąd parametru: " << e.what() << endl;
                    } catch (LogicException &e) {
                        cerr << "Błąd logiczny: " << e.what() << endl;
                    }
                } else {
                    cerr << "Błędny typ" << endl;
                    return;
                }
                break;
            }


                // 2. Wyswietl informacje o itemie
            case '2': {
                string itemID;
                cout << "Podaj id itemu: ";
                cin >> itemID;

                ItemPtr item = itemManager->find(itemID);
                if (item == nullptr) {
                    cout << "Item o podanym numerze nie istnieje!" << endl;
                    return;
                }

                cout << item->getInfo() << endl;
                break;
            }

                // 3. Wyswietl informacje o wszystkich itemach
            case '3':
                 cout << itemManager->report() << endl;
                break;

                // 0. Powrot do menu
            case '0':
                exit = true;
                break;

            default:
                cout << "Bledny wybor!" << endl;
                break;
        }
    }
}


void TerminalMenu::rent() {
    bool exit = false;
    while (!exit) {
        cout << "==================================" << endl
             << "1. Wynajmij item" << endl
             << "2. Wyswietl informacje o wynajmnie" << endl
             << "3. Wyswietl informacje o wszystkich wypozyczeniach" << endl
             << "4. Zakoncz wynajem" << endl
             << "5. Wyswietl koszt wypozyczenia" << endl
             << "0. Powrot do menu" << endl
             << "==================================" << endl;

        char input;
        cin >> input;
        string personalID;
        string itemID;
        string rentID;
        switch (input) {
            // 1. Wynajmij item
            case '1': {
                cout << "Podaj numer pesel klienta: ";
                cin >> personalID;

                ClientPtr client = clientManager->find(personalID);
                if (client == nullptr) {
                    cout << "Klient nie istnieje!" << endl;
                    return;
                }

                cout << "Podaj id item: ";
                cin >> itemID;

                ItemPtr item = itemManager->find(itemID);
                if (item == nullptr) {
                    cout << "Nie znaleziono odpowiedniego itemu!" << endl;
                    return;
                }

                cout << "Podaj rent id: ";
                cin >> rentID;
                boost::posix_time::ptime currentTime = boost::posix_time::second_clock::local_time();


                try {
                    rentManager->rentItem(client, item, rentID ,currentTime);
                } catch (ParameterException &e) {
                    cerr << "Błąd parametru: " << e.what() << endl;
                } catch (LogicException &e) {
                    cerr << "Błąd logiczny: " << e.what() << endl;
                }
                break;
            }

                // 2. Wyswietl informacje o wynajmnie
            case '2': {
                string rentId;
                cout << "Podaj numer rentId: ";
                cin >> rentId;

                RentPtr rent = rentManager->find(rentId);
                if (rent == nullptr) {
                    cout <<"Nie ma takiego wynajmu"<< endl;
                    return;
                }

                cout << rent->getInfo() << endl;
                break;
            }
                    // 3. Wyswietl informacje o wszystkich obecnych wypozyczeniach
                case '3':
                    cout << rentManager->report() << endl;
                    break;

                    // 4. Zakoncz wynajem
                case '4': {
                    int number;
                    cout << "Podaj numer itemu: ";
                    cin >> itemID;
                    ItemPtr item = itemManager->find(itemID);
                    if (item == nullptr) {
                        cout << "Nie znaleziono odpowiedniego itemu!" << endl;
                        return;
                    }
                    boost::posix_time::ptime currentTime = boost::posix_time::second_clock::local_time();
                    int rok, dzien, miesiac, godzina, minuta, sekunda;
                    cout << "Podaj rok zakonczenia wypozyczenia: ";
                    cin >> rok;
                    cout << "Podaj miesiac zakonczenia wypozyczenia: ";
                    cin >> dzien;
                    cout << "Podaj dzien zakonczenia wypozyczenia: ";
                    cin >> miesiac;
                    cout << "Podaj godzine zakonczenia wypozyczenia: ";
                    cin >> godzina;
                    cout << "Podaj minute zakonczenia wypozyczenia: ";
                    cin >> minuta;
                    cout << "Podaj sekunde zakonczenia wypozyczenia: ";
                    cin >> sekunda;
                    pt::ptime end = pt::ptime(gr::date(rok, miesiac, dzien), pt::hours(godzina)+pt::minutes(minuta)+pt::seconds(sekunda));
                    try {
                        rentManager->returnItem(item, end);
                    } catch (ParameterException &e) {
                        cerr << "Parameter error: " << e.what() << endl;
                    } catch (LogicException &e) {
                        cerr << "Logic error: " << e.what() << endl;
                    }

                    break;

                }
                case '5':{
                    string id;
                    cout << "Podaj rentID: ";
                    cin>> id;

                    RentPtr rent=rentManager->find(id);
                    if(rent==nullptr)
                    {
                        cout<<"Nie ma takiego wypozyczenia"<<endl;
                        break;
                    }
                    try{
                      cout<< rentManager->getRentCost(id)<<" zl" <<endl;
                    }catch (ParameterException &e) {
                        cerr << "Parameter error: " << e.what() << endl;
                    } catch (LogicException &e) {
                        cerr << "Logic error: " << e.what() << endl;
                    }

                }

                // 0. Powrot do menu
            case '0':
                exit = true;
                break;

            default:
                cout << "Bledny wybor!" << endl;
                break;
        }
    }
}

void TerminalMenu::dump() {
    string filename;
    cout << "Podaj nazwę pliku do zapisu: ";
    cin >> filename;

    ofstream outputFile(filename);
    if (!outputFile) {
        cerr << "Błąd podczas otwierania pliku." << endl;
        return;
    }

    // Zapisz dane klientów
    outputFile << "=== Klienci ===" << endl;
    outputFile << clientManager->report() << endl;

    // Zapisz dane itemów
    outputFile << "=== Itemy ===" << endl;
    outputFile << itemManager->report() << endl;

    // Zapisz dane wypożyczeń
    outputFile << "=== Wypożyczenia ===" << endl;
    outputFile << rentManager->report() << endl;

    outputFile.close();
    cout << "Zapisano dane na dysk." << endl;
}
