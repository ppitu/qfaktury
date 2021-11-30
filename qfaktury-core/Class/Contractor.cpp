#include "Contractor.h"

const QString &Contractor::name() const
{
    return name_;
}

void Contractor::setName(const QString &newName)
{
    name_ = newName;
}

const QString &Contractor::city() const
{
    return city_;
}

void Contractor::setCity(const QString &newCity)
{
    city_ = newCity;
}

const PostCode &Contractor::postCode() const
{
    return postCode_;
}

void Contractor::setPostCode(const PostCode &newPostCode)
{
    postCode_ = newPostCode;
}

const QString &Contractor::address() const
{
    return address_;
}

void Contractor::setAddress(const QString &newAddress)
{
    address_ = newAddress;
}

const NIP &Contractor::nip() const
{
    return nip_;
}

void Contractor::setNip(const NIP &newNip)
{
    nip_ = newNip;
}

std::optional<QString> Contractor::bankAccount() const
{
    return bankAccount_;
}

void Contractor::setBankAccount(std::optional<QString> newBankAccount)
{
    bankAccount_ = newBankAccount;
}

std::optional<Phone> Contractor::phone() const
{
    return phone_;
}

void Contractor::setPhone(std::optional<Phone> newPhone)
{
    phone_ = newPhone;
}

std::optional<Email> Contractor::email() const
{
    return email_;
}

void Contractor::setEmail(std::optional<Email> newEmail)
{
    email_ = newEmail;
}

std::optional<QString> Contractor::www() const
{
    return www_;
}

void Contractor::setWww(std::optional<QString> newWww)
{
    www_ = newWww;
}

Contractor::Contractor(const QString &name, const QString &city, const PostCode &postCode, const QString &address, const NIP &nip, std::optional<QString> bankAccount, std::optional<Phone> phone, std::optional<Email> email, std::optional<QString> www) : name_(name),
    city_(city),
    postCode_(postCode),
    address_(address),
    nip_(nip),
    bankAccount_(std::move(bankAccount)),
    phone_(std::move(phone)),
    email_(std::move(email)),
    www_(std::move(www))
{}

Contractor::Contractor() :
    name_(""),
    address_(""),
    city_("")
{

}
