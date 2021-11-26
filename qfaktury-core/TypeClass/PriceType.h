#ifndef PRICE_H
#define PRICE_H

// TODO
// Dodac obsluge dwoch liczba po przecinku, na razie moze ich byc wiecej

class PriceType
{
public:
    PriceType(double net, int vat);
    PriceType();

    double getNet() const;
    void setNet(const double newNet);
    double getGross() const;
    void setGross(const double newGorss);
    int getVat() const;
    void setVat(const int newVat);
    void changeNet(double net);
    void changeGross(double gross);
    void chbageVat(int vat);

private:
    double net_;
    double gross_;
    int vat_;

    void calculate();
};

#endif // PRICE_H
