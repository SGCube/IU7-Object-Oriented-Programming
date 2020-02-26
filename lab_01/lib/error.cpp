#ifndef ERROR_CPP
#define ERROR_CPP

#include "error.h"

const char* getErrorMsg(const ErrorType error)
{
    switch (error)
    {
        case OK:
            return "OK";
        case ERROR_FILE_OPEN:
            return "Error: File open";
        case ERROR_FILE_READ:
            return "Error: file read";
        case ERROR_FILE_WRITE:
            return "Error: file write";
        case ERROR_FILE_NAME:
            return "Error: filename is empty";
        case ERROR_ALLOCATION:
            return "Error: bad memory allocation";
        case ERROR_FREE:
            return "Error: bad memory free";
        case ERROR_MODEL_INIT:
            return "Error: model is not inizialised";
        case ERROR_EDGES_EXIST:
            return "Error: edge array is not inizialised";
        case ERROR_VERTICES_EXIST:
            return "Error: vertex array is not inizialised";
        case ERROR_ACTION:
            return "Error: type of action not defined";
        case ERROR_AXIS:
            return "Error: type of axis not defined";
        default:
            return "Error: not defined";
    }
}

#endif // ERROR_CPP

