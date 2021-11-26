#include "NIPType.h"

#include "Exception/NIPException.h"

#include <QRegularExpression>

NIPType::NIPType()
{

}

NIPType::NIPType(const QString &nip) :
    nip_(nip)
{

}

const QString &NIPType::getNIP() const
{
    return nip_;
}

void NIPType::validate()
{
    if(nip_.size() != 11)
    {
        throw NIPException();
    }

    QRegularExpression re("\\d\\d\\d\\d\\d\\d\\d\\d\\d\\d\\d");
    QRegularExpressionMatch match = re.match(nip_);

    if(!match.hasMatch())
    {
        throw NIPException();
    }
}
