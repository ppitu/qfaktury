#ifndef PHONE_H
#define PHONE_H

#include <QString>

class Phone
{
public:
    Phone() = delete;
    Phone(const QString& phone);

    const QString& getPhone() const;

private:
    QString phone_;

    void validate();
};

#endif // PHONE_H
