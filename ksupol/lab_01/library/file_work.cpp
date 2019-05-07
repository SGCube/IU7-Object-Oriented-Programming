#ifndef FILEWORK_CPP
#define FILEWORK_CPP

#include "file_work.h"

bool isEmptyFile(FILE* f)
{
    const long place = ftell(f);
    fseek(f, 0, SEEK_END);

    if (place == ftell(f))
        return true;

    fseek(f, place, SEEK_SET);

    return false;
}

bool isOpenFile(const FILE* f)
{
    return f ? true : false;
}

error_type checkFileForOpen(const FILE* f)
{
    return isOpenFile(f) ? OK : ErrorFileOpen;
}

error_type isFileNameEmpty(const char* fileName)
{
    return fileName[0] == '\0' ? ErrorFileName : OK;
}

fileWorkType fileTypeInit()
{
    fileWorkType file;
    file.f = NULL;
    return file;
}

error_type openFileForRead(fileWorkType& file, const char* fileName)
{
    file.f = fopen(fileName, "r");
    return isOpenFile(file.f) ? OK : ErrorFileOpen;
}

error_type openFileForWrite(fileWorkType& file, const char* fileName)
{
    file.f = fopen(fileName, "w");
    return isOpenFile(file.f) ? OK : ErrorFileOpen;
}

error_type isCorrectFile(FILE* f)
{
    if (!isOpenFile(f))
        return ErrorFileOpen;
    if (isEmptyFile(f))
        return ErrorFileRead;
    return OK;
}

error_type getSize(unsigned int& size, FILE* f)
{
    if (fscanf(f, "%u", &size) == READ_OK)
        return OK;
    return ErrorFileRead;
}

error_type setSize(FILE* f, const unsigned int size)
{
    if (fprintf(f, "%u\n\n", size) < WRITE_OK)
        return ErrorFileSave;
    return OK;
}

error_type getEdgeData(unsigned int& data, FILE* f)
{
    if (fscanf(f, "%u", &data) == READ_OK)
        return OK;
    return ErrorFileRead;
}

error_type setEdgeData(FILE* f, const unsigned int data)
{
    if (fprintf(f, "%u ", data) < WRITE_OK)
        return ErrorFileSave;
    return OK;
}

error_type getNodeData(double& data, FILE *f)
{
    float tmp;
    if (fscanf(f, "%f", &tmp) != READ_OK)
        return ErrorFileRead;
    data = tmp;

    return OK;
}

error_type setNodeData(FILE *f, const double data)
{
    float tmp = data;
    return fprintf(f, "%f ", tmp) < WRITE_OK ? ErrorFileSave : OK;
}

#endif // FILEWORK_CPP

