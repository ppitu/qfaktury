#include "Address.h"

const Street& Address::getStreet() const
{
    return street_;
}

const HouseNumber &Address::getHouseNumber() const
{
    return houseNumber_;
}

const std::optional<FlatNumber> Address::getFlatNumber() const
{
    if(flatNumber_.has_value())
    {
        return flatNumber_;
    }

    return {};
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

const std::optional<Country> Address::getCountry() const
{
    if(country_.has_value())
    {
        return country_;
    }

    return {};
}

const std::optional<County> Address::getCounty() const
{
    if(country_.has_value())
    {
        return county_;
    }

    return {};
}

const std::optional<Province> Address::getProvice() const
{
    if(provice_.has_value())
    {
        return provice_;
    }

    return {};
}

Address::Address(const Street &street, const HouseNumber &houseNumber, const std::optional<FlatNumber> flatNumber,
                 const City &city, const Municipality &municipality, const PostCode &postCode,
                 const std::optional<Country> country, const std::optional<County> county, const std::optional<Province> provice) :
    street_(street),
    houseNumber_(houseNumber),
    flatNumber_(flatNumber),
    city_(city),
    municipality_(municipality),
    postCode_(postCode),
    country_(country),
    county_(county),
    provice_(provice)
{}
