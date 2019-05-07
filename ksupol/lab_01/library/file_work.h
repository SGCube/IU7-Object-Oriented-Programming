#ifndef FILE_WORK_H
#define FILE_WORK_H

#include "errors.h"

#include <fstream>

#define READ_OK 1
#define WRITE_OK 1

struct fileWorkType
{
    FILE* f;
};

// проверить файл на пустоту
bool isEmptyFile(FILE* f);

// проверить файл на открытие
bool isOpenFile(const FILE* f);

// проверить файл на открытие
error_type checkFileForOpen(const FILE* f);

// проверка на пустое имя файла
error_type isFileNameEmpty(const char* fileName);

// инициализация переменной для файла
fileWorkType fileTypeInit();

// открытие файла для чтения
error_type openFileForRead(fileWorkType &file, const char* fileName);

// открытие файла для записи
error_type openFileForWrite(fileWorkType &file, const char* fileName);

// проверка на корректность файла
error_type isCorrectFile(FILE* f);

// получение кол-ва вершин и точек пересечений из файла
error_type getSize(unsigned int& size, FILE* f);

// установка кол-ва вершин и точек пересечений в файл
error_type setSize(FILE* f, const unsigned int size);

// получение вершин из файла
error_type getEdgeData(unsigned int& data, FILE* f);

// установка вершин в файл
error_type setEdgeData(FILE* f, const unsigned int data);

// получение точек пересечения из файла
error_type getNodeData(double &data, FILE *f);

// установка точек пересечения в файл
error_type setNodeData(FILE *f, const double data);

#endif // FILE_WORK_H

