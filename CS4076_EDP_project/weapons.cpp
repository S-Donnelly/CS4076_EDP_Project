#include "weapons.h"

weapons::weapons()
{

}
weapons::weapons(const QString description, const int weight, const double cost)
{
    this->description = description;
    this->weight = weight;
    this->cost = cost;
}
QString weapons::getDescription()
{
    return this->description;
}
int weapons::getWeight()
{
    return this->weight;
}
double weapons::getCost()
{
    return this->cost;
}

