#include "PostCode.h"

#include "Exception/PostCodeException.h"

#include <QRegularExpression>

PostCode::PostCode(QString postCode) :
    postCode_(postCode)
{
    validate(postCode_);
}

const QString &PostCode::getPostCode() const
{
    return postCode_;
}

void PostCode::validate(QString value)
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
