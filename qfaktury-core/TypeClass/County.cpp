#include "County.h"

County::County() :
    county_("")
{

}

County::County(const QString& county) :
    county_(county)
{

}

const QString &County::getCounty() const
{
    return county_;
}
