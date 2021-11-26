#ifndef EMAIL_H
#define EMAIL_H

#include <QString>

class EmailType
{
public:
    EmailType() = delete;
    EmailType(const QString &email);

    const QString& getEmail() const;

private:
    QString email_;

    void validate();
};

#endif // EMAIL_H
