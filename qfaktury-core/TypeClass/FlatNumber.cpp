#include "FlatNumber.h"

FlatNumber::FlatNumber() :
    flatNumber_("")
{

}

FlatNumber::FlatNumber(const QString& flatNumber) :
    flatNumber_(flatNumber)
{

}

const QString &FlatNumber::getFlatNumber() const
{
    return flatNumber_;
}
