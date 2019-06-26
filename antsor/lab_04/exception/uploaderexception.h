#ifndef UPLOADEREXCEPTION_H
#define UPLOADEREXCEPTION_H

#include "exceptionbase.h"

class OpenFileException : public ExceptionBase
{
private:
    static constexpr const char* ErrorMsg = "Error opening file";
public:
    explicit OpenFileException() : ExceptionBase(ErrorMsg) {}
    explicit OpenFileException(const std::string& message) :
        ExceptionBase(ErrorMsg + message) {}
};

class CloseFileException : public ExceptionBase
{
private:
    static constexpr const char* ErrorMsg = "Error closing file";
public:
    explicit CloseFileException() : ExceptionBase(ErrorMsg) {}
    explicit CloseFileException(const std::string& message) :
        ExceptionBase(ErrorMsg + message) {}
};

class ReadFileException : public ExceptionBase
{
private:
    static constexpr const char* ErrorMsg = "Error reading file";
public:
    explicit ReadFileException() : ExceptionBase(ErrorMsg) {}
    explicit ReadFileException(const std::string& message) :
        ExceptionBase(ErrorMsg + message) {}
};

#endif // UPLOADEREXCEPTION_H

