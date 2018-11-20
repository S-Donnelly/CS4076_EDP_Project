#include "mybuttons.h"
#include <QPushButton>
using namespace std;
#include <iostream>

myButtons::myButtons()
{
    upButton = new QPushButton("&Up");
    downButton = new QPushButton("&Down");
    leftButton = new QPushButton("&Left");
    rightButton = new QPushButton("&Right");
    useButton = new QPushButton("&Use");
    increase = new QPushButton("&+");
    decrease = new QPushButton("&-");
    submit = new QPushButton("&Submit");
    useItem = new QPushButton("&Use Item");

}
