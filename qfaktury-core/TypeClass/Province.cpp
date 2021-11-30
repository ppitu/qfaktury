#include "Province.h"

Province::Province() :
    province_("")
{

}

Province::Province(const QString& province) :
    province_(province)
{

}

const QString &Province::getProvince() const
{
    return province_;
}
