#ifndef ITEMS_H
#define ITEMS_H
#include <string>
#include <QString>
using namespace std;

class item
{
public:
    virtual QString getDescription() = 0;
    virtual int getWeight() = 0;
    virtual double getCost() = 0;
protected:
    QString description;
    int weight;
    double cost;
};

#endif // ITEMS_H
