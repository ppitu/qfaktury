#ifndef PRICE_H
#define PRICE_H


class Price
{
public:
    Price(double net, double vat);

    double getNet() const;
    void setNet(double newNet);
    double getGorss() const;
    void setGorss(double newGorss);
    double getVat() const;
    void setVat(double newVat);

private:
    double mNet;
    double mGross;
    double mVat;
};

#endif // PRICE_H
