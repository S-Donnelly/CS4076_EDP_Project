#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "potion.h"
#include <QMainWindow>
#include "character.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow();
    character *player;
public slots:
    void handleUpButton();
    void handleDownButton();
    void handleLeftButton();
    void handleRightButton();
    //void handleUseButton();
};

#endif // MAINWINDOW_H
