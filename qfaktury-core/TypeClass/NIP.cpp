#include "NIP.h"

#include "Exception/NIPException.h"

#include <QRegularExpression>

NIP::NIP(const QString &nip) :
    nip_(nip)
{

}

const QString &NIP::getNIP() const
{
    return nip_;
}

void NIP::validate()
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
