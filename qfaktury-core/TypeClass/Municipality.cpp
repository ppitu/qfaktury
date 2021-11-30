#include "Municipality.h"

Municipality::Municipality() :
    municipality_("")
{

}

Municipality::Municipality(const QString& municipality) :
    municipality_(municipality)
{

}

const QString &Municipality::getMunicipality() const
{
    return municipality_;
}
