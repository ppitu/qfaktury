#ifndef COUNTRY_H
#define COUNTRY_H

#include <QString>

class Country
{
public:
    Country();
    Country(const QString& country);

    const QString& getCountry() const;

private:
    QString country_;
};

#endif // COUNTRY_H
