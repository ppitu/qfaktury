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

double Price::getGross() const
{
    return gross_;
}

int Price::getVat() const
{
    return vat_;
}

void Price::calculate()
{
    gross_ = net_ + (net_ * (vat_/100.00));
}
