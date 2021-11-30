#include "Email.h"

Email::Email(const QString &email) :
    email_(email)
{
    validate();
}

const QString &Email::getEmail() const
{
    return email_;
}

void Email::validate()
{
    // TODO
    // Add validation
}
