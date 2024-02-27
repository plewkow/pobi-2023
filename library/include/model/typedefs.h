//
// Created by student on 29.05.23.
//

#ifndef SHAREDPROJECT_TYPEDEFS_H
#define SHAREDPROJECT_TYPEDEFS_H
#include <memory>


using namespace std;

class Client;
class Item;
class Rent;
class ClientType;
template<class T>
class Repository;
//class ClientRepository;
//class ItemRepository;
//class RentRepository;


//class NoMembership;
//class Membership;
//class DiamondMembership;

class ClientManager;
class ItemManager;
class RentManager;


typedef shared_ptr<Client> ClientPtr;
typedef shared_ptr<Item>  ItemPtr;
typedef shared_ptr<Rent> RentPtr;
typedef shared_ptr<ClientType> ClientTypePtr;

//typedef bool (*ClientPredicate)(ClientPtr);
//typedef bool (*RentPredicate)(RentPtr);
//typedef bool (*ItemPredicate)(ItemPtr);


typedef std::shared_ptr<Repository<ClientPtr>> ClientRepositoryPtr;
typedef std::shared_ptr<Repository<ItemPtr>> ItemRepositoryPtr;
typedef std::shared_ptr<Repository<RentPtr>> RentRepositoryPtr;
// predicates
//typedef std::function<bool(ClientPtr)> ClientPredicate;
//typedef std::function<bool(ItemPtr)> ItemPredicate;
//typedef std::function<bool(RentPtr)> RentPredicate;

// managars smart pointers
typedef std::shared_ptr<ClientManager> ClientManagerPtr;
typedef std::shared_ptr<ItemManager> ItemManagerPtr;
typedef std::shared_ptr<RentManager> RentManagerPtr;
#endif //SHAREDPROJECT_TYPEDEFS_H
