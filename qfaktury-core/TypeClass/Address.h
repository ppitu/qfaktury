#ifndef ADDRESS_H
#define ADDRESS_H

#include "Street.h"
#include "HouseNumber.h"
#include "FlatNumber.h"
#include "City.h"
#include "PostCode.h"
#include "Municipality.h"
#include "Country.h"
#include "County.h"
#include "Province.h"

class Address
{
public:
    Address(const Street &street, const HouseNumber &houseNumber, const FlatNumber &flatNumber,
            const City &city, const Municipality &municipality, const PostCode &postCode,
            const Country &country, const County &county, const Province &provice);

    const Street& getStreet() const;
    const HouseNumber &getHouseNumber() const;
    const FlatNumber &getFlatNumber() const;
    const City &getCity() const;
    const Municipality &getMunicipality() const;
    const PostCode &getPostCode() const;
    const Country &getCountry() const;
    const County &getCounty() const;
    const Province &getProvice() const;

private:
    Street street_;
    HouseNumber houseNumber_;
    FlatNumber flatNumber_;
    City city_;
    Municipality municipality_;
    PostCode postCode_;
    Country country_;
    County county_;
    Province provice_;
};

#endif // ADDRESS_H
