#include "composite.h"

void CompositeObject::addModel(std::shared_ptr<Object> object)
{
    models.push_back(std::static_pointer_cast<Model>(object));
}

void CompositeObject::removeModel(const size_t index)
{
    if (index > models.size())
    {
        throw OutOfRangeObjectException(": removeModel");
    }
    else
    {
        models.erase(models.begin() + index);
    }
}

void CompositeObject::addCamera(std::shared_ptr<Object> object)
{
    cameras.push_back(std::static_pointer_cast<Camera>(object));
}

void CompositeObject::removeCamera(const size_t index)
{
    if (index > cameras.size())
    {
        throw OutOfRangeObjectException(": removeCamera");
    }
    else
    {
        cameras.erase(cameras.begin() + index);
    }
}

std::shared_ptr<Object> CompositeObject::getModel(const size_t index)
{
    if (index > models.size())
        throw OutOfRangeObjectException(": getModel");
    else
        return models[index];
}

std::shared_ptr<Object> CompositeObject::getCamera(const size_t index)
{
    if (index > cameras.size())
        throw OutOfRangeObjectException(": getCamera");
    else
        return cameras[index];
}

ObjIter CompositeObject::modelBegin()
{
    return models.begin();
}

ObjIter CompositeObject::modelEnd()
{
    return models.end();
}

ObjIter CompositeObject::cameraBegin()
{
    return cameras.begin();
}

ObjIter CompositeObject::cameraEnd()
{
    return cameras.end();
}

ObjIter CompositeObject::modelIndex(const size_t index)
{
    if (index > models.size())
        throw OutOfRangeObjectException(": modelIndex");
    else
        return models.begin() + index;
}

ObjIter CompositeObject::cameraIndex(const size_t index)
{
    if (index > cameras.size())
        throw OutOfRangeObjectException(": cameraIndex");
    else
        return cameras.begin() + index;
}

