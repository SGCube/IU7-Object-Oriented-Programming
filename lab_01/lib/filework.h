#ifndef FILEWORK_H
#define FILEWORK_H

#include "error.h"

#include <fstream>

struct FileWorkType
{
    FILE* f;
};

bool checkFileIsEmpty(FILE* f);

ErrorType checkFileNameIsEmpty(const char* fileName);

ErrorType checkFileIsOpened(const FILE* f);

ErrorType checkFileIsCorrect(FILE* f);

ErrorType initializeFileType(FileWorkType& file);

ErrorType openFileForRead(FileWorkType& file, const char* fileName);

ErrorType openFileForWrite(FileWorkType& file, const char* fileName);

ErrorType closeFile(FileWorkType& file);

ErrorType getArraySize(size_t& size, FILE* f);

ErrorType setArraySize(const size_t size, FILE* f);

ErrorType getVertexData(double& data, FILE *f);

ErrorType setVertexData(const double data, FILE *f);

ErrorType getEdgeData(size_t& data, FILE* f);

ErrorType setEdgeData(const size_t data, FILE* f);

#endif // FILEWORK_H

