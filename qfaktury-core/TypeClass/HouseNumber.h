#ifndef HOUSENUMBER_H
#define HOUSENUMBER_H

#include <QString>

class HouseNumber
{
public:
    HouseNumber();
    HouseNumber(const QString& houseNumber);

    const QString& getHouseNumber() const;

private:
    QString houseNumber_;
};

#endif // HOUSENUMBER_H
