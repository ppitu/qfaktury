#include "Phone.h"


Phone::Phone(const QString &phone) :
    phone_(phone)
{
    validate();
}

const QString &Phone::getPhone() const
{
    return phone_;
}

void Phone::validate()
{
    // TODO
    // Add validate
}
