#include "Street.h"

Street::Street() :
    street_("")
{

}

Street::Street(const QString& street) :
    street_(street)
{

}

const QString& Street::getStreet() const
{
    return street_;
}
