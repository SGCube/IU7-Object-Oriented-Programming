#ifndef OBJECTEXCEPTION_H
#define OBJECTEXCEPTION_H

#include "exceptionbase.h"

class OutOfRangeObjectException : public ExceptionBase
{
private:
    static constexpr const char* ErrorMsg = "Error: out of range of objects";

public:
    explicit OutOfRangeObjectException() : ExceptionBase(ErrorMsg) {}
    explicit OutOfRangeObjectException(const std::string& message) :
        ExceptionBase(ErrorMsg + message) {}
};

#endif // OBJECTEXCEPTION_H

