#ifndef ADDRESS_H
#define ADDRESS_H

#include <optional>

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
    Address(const Street &street, const HouseNumber &houseNumber, const std::optional<FlatNumber> flatNumber,
            const City &city, const Municipality &municipality, const PostCode &postCode,
            const std::optional<Country> country, const std::optional<County> county, const std::optional<Province> provice);

    const Street& getStreet() const;
    const HouseNumber &getHouseNumber() const;
    const std::optional<FlatNumber> getFlatNumber() const;
    const City &getCity() const;
    const Municipality &getMunicipality() const;
    const PostCode &getPostCode() const;
    const std::optional<Country> getCountry() const;
    const std::optional<County> getCounty() const;
    const std::optional<Province> getProvice() const;

private:
    Street street_;
    HouseNumber houseNumber_;
    std::optional<FlatNumber> flatNumber_;
    City city_;
    Municipality municipality_;
    PostCode postCode_;
    std::optional<Country> country_;
    std::optional<County> county_;
    std::optional<Province> provice_;
};

#endif // ADDRESS_H
