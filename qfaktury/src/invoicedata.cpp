#include "invoicedata.h"

#include <QObject>

QString InvoiceData::getCustomer() const
{
    return customer;
}

QString InvoiceData::getInvoiceTypeAndSaveNr(int invoiceType)
{
    QString ret = "FVAT";

    switch (invoiceType)
    {
        case 1:
            ret = QString("FVAT");
        break;
        case 2:
            ret = QString("FPro");
        break;
        case 3:
            ret = QString("korekta");
        break;
        case 4:
            ret = QString("FBrutto");
        break;
        case 5:
            ret = QString("kbrutto");
        break;
        case 6:
            ret = QString("rachunek");
        break;
        case 7:
            ret = QString("duplikat");
        break;
        case 8:
            ret = QString("RR");
        break;
        case 9:
            ret = QString("FVAT");
        break;
        case 10:
            ret = QString("RW");
        break;
        default:
            ret = QString("FVAT");
        break;
    }

    return ret;
}

InvoiceData::~InvoiceData()
{

}

int InvoiceData::getInvoiceNameReturnType(QString invoiceType)
{
    if (invoiceType == QString("FVAT"))
        return 1;
    else if (invoiceType == QString("FPro"))
        return 2;
    else if (invoiceType == QString("korekta"))
        return 3;
    else if (invoiceType == QString("FBrutto"))
        return 4;
    else if (invoiceType == QString("kbrutto"))
        return 5;
    else if (invoiceType == QString("rachunek"))
        return 6;
    else if (invoiceType == QString("duplikat"))
        return 7;
    else if (invoiceType == QString("RR"))
        return 8;
    else if (invoiceType == QString("FVAT"))
        return 9;
    else if (invoiceType == QString("RW"))
        return 10;
    else
        return 1;

    return 1;
}
