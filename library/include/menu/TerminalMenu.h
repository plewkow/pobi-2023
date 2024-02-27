//
// Created by student on 07.06.23.
//

#ifndef OOPPROJECT_TERMINALMENU_H
#define OOPPROJECT_TERMINALMENU_H

#include "model/typedefs.h"

class TerminalMenu {
private:
    ClientManagerPtr clientManager;
    ItemManagerPtr itemManager;
    RentManagerPtr rentManager;

public:

    TerminalMenu(const ClientManagerPtr &clientManager, const ItemManagerPtr &itemManager,
                 const RentManagerPtr &rentManager);

    virtual ~TerminalMenu();

    void start();

    void client();

    void item();

    void rent();

    void dump();
};

#endif //OOPPROJECT_TERMINALMENU_H
