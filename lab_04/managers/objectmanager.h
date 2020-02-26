
#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include "object/object.h"
#include "workers/transformator.h"
#include "exception/transformerexception.h"

class ModelManager
{
public:
    ModelManager() = default;
    ~ModelManager() = default;

    void transform(BaseTransformator& tr, const ObjIter& b, const ObjIter& e)
    {
        for (ObjIter iter = b; iter != e; iter++)
        {
            if (!(*iter))
                throw NoObjectToTransformException();
			tr.transform((*iter));
        }
    }
};

class CameraManager
{
public:
    CameraManager() = default;
    ~CameraManager() = default;

    void transform(BaseTransformator& tr, const ObjIter& b, const ObjIter& e)
    {
        for (ObjIter iter = b; iter != e; iter++)
        {
            if (!(*iter))
                throw NoObjectToTransformException();
			tr.transform((*iter));
        }
    }
};

#endif // MODELMANAGER_H
