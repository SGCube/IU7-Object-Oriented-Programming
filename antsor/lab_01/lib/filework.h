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

ErrorType getArraySize(unsigned int& size, FILE* f);

ErrorType setArraySize(const unsigned int size, FILE* f);

ErrorType getVertexData(double& data, FILE *f);

ErrorType setVertexData(FILE *f, const double data);

ErrorType getEdgeData(unsigned int& data, FILE* f);

ErrorType setEdgeData(const unsigned int data, FILE* f);

#endif // FILEWORK_H

