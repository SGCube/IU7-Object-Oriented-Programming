#ifndef TRANSFORMEXCEPTION_H
#define TRANSFORMEXCEPTION_H

#include "exceptionbase.h"

class NoObjectToTransformException : public ExceptionBase
{
private:
    static constexpr const char* ErrorMsg = "Error existence transforming object";
public:
    explicit NoObjectToTransformException() : ExceptionBase(ErrorMsg) {}
    explicit NoObjectToTransformException(const std::string& message) :
        ExceptionBase(ErrorMsg + message) {}
};

class NoVerticesToTransformException : public ExceptionBase
{
private:
    static constexpr const char* ErrorMsg = "Error existence transforming vertices";
public:
    explicit NoVerticesToTransformException() : ExceptionBase(ErrorMsg) {}
    explicit NoVerticesToTransformException(const std::string& message) :
        ExceptionBase(ErrorMsg + message) {}
};

#endif // TRANSFORMEXCEPTION_H
