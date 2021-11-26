#ifndef PHONE_H
#define PHONE_H

#include <QString>

class PhoneType
{
public:
    PhoneType() = delete;
    PhoneType(const QString& phone);

    const QString& getPhone() const;

private:
    QString phone_;

    void validate();
};

#endif // PHONE_H
