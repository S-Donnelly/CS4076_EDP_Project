#include "character.h"

character::character()
{
    inventory = new player_Inventory();
    name;
    health = 100;
    aPlayer = new QGraphicsRectItem(100,100,50,50);
}
character::~character()
{
    delete aPlayer;
}
character::character(string name, int size)
{
    this->name = name;
    aPlayer = new QGraphicsRectItem(50,50,size,size);

}
int character::getHealth()
{
    return health;
}
string character::getNameOfCharacter()
{
    return name;
}
void character::setCharacterName(string name)
{
    this->name = name;
}
void character::decreaseHealth()
{
    health -= 5;
}
void character::increaseHealth()
{
    if (health != 100)
        health += 5;
}
player_Inventory * character::getInventory()
{
    return inventory;
}
