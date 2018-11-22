#ifndef WEAPONS_H
#define WEAPONS_H
#include "item.h"

class weapons : public item
{
public:
    weapons();
    weapons(const QString, const int, const double);
    QString getDescription();
    double getCost();
    int getWeight();
};

#endif // WEAPONS_H
