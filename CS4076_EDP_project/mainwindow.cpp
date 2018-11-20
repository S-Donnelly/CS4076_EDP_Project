#include "mainwindow.h"
#include "ui_layout.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QtWidgets>
#include <iostream>
using namespace std;

MainWindow::MainWindow()
{
    cout << "here" << endl;
    potion *healthPotion = new potion("health", 2, 5.0);
    player = new character();
    UI_Layout *gameLayout = new UI_Layout();
    gameLayout->makeUI();
    gameLayout->getMainScene()->addItem(player->aPlayer);
    setCentralWidget(gameLayout);
    player->getInventory()->addToInventory(healthPotion);
    gameLayout->inventory->addItem(healthPotion->getDescription());
    connect(gameLayout->buttons->upButton, &QPushButton::clicked, this, &MainWindow::handleUpButton);
    connect(gameLayout->buttons->downButton, &QPushButton::clicked, this, &MainWindow::handleDownButton);
    connect(gameLayout->buttons->leftButton, &QPushButton::clicked, this, &MainWindow::handleLeftButton);
    connect(gameLayout->buttons->rightButton, &QPushButton::clicked, this, &MainWindow::handleRightButton);


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
