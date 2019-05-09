#ifndef ERROR_H
#define ERROR_H

// types of library errors
enum ErrorType
{
    OK = 0,
    ERROR_FILE_OPEN,
	ERROR_FILE_READ,
	ERROR_FILE_WRITE,
	ERROR_FILE_NAME,
	ERROR_ALLOCATION,
	ERROR_FREE,
	ERROR_MODEL_INIT,
	ERROR_EDGES_EXIST,
	ERROR_VERTICES_EXIST,
	ERROR_ACTION,
	ERROR_FIELD
};

// get message of error
const char* getErrorMsg(const errorType error);

#endif // ERROR_H

