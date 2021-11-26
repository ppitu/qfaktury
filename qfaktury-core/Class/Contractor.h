#ifndef CONTRACTOR_H
#define CONTRACTOR_H

#include <QString>
#include <optional>

#include "TypeClass/EmailType.h"
#include "TypeClass/NIPType.h"
#include "TypeClass/PhoneType.h"
#include "TypeClass/PostCodeType.h"

class Contractor
{
public:
    Contractor();
    Contractor(const QString &name, const QString &city, const PostCodeType &postCode, const QString &address, const NIPType &nip, std::optional<QString> bankAccount, std::optional<PhoneType> phone, std::optional<EmailType> email, std::optional<QString> www);

    const QString &name() const;
    void setName(const QString &newName);
    const QString &city() const;
    void setCity(const QString &newCity);
    const PostCodeType &postCode() const;
    void setPostCode(const PostCodeType &newPostCode);
    const QString &address() const;
    void setAddress(const QString &newAddress);
    const NIPType &nip() const;
    void setNip(const NIPType &newNip);
    std::optional<QString> bankAccount() const;
    void setBankAccount(std::optional<QString> newBankAccount);
    std::optional<PhoneType> phone() const;
    void setPhone(std::optional<PhoneType> newPhone);
    std::optional<EmailType> email() const;
    void setEmail(std::optional<EmailType> newEmail);
    std::optional<QString> www() const;
    void setWww(std::optional<QString> newWww);

private:
    QString name_;
    QString city_;
    PostCodeType postCode_;
    QString address_;
    NIPType nip_;
    std::optional<QString> bankAccount_;
    std::optional<PhoneType> phone_;
    std::optional<EmailType> email_;
    std::optional<QString> www_;

};

#endif // CONTRACTOR_H
