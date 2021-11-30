#include "City.h"

City::City() :
    city_("")
{

}

City::City(const QString& city) :
    city_(city)
{

}

const QString &City::getCity() const
{
    return city_;
}
