#ifndef ERROR_HPP
#define ERROR_HPP

#include <exception>
#include <string>

using std::exception;
using std::string;

class Error : public exception
{
public:
    Error();
    explicit Error(const char* msg) : message(msg) {}
    explicit Error(const string& msg) : message(msg) {}

    virtual const char* what() const noexcept override
    {
        return message.c_str();
    }

protected:
    string message;
};

class ErrorMemory : public Error
{
public:
    explicit ErrorMemory() : Error(messageError) {}
    explicit ErrorMemory(const string& msg) : Error(messageError + msg) {}

private:
    static constexpr const char* messageError = "Memory allocation error!";
    static constexpr const char* messageErrorExt = "Memory allocation error: ";
};

class ErrorEmpty : public Error
{
public:
    explicit ErrorEmpty() : Error(messageError) {}
    explicit ErrorEmpty(const string& msg) : Error(messageError + msg) {}

private:
    static constexpr const char* messageError = "List is empty!";
    static constexpr const char* messageErrorExt = "List is empty: ";
};

class ErrorListRange : public Error
{
public:
    explicit ErrorListRange() : Error(messageError) {}
    explicit ErrorListRange(const string& msg) : Error(messageError + msg) {}

private:
    static constexpr const char* messageError = "Index out of range!";
    static constexpr const char* messageErrorExt = "Index out of range: ";
};

#endif //ERROR_HPP
