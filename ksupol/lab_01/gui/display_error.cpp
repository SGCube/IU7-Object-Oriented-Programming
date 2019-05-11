#ifndef DISPLAY_ERROR_CPP
#define DISPLAY_ERROR_CPP

#include "display_error.h"

void display_error(QString m)
{
    QMessageBox::critical(NULL, "Ошибка!", m);
}

void display_error(error_type e)
{
    display_error(QString(get_message(e)));
}

#endif // DISPLAY_ERROR_CPP

