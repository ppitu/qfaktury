/*
 * Const.h
 *
 *  Created on: Apr 11, 2009
 *      Author: moux
 */

#include "detector.h"
#if _pragma_once_support
#pragma once
#endif
#ifndef CONST_H_
#define CONST_H_

// window title names
static const QString s_PROFORMA = QString("Faktura Pro Forma");
static const QString s_INVOICE = QString("Faktura VAT");
static const QString s_BILL = QString("Rachunek");
static const QString s_CORRECTION = QString("Faktura VAT korygująca");
static const QString s_RR = QString("Faktura RR");
static const QString s_WZ = QString("WZ");
static const QString s_RW = QString("RW");

static const QString s_FBRUTTO = QString("Faktura VAT Brutto");
static const QString s_DUPLICATE = QString("Nowy Duplikat");
static const QString s_CORRECT_TITLE = QString("Nowa Korekta");
static const QString s_CORRECT_BRUTTO = QString("Nowa Korekta Brutto");

static const QString s_TIC = QString("NIP: ");

static const QString s_WIN_PRINTPREVIEW = (" - Podgląd wydruku");
static const QString s_WIN_INVOICE_EDIT =
    QString("Edytuje Fakturę VAT");
static const QString s_BR_INVOICE_EDIT =
    QString("Edytuje Fakturę Brutto");
static const QString s_WIN_PROFORMA_EDIT =
    QString("Edytuje Fakturę Pro Forma");
static const QString s_BILL_EDIT = QString("Edytuje Rachunek");
static const QString s_WIN_DUPLICATE_LOOK =
    QString("Sprawdza Duplikat");
static const QString s_WIN_CORRECT_EDIT = QString("Edytuje Korektę");
static const QString s_WIN_WZ_EDIT = QString("Edytuje WZ");
static const QString s_WIN_RW_EDIT = QString("Edytuje RW");

#endif /* CONST_H_ */
