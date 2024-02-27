#include <iostream>
#include <repositories/StorageContainer.h>
#include <managers/ClientManager.h>
#include <managers/ItemManager.h>
#include <managers/RentManager.h>
#include <repositories/Repository.h>
#include "model/Client.h"
#include "model/ClientType.h"
#include "model/DiamondMembership.h"
#include "model/Music.h"
#include "model/Item.h"
#include "model/typedefs.h"
#include <boost/date_time.hpp>
#include "menu/TerminalMenu.h"




namespace pt = boost::posix_time;
namespace gr = boost::gregorian;
using namespace std;

int main() {
    //StorageContainer c;
    //ClientRepository repo =c.getClientRepository();\

    /*ClientRepositoryPtr cr= std::make_shared<ClientRepository>();
    ClientManager cm(cr);
    ItemRepositoryPtr ir= std::make_shared<ItemRepository>();
    ItemManager im(ir);
    RentRepositoryPtr rr= std::make_shared<RentRepository>();
    RentManager rm(rr);
    ClientTypePtr type =make_shared<DiamondMembership>();
    ClientPtr client=cm.registerClient("jan","Kowalski","123",type);
    cout<<cm.report()<<endl;
    ItemPtr item=im.registerMusic("123",23,"kizo",true,HipHop);
    cout<<im.report()<<endl;
    RentPtr rent=rm.rentItem(client,item,"3214",pt::not_a_date_time);
    cout<<rm.report()<<endl;
    rm.returnItem(item,pt::ptime(gr::date(2025,7,13),pt::hours(9)+pt::minutes(25)));
    cout<<rm.report()<<endl;*/
    ClientRepositoryPtr clientRepo = make_shared<Repository<ClientPtr>>();
    ClientManagerPtr clientManager = std::make_shared<ClientManager>(clientRepo);

    ItemRepositoryPtr itemRepo = make_shared<Repository<ItemPtr>>();
    ItemManagerPtr itemManager = std::make_shared<ItemManager>(itemRepo);

    RentRepositoryPtr rentRepo = make_shared<Repository<RentPtr>>();
    RentManagerPtr rentManager = std::make_shared<RentManager>(rentRepo);

    TerminalMenu menu(clientManager, itemManager, rentManager);

    menu.start();

    return 0;
}