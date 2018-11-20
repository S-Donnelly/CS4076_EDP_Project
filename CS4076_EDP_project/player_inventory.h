#ifndef PLAYER_INVENTORY_H
#define PLAYER_INVENTORY_H
#include "item.h"
#include <vector>
using namespace std;

class player_Inventory
{
public:
    player_Inventory();
    void addToInventory(item*);
    void removeFromInventory(item*);
private:
    vector<item*> inventory;

};

#endif // PLAYER_INVENTORY_H
