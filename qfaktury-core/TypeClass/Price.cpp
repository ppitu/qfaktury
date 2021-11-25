#include "Price.h"


Price::Price(double net, int vat) :
    net_(net),
    vat_(vat),
    gross_(0.00)
{
    calculate();
}

Price::Price() :
    net_(0.00),
    vat_(23),
    gross_(0.00)
{

}

double Price::getNet() const
{
    return net_;
}

void Price::setNet(double newNet)
{
    net_ = newNet;
}

double Price::getGross() const
{
    return gross_;
}

void Price::setGross(double newGorss)
{
    gross_ = newGorss;
}

int Price::getVat() const
{
    return vat_;
}

void Price::setVat(int newVat)
{
    vat_ = newVat;
}

void Price::changeNet(double net)
{
    net_ = net;
    calculate();
}

void Price::changeGross(double gross)
{
    gross_= gross;
    calculate();
}

void Price::chbageVat(int vat)
{
    vat_ = vat;
    calculate();
}

void Price::calculate()
{
    gross_ = net_ + (net_ * (vat_/100.00));
}
