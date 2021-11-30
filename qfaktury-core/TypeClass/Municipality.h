#ifndef MUNICIPALITY_H
#define MUNICIPALITY_H

#include <QString>

class Municipality
{
public:
    Municipality();
    Municipality(const QString& municipality);

    const QString& getMunicipality() const;

private:
    QString municipality_;
};

#endif // MUNICIPALITY_H
