#include "player_inventory.h"
#include <algorithm>


player_Inventory::player_Inventory()
{

}
void player_Inventory::addToInventory(item *anItem)
{
    inventory.push_back(anItem);
}
void player_Inventory::removeFromInventory(item *anItem)
{
    inventory.erase(remove(inventory.begin(), inventory.end(), anItem), inventory.end());
}
