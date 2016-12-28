#ifndef Korekta_H
#define Korekta_H
#include <QDialog>
#include <QComboBox>

#include "ui_Faktura.h"

#include "Faktura.h"
#include "ConvertAmount.h"
#include "Settings.h"
#include "InvoiceData.h"


class Korekta: public Faktura {

Q_OBJECT

public:

    Korekta(QWidget *parent, IDataLayer *dl, QString in_form = QString(), bool edMode = false);
	virtual ~Korekta();
    bool const getMode() const;
    bool const getFirstRun() const;
    QString const getRet() const;
    void schemaCalcSum();
    virtual void korektaInit(bool mode);
	virtual void readCorrData(QString fraFile);


public slots:

	// to be overwritten in child class
	virtual void backBtnClick();
	virtual bool saveInvoice();
	virtual void makeInvoice();
    virtual void canQuit();


protected:

	virtual void makeInvoiceSummAll();
	virtual void makeInvoiceSumm();
	virtual void makeInvoceProductsTitle(short a);
	virtual void makeBeforeCorrProducts();
	virtual void makeBeforeCorrSumm();
	InvoiceData *createOriginalInv();
	virtual void setIsEditAllowed(bool isAllowed);
	virtual void calculateDiscount();
	virtual void calculateSum();
	virtual void calculateOneDiscount(int i);
	virtual QString getInvoiceTypeAndSaveNr();


private:

    double origGrossBureau;
    bool editMode;
    bool firstRunned;
    double origDiscTotal, origNettTotal, origGrossTotal;
    double diffTotal;
    InvoiceData *invData;
    QComboBox *reasonCombo;
    QLabel *labelReason1;
    QString ret, fName;

};
#endif
