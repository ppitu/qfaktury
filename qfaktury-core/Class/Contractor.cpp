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

const PostCodeType &Contractor::postCode() const
{
    return postCode_;
}

void Contractor::setPostCode(const PostCodeType &newPostCode)
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

const NIPType &Contractor::nip() const
{
    return nip_;
}

void Contractor::setNip(const NIPType &newNip)
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

std::optional<PhoneType> Contractor::phone() const
{
    return phone_;
}

void Contractor::setPhone(std::optional<PhoneType> newPhone)
{
    phone_ = newPhone;
}

std::optional<EmailType> Contractor::email() const
{
    return email_;
}

void Contractor::setEmail(std::optional<EmailType> newEmail)
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

Contractor::Contractor(const QString &name, const QString &city, const PostCodeType &postCode, const QString &address, const NIPType &nip, std::optional<QString> bankAccount, std::optional<PhoneType> phone, std::optional<EmailType> email, std::optional<QString> www) : name_(name),
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
