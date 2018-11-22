#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "potion.h"
#include <QMainWindow>
#include "character.h"
#include "ui_layout.h"
#include "weapons.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow();
    character *player;
    UI_Layout *gameLayout;
public slots:
    void handleUpButton();
    void handleDownButton();
    void handleLeftButton();
    void handleRightButton();
    //void handleUseButton();
    void handleSubmitButton();
    void handleUseItemButton();
    void handleUseButton();
    void handleIncreaseButton();
    void handleDecreaseButton();
};

#endif // MAINWINDOW_H
