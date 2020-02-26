#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include <exception>
#include <string>

class ExceptionBase : public std::exception
{
public:
    ExceptionBase();
    explicit ExceptionBase(const char* message) : message(message) {}
    explicit ExceptionBase(const std::string& message) : message(message) {}

    virtual const char* what() const noexcept override
    {
        return message.c_str();
    }

protected:
    std::string message;
};

#endif // BASEEXCEPTION_H
