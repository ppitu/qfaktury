#include "HouseNumber.h"

HouseNumber::HouseNumber() :
    houseNumber_("")
{

}

HouseNumber::HouseNumber(const QString& houseNumber) :
    houseNumber_(houseNumber)
{

}

const QString &HouseNumber::getHouseNumber() const
{
    return houseNumber_;
}
