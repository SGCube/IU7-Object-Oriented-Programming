#ifndef ERROR_CPP
#define ERROR_CPP

#include "error.h"

const char* getErrorMsg(const errorType error)
{
    switch (error)
    {
        case OK:
            return "OK";
        case ERROR_FILE_OPEN:
            return "Error file: open";
        case ERROR_FILE_READ:
            return "Error file: read";
        case ERROR_FILE_WRITE:
            return "Error file: write";
        case ERROR_FILE_NAME:
            return "Error file: name is empty";
        case ERROR_ALLOCATION:
            return "Error memory: bad allocation";
        case ERROR_FREE:
            return "Error memory: bad free";
        case ERROR_MODEL_INIT:
            return "Error model: not inizialisation";
        case ERROR_EDGES_EXIST:
            return "Error edge array: not inizialisation";
        case ERROR_VERTICES_EXIST:
            return "Error node array: not inizialisation";
        case ERROR_ACTION:
            return "Error type of action: not defined";
        case ERROR_FIELD:
            return "Error type of field: not defined";
        default:
            return "Error type of error: not defined";
    }
}

#endif // ERROR_CPP

