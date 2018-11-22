#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QtWidgets>
#include <QVariant>
#include <stdlib.h>
#include <iostream>
using namespace std;

MainWindow::MainWindow()
{
    cout << "here" << endl;
    potion *healthPotion = new potion("Health Potion", 2, 5.0);
    player = new character();
    gameLayout = new UI_Layout();
    gameLayout->makeUI();
    gameLayout->getMainScene()->addItem(player->aPlayer);
    gameLayout->healthVal->setText(QVariant(player->getHealth()).toString());
    setCentralWidget(gameLayout);
    player->getInventory()->addToInventory(healthPotion);
    for(int i = 0; i <player->inventory->getInventory().size(); i++)
    {
        gameLayout->inventory->addItem(player->inventory->getInventory()[i]->getDescription());

    }
    gameLayout->inventory->addItem(healthPotion->getDescription());
    connect(gameLayout->buttons->upButton, &QPushButton::clicked, this, &MainWindow::handleUpButton);
    connect(gameLayout->buttons->downButton, &QPushButton::clicked, this, &MainWindow::handleDownButton);
    connect(gameLayout->buttons->leftButton, &QPushButton::clicked, this, &MainWindow::handleLeftButton);
    connect(gameLayout->buttons->rightButton, &QPushButton::clicked, this, &MainWindow::handleRightButton);
    connect(gameLayout->buttons->submit, &QPushButton::clicked, this, &MainWindow::handleSubmitButton);
    connect(gameLayout->buttons->useItem, &QPushButton::clicked, this, &MainWindow::handleUseItemButton);
    connect(gameLayout->buttons->useButton, &QPushButton::clicked, this, &MainWindow::handleUseButton);
    connect(gameLayout->buttons->increase, &QPushButton::clicked, this, &MainWindow::handleIncreaseButton);
    connect(gameLayout->buttons->decrease, &QPushButton::clicked, this, &MainWindow::handleDecreaseButton);
}
void MainWindow::handleUpButton()
{
    if (player->aPlayer->y() + 50 > 0)
        player->aPlayer->setPos(player->aPlayer->x(), player->aPlayer->y() - 50);
}
void MainWindow::handleDownButton()
{
    if (player->aPlayer->pos().y() + 200 < 500)
        player->aPlayer->setPos(player->aPlayer->pos().x(), player->aPlayer->pos().y() + 50);
}
void MainWindow::handleLeftButton()
{
    if (player->aPlayer->pos().x() + 50 > 0)
        player->aPlayer->setPos(player->aPlayer->pos().x() - 50, player->aPlayer->pos().y());
}
void MainWindow::handleRightButton()
{
    if (player->aPlayer->pos().x() + 200 < 500)
        player->aPlayer->setPos(player->aPlayer->pos().x() + 50, player->aPlayer->pos().y());
}
void MainWindow::handleSubmitButton()
{
    if(gameLayout->usernameVal->text() != "")
    {
        gameLayout->usernameVal->setReadOnly(true);
        gameLayout->buttons->submit->setDisabled(true);
    }
}
void MainWindow::handleUseItemButton()
{
    if(gameLayout->inventory->currentText() == "Health Potion" && player->getHealth() < 100)
    {
        player->increaseHealth();
        gameLayout->txt->append("You Used " + gameLayout->inventory->currentText());
        gameLayout->inventory->removeItem(gameLayout->inventory->currentIndex());
        gameLayout->healthVal->setText(QVariant(player->getHealth()).toString());
    }
    else if(gameLayout->inventory->currentText() == "Mana Potion")
    {
        gameLayout->txt->append("You Used " + gameLayout->inventory->currentText());
        gameLayout->inventory->removeItem(gameLayout->inventory->currentIndex());
    }
    else if (gameLayout->inventory->currentText() == "")
        gameLayout->txt->append("Inventory is Empty");
    else
        gameLayout->txt->append("You Used " + gameLayout->inventory->currentText());
}
void MainWindow::handleUseButton()
{
    int randnum = rand() % 3 + 1;
    item* newItem;
    switch(randnum)
    {
        case 1: newItem = new potion("Health Potion", 2, 5.0); break;
        case 2: newItem = new weapons("Sword" , 8, 10.0); break;
        case 3: newItem = new potion("Mana Potion", 2, 5.0);
    }
    player->inventory->addToInventory(newItem);
    gameLayout->txt->append(newItem->getDescription() + " Has been added to your inventory");
    gameLayout->inventory->addItem(newItem->getDescription());
}
void MainWindow::handleIncreaseButton()
{
    player->increaseHealth();
    gameLayout->healthVal->setText(QVariant(player->getHealth()).toString());
}
void MainWindow::handleDecreaseButton()
{
    player->decreaseHealth();
    gameLayout->healthVal->setText(QVariant(player->getHealth()).toString());
}


