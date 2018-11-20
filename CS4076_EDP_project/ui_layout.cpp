#include "ui_layout.h"
#include <QApplication>
#include "mainwindow.h"
#include <iostream>
#include "mybuttons.h"
using namespace std;


UI_Layout::UI_Layout()
{
    inventory = new QComboBox();
    buttons = new myButtons();
    mainScene = new QGraphicsScene(0,0,500,500);
    mainView = new QGraphicsView();
    mainLayout = new QGridLayout();
    buttonLayout = new QGridLayout();
    statsLayout = new QGridLayout();
    utilityLayout = new QGridLayout();

}
UI_Layout::~UI_Layout()
{
    delete mainScene;
    delete mainView;
    delete mainLayout;
    delete buttonLayout;
    delete statsLayout;
}
void UI_Layout::makeUI()
{

    mainView->setScene(mainScene);
    mainLayout->addWidget(mainView,0,0);
    mainLayout->addLayout(buttonLayout,1,0);
    utilityLayout->addLayout(statsLayout,0,0);
    mainLayout->addLayout(utilityLayout,0,1);
    buttonLayout->addWidget(buttons->upButton, 0,1);
    buttonLayout->addWidget(buttons->leftButton, 1,0);
    buttonLayout->addWidget(buttons->useButton, 1,1);
    buttonLayout->addWidget(buttons->rightButton, 1,2);
    buttonLayout->addWidget(buttons->downButton, 2,1);
    createStatsLayout();
    mainView->setFixedSize(500,500);
    mainView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mainView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setLayout(mainLayout);
    mainView->show();

}
//returns the main scene object
QGraphicsScene* UI_Layout::getMainScene()
{
    return mainScene;
}
//returns the main view object
QGraphicsView* UI_Layout::getMainView()
{
    return mainView;
}
//returns the main layout
QGridLayout* UI_Layout::getMainLayout()
{
    return mainLayout;
}
QGridLayout* UI_Layout::getButtonLayout()
{
    return buttonLayout;
}
QGridLayout* UI_Layout::getStatsLayout()
{
    return statsLayout;
}
void UI_Layout::createStatsLayout()
{
    username = new QLabel("Username  :");
    health = new QLabel("Hit Points:");
    level = new QLabel("Level     :");
    inven = new QLabel("-----Inventory-----");
    usernameVal = new QLineEdit();
    healthVal = new QLineEdit();
    levelVal = new QLineEdit("1");
    statsLayout->addWidget(username, 0,0);
    statsLayout->addWidget(health,1,0);
    statsLayout->addWidget(level,2,0);
    statsLayout->addWidget(usernameVal,0,1);
    statsLayout->addWidget(healthVal,1,1);
    statsLayout->addWidget(levelVal,2,1);
    statsLayout->addWidget(inven,3,1);
    statsLayout->addWidget(inventory,4,1);
    statsLayout->addWidget(buttons->increase,1,2);
    statsLayout->addWidget(buttons->decrease,1,3);
    statsLayout->addWidget(buttons->submit,0,2);
    statsLayout->addWidget(buttons->useItem,4,2);
    QTextEdit *txt = new QTextEdit();
    statsLayout->addWidget(txt,5,1);


}
