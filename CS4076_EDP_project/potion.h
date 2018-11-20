#ifndef POTION_H
#define POTION_H
#include "item.h"

class potion : public item
{
public:
    potion();
    potion(const QString, const int, const double);
    virtual ~potion();
    QString getDescription();
    double getCost();
    int getWeight();
};

#endif // POTION_H
