#ifndef STREET_H
#define STREET_H

#include <QString>

class Street
{
public:
    Street();
    Street(const QString& street);

    const QString& getStreet() const;

private:
    QString street_;
};

#endif // STREET_H
