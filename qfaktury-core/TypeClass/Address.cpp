#include "Address.h"

const Street& Address::getStreet() const
{
    return street_;
}

const HouseNumber &Address::getHouseNumber() const
{
    return houseNumber_;
}

const FlatNumber &Address::getFlatNumber() const
{
    return flatNumber_;
}

const City &Address::getCity() const
{
    return city_;
}

const Municipality &Address::getMunicipality() const
{
    return municipality_;
}

const PostCode &Address::getPostCode() const
{
    return postCode_;
}

const Country &Address::getCountry() const
{
    return country_;
}

const County &Address::getCounty() const
{
    return county_;
}

const Province &Address::getProvice() const
{
    return provice_;
}

Address::Address(const Street &street, const HouseNumber &houseNumber, const FlatNumber &flatNumber, const City &city, const Municipality &municipality, const PostCode &postCode, const Country &country, const County &county, const Province &provice) : street_(street),
    houseNumber_(houseNumber),
    flatNumber_(flatNumber),
    city_(city),
    municipality_(municipality),
    postCode_(postCode),
    country_(country),
    county_(county),
    provice_(provice)
{}
