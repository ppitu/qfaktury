#ifndef EMAILEXCEPTION_H
#define EMAILEXCEPTION_H


class EmailException
{
public:
    EmailException();

    const char* what() const throw();
};

#endif // EMAILEXCEPTION_H
