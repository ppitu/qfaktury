#ifndef COUNTY_H
#define COUNTY_H

#include <QString>

class County
{
public:
    County();
    County(const QString& county);

    const QString& getCounty() const;

private:
    QString county_;
};

#endif // COUNTY_H
