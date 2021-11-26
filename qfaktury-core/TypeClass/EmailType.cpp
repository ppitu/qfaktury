#include "EmailType.h"

EmailType::EmailType(const QString &email) :
    email_(email)
{
    validate();
}

const QString &EmailType::getEmail() const
{
    return email_;
}

void EmailType::validate()
{
    // TODO
    // Add validation
}
