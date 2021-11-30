#include "Country.h"

Country::Country() :
    country_("")
{

}

Country::Country(const QString& country) :
    country_(country)
{

}

const QString &Country::getCountry() const
{
    return country_;
}
