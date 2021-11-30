#ifndef CITY_H
#define CITY_H

#include <QString>

class City
{
public:
    City();
    City(const QString& city);

    const QString& getCity() const;

private:
    QString city_;
};

#endif // CITY_H
