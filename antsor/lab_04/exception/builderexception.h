#ifndef BUILDEREXCEPTION_H
#define BUILDEREXCEPTION_H

#include "exceptionbase.h"

class NoObjectToBuildException : public ExceptionBase
{
private:
    static constexpr const char* ErrorMsg = "Error existence building object";
public:
    explicit NoObjectToBuildException() : ExceptionBase(ErrorMsg) {}
    explicit NoObjectToBuildException(const std::string& message) : \
        ExceptionBase(ErrorMsg + message) {}
};

#endif // BUILDEREXCEPTION_H
