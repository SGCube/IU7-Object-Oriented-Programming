#ifndef FILEWORK_CPP
#define FILEWORK_CPP

#include "filework.h"

bool checkFileIsEmpty(FILE* f)
{
    const long place = ftell(f);
    fseek(f, 0, SEEK_END);

    if (place == ftell(f))
        return true;

    fseek(f, place, SEEK_SET);
    return false;
}

bool checkFileNameIsEmpty(const char* fileName)
{
    return fileName[0] == '\0';
}

ErrorType checkFileIsOpened(const FILE* f)
{
    return f ? OK : ERROR_FILE_OPEN;
}

ErrorType checkFileIsCorrect(FILE* f)
{
	ErrorType error = checkFileOpened(f);
    if (error != OK)
        return error;
    return checkFileIsEmpty(f) ? ERROR_FILE_READ : OK;
}

ErrorType initializeFileType(FileWorkType& file)
{
    file.f = nullptr;
    return OK;
}

ErrorType openFileForRead(FileWorkType& file, const char* fileName)
{
    file.f = fopen(fileName, "r");
    return checkFileIsOpened(file.f);
}

ErrorType openFileForWrite(FileWorkType& file, const char* fileName)
{
    file.f = fopen(fileName, "w");
    return checkFileIsOpened(file.f);
}

ErrorType getArraySize(unsigned int& size, FILE* f)
{
    return fscanf(f, "%u", &size) == 1 ? OK : ERROR_FILE_READ;
}

ErrorType setArraySize(const unsigned int size, FILE* f)
{
    return fprintf(f, "%u\n\n", size) < 1 ? ERROR_FILE_WRITE : OK;
}

ErrorType getVertexData(double& data, FILE *f)
{
    float tmp;
    if (fscanf(f, "%f", &tmp) != READ_OK)
        return ERROR_FILE_READ;
    data = tmp;
    return OK;
}

ErrorType setVertexData(FILE *f, const double data)
{
    return fprintf(f, "%f ", data) < 1 ? ERROR_FILE_WRITE : OK;
}

ErrorType getEdgeData(unsigned int& data, FILE* f)
{
    return fscanf(f, "%u", &data) == 1 ? OK : ERROR_FILE_READ;
}

ErrorType setEdgeData(const unsigned int data, FILE* f)
{
    return fprintf(f, "%u ", data) < 1 ? ERROR_FILE_WRITE : OK;
}

#endif // FILEWORK_CPP

