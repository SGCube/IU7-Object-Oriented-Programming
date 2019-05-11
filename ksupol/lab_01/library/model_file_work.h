#ifndef MODELFILEWORK_H
#define MODELFILEWORK_H

#include "errors.h"
#include "model.h"

#include <fstream>

error_type modelLoad(modelType& model, fileWorkType file);

error_type modelSave(modelType model, fileWorkType file);

#endif // MODELFILEWORK_H

