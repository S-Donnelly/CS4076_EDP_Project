#ifndef MYBUTTONS_H
#define MYBUTTONS_H
#include <QPushButton>
#include <QtWidgets>
#include <QWidget>

class myButtons : public QWidget
{
public:
    QPushButton *upButton;
    QPushButton *downButton;
    QPushButton *leftButton;
    QPushButton *rightButton;
    QPushButton *useButton;
    QPushButton *increase;
    QPushButton *decrease;
    QPushButton *submit;
    QPushButton *useItem;
    myButtons();
private slots:
    void handleUpButton();
    void handleDownButton();
    void handleLeftButton();
    void handleRightButton();
    void handleUseButton();
    void handleIncrease();
    void handleDecrease();
    void handleSubmit();
    void handleUseItem();
};

#endif // MYBUTTONS_H
