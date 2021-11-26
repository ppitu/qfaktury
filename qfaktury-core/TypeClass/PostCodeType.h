#ifndef POSTCODE_H
#define POSTCODE_H

#include <QString>

class PostCodeType
{
public:
    PostCodeType();
    PostCodeType(QString postCode);

    const QString& getPostCode() const;

private:
    QString postCode_;

    void validate(QString value);
};

#endif // POSTCODE_H
