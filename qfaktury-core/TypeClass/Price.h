#ifndef PRICE_H
#define PRICE_H

// TODO
// Dodac obsluge dwoch liczba po przecinku, na razie moze ich byc wiecej

class Price
{
public:
    Price(double net, int vat);
    Price();

    double getNet() const;
    double getGross() const;
    int getVat() const;

private:
    double net_;
    double gross_;
    int vat_;

    void calculate();
};

#endif // PRICE_H
