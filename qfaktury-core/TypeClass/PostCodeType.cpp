#include "PostCodeType.h"

#include "Exception/PostCodeException.h"

#include <QRegularExpression>

PostCodeType::PostCodeType()
{

}

PostCodeType::PostCodeType(QString postCode) :
    postCode_(postCode)
{
    validate(postCode_);
}

const QString &PostCodeType::getPostCode() const
{
    return postCode_;
}

void PostCodeType::validate(QString value)
{
    if(postCode_.size() != 6)
    {
        throw PostCodeException();
    }

    QRegularExpression re("\\d\\d-\\d\\d\\d");
    QRegularExpressionMatch match = re.match(value);

    if(!match.hasMatch())
    {
        throw PostCodeException();
    }

}
