#ifndef CONTRACTOR_H
#define CONTRACTOR_H

#include <QString>
#include <optional>

#include "TypeClass/Email.h"
#include "TypeClass/NIP.h"
#include "TypeClass/Phone.h"
#include "TypeClass/PostCode.h"

class Contractor
{
public:
    Contractor();
    Contractor(const QString &name, const QString &city, const PostCode &postCode, const QString &address, const NIP &nip, std::optional<QString> bankAccount, std::optional<Phone> phone, std::optional<Email> email, std::optional<QString> www);

    const QString &name() const;
    void setName(const QString &newName);
    const QString &city() const;
    void setCity(const QString &newCity);
    const PostCode &postCode() const;
    void setPostCode(const PostCode &newPostCode);
    const QString &address() const;
    void setAddress(const QString &newAddress);
    const NIP &nip() const;
    void setNip(const NIP &newNip);
    std::optional<QString> bankAccount() const;
    void setBankAccount(std::optional<QString> newBankAccount);
    std::optional<Phone> phone() const;
    void setPhone(std::optional<Phone> newPhone);
    std::optional<Email> email() const;
    void setEmail(std::optional<Email> newEmail);
    std::optional<QString> www() const;
    void setWww(std::optional<QString> newWww);

private:
    QString name_;
    QString city_;
    PostCode postCode_;
    QString address_;
    NIP nip_;
    std::optional<QString> bankAccount_;
    std::optional<Phone> phone_;
    std::optional<Email> email_;
    std::optional<QString> www_;

};

#endif // CONTRACTOR_H
