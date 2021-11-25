#include "warehousedata.h"

#include <QObject>

QString WarehouseData::getCustomer() const
{
    return customer;
}

QString WarehouseData::getInvoiceTypeAndSaveNr(int invoiceType)
{
    QString ret = "WZ";

    switch (invoiceType)
    {
        case 9:
            ret = QObject::trUtf8("WZ");
        break;
        case 10:
            ret = QObject::trUtf8("RW");
        break;
        default:
            ret = QObject::trUtf8("WZ");
        break;
    }

    return ret;
}
