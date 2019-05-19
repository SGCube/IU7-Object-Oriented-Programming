#ifndef DISPLAY_ERROR_H
#define DISPLAY_ERROR_H

#include "../library/errors.h"

#include <QMessageBox>

void display_error(QString m);

void display_error(error_type e);

#endif // DISPLAY_ERROR_H

