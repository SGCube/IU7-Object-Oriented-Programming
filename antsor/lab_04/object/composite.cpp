#include "composite.h"

void CompositeObject::addModel(std::shared_ptr<Object> object)
{
    objects.push_back(std::static_pointer_cast<Model>(object));
	isModel.push_back(true);
	modelsAmount++;
}

void CompositeObject::removeModel(size_t index)
{
    objects.erase(modelIndex(index));
	modelsAmount--;
}

void CompositeObject::addCamera(std::shared_ptr<Object> object)
{
    objects.push_back(std::static_pointer_cast<Camera>(object));
	isModel.push_back(false);
	camerasAmount++;
}

void CompositeObject::removeCamera(size_t index)
{
	objects.erase(cameraIndex(index));
	camerasAmount--;
}

std::shared_ptr<Object> CompositeObject::getModel(size_t index)
{
	size_t iAll = 0, i = 0;
	
	for (; iAll < objects.size() && i != index + 1; iAll++)
	{
		if (isModel[iAll])
			i++;
	}
	
    if (i != index + 1)
        throw OutOfRangeObjectException(": getModel");
    return objects[iAll];
}

std::shared_ptr<Object> CompositeObject::getCamera(size_t index)
{
	size_t iAll = 0, i = 0;
	
	for (; iAll < objects.size() && i != index + 1; iAll++)
	{
		if (!isModel[iAll])
			i++;
	}
	
    if (i != index + 1)
        throw OutOfRangeObjectException(": getCamera");
    return objects[iAll];
}

ObjIter CompositeObject::objectBegin()
{
    return objects.begin();
}

ObjIter CompositeObject::objectEnd()
{
    return objects.end();
}

ObjIter CompositeObject::modelIndex(size_t index)
{
	size_t iAll = 0, i = 0;
	
	for (; iAll < objects.size() && i != index + 1; iAll++)
	{
		if (isModel[iAll])
			i++;
	}
	
    if (i != index + 1)
        throw OutOfRangeObjectException(": modelIndex");
    return objects.begin() + iAll;
}

ObjIter CompositeObject::cameraIndex(size_t index)
{
	size_t iAll = 0, i = 0;
	
	for (; iAll < objects.size() && i != index + 1; iAll++)
	{
		if (!isModel[iAll])
			i++;
	}
	
    if (i != index + 1)
        throw OutOfRangeObjectException(": cameraIndex");
    return objects.begin() + iAll;
}

