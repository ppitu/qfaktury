#include "Price.h"


Price::Price(double net, double vat) :
    mNet(net),
    mVat(vat)
{
    mGross = mNet + (mNet * mVat);
}

double Price::getNet() const
{
    return mNet;
}

void Price::setNet(double newNet)
{
    mNet = newNet;
}

double Price::getGorss() const
{
    return mGross;
}

void Price::setGorss(double newGorss)
{
    mGross = newGorss;
}

double Price::getVat() const
{
    return mVat;
}

void Price::setVat(double newVat)
{
    mVat = newVat;
}
