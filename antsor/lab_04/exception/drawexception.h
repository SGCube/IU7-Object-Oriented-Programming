#ifndef DRAWEREXCEPTION_H
#define DRAWEREXCEPTION_H

#include "exceptionbase.h"

class NoObjectToDrawException : public ExceptionBase
{
private:
    static constexpr const char* ErrorMsg = "Error existence drawing object";
public:
    explicit NoObjectToDrawException() : ExceptionBase(ErrorMsg) {}
    explicit NoObjectToDrawException(const std::string& message) :
        ExceptionBase(ErrorMsg + message) {}
};

class NoVerticesToDrawException : public ExceptionBase
{
private:
    static constexpr const char* ErrorMsg = "Error existence drawing nodes";
public:
    explicit NoVerticesToDrawException() : ExceptionBase(ErrorMsg) {}
    explicit NoVerticesToDrawException(const std::string& message) :
        ExceptionBase(ErrorMsg + message) {}
};

class NoEdgesToDrawException : public ExceptionBase
{
private:
    static constexpr const char* ErrorMsg = "Error existence drawing edges";
public:
    explicit NoEdgesToDrawException() : ExceptionBase(ErrorMsg) {}
    explicit NoEdgesToDrawException(const std::string& message) :
        ExceptionBase(ErrorMsg + message) {}
};

#endif // DRAWEREXCEPTION_H
