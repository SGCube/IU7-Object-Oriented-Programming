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

ErrorType checkFileNameIsEmpty(const char* fileName)
{
    return (fileName[0] == '\0') ? ERROR_FILE_NAME : OK;
}

ErrorType checkFileIsOpened(const FILE* f)
{
    return f ? OK : ERROR_FILE_OPEN;
}

ErrorType checkFileIsCorrect(FILE* f)
{
	ErrorType error = checkFileIsOpened(f);
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

ErrorType getArraySize(size_t& size, FILE* f)
{
    return fscanf(f, "%llu", &size) == 1 ? OK : ERROR_FILE_READ;
}

ErrorType setArraySize(const size_t size, FILE* f)
{
    return fprintf(f, "%llu\n\n", size) < 1 ? ERROR_FILE_WRITE : OK;
}

ErrorType getVertexData(double& data, FILE *f)
{
    float tmp;
    if (fscanf(f, "%f", &tmp) != 1)
        return ERROR_FILE_READ;
    data = tmp;
    return OK;
}

ErrorType setVertexData(const double data, FILE *f)
{
    return fprintf(f, "%f ", data) < 1 ? ERROR_FILE_WRITE : OK;
}

ErrorType getEdgeData(size_t& data, FILE* f)
{
    return fscanf(f, "%llu", &data) == 1 ? OK : ERROR_FILE_READ;
}

ErrorType setEdgeData(const size_t data, FILE* f)
{
    return fprintf(f, "%llu ", data) < 1 ? ERROR_FILE_WRITE : OK;
}

#endif // FILEWORK_CPP

