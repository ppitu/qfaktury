#include "PhoneType.h"


PhoneType::PhoneType(const QString &phone) :
    phone_(phone)
{
    validate();
}

const QString &PhoneType::getPhone() const
{
    return phone_;
}

void PhoneType::validate()
{
    // TODO
    // Add validate
}
