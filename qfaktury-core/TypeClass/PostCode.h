#ifndef POSTCODE_H
#define POSTCODE_H

#include <QString>

class PostCode
{
public:
    PostCode();
    PostCode(QString postCode);

    const QString& getPostCode() const;

private:
    QString postCode_;

    void validate(QString value);
};

#endif // POSTCODE_H
