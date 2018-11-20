#ifndef CHARACTER_H
#define CHARACTER_H
#include <QGraphicsRectItem>
#include <string>
#include "player_inventory.h"
using namespace std;

class character: public QGraphicsRectItem
{
    friend class MainWindow;
    friend class myButtons;
public:
    string name;
    int health;
    character();
    ~character();
    character(string, int);
    int getHealth();
    string getNameOfCharacter();
    void decreaseHealth();
    void increaseHealth();
    void setCharacterName(string);
    player_Inventory * getInventory();

private:
    player_Inventory* inventory;
    QGraphicsRectItem *aPlayer;
};

#endif // CHARACTER_H
