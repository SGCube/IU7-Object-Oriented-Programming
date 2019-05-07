#ifndef ERRORS_CPP
#define ERRORS_CPP

#include "errors.h"

const char *get_message(error_type error)
{
    if (error == OK)
        return "OK";
    else if (error == ErrorFileOpen)
        return "Файл не открыт!";
    else if (error == ErrorFileRead)
        return "Файл не прочтен!";
    else if (error == ErrorFileSave)
        return "Файл не сохранен!";
    else if (error == ErrorFileName)
        return "Пустое имя файла!";
    else if (error == ErrorAllocation)
        return "Ошибка в выделении памяти!";
    else if (error == ErrorFree)
        return "Неполное освобождение памяти!";
    else if (error == ErrorModelInit)
        return "Неинициализированная модель!";
    else if (error == ErrorEdgesExist)
        return "Неинициализированная вершина!";
    else if (error == ErrorNodesExist)
        return "Неинициализированная точка пересечения!";
    else if (error == ErrorAction)
        return "Неинициализированное действие!";
    else if (error == ErrorField)
        return "Неинициализированное поле ввода!";
    else
        return "Неинициализированная ошибка!";
}

#endif // ERRORS_CPP

