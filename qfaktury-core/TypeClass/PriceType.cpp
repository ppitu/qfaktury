#include "PriceType.h"


PriceType::PriceType(double net, int vat) :
    net_(net),
    vat_(vat),
    gross_(0.00)
{
    calculate();
}

PriceType::PriceType() :
    net_(0.00),
    vat_(23),
    gross_(0.00)
{

}

double PriceType::getNet() const
{
    return net_;
}

void PriceType::setNet(double newNet)
{
    net_ = newNet;
}

double PriceType::getGross() const
{
    return gross_;
}

void PriceType::setGross(double newGorss)
{
    gross_ = newGorss;
}

int PriceType::getVat() const
{
    return vat_;
}

void PriceType::setVat(int newVat)
{
    vat_ = newVat;
}

void PriceType::changeNet(double net)
{
    net_ = net;
    calculate();
}

void PriceType::changeGross(double gross)
{
    gross_= gross;
    calculate();
}

void PriceType::chbageVat(int vat)
{
    vat_ = vat;
    calculate();
}

void PriceType::calculate()
{
    gross_ = net_ + (net_ * (vat_/100.00));
}
