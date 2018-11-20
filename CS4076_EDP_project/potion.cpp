#include "potion.h"

potion::potion()
{

}
potion::potion(const QString description, const int weight, const double cost)
{
    this->description = description;
    this->weight = weight;
    this->cost = cost;
}
potion::~potion()
{
    delete this;
}
QString potion::getDescription()
{
    return this->description;
}
int potion::getWeight()
{
    return this->weight;
}
double potion::getCost()
{
    return this->cost;
}
