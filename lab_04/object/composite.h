#ifndef COMPOSITEOBJECT_H
#define COMPOSITEOBJECT_H

#include "model.h"
#include "camera.h"
#include "object.h"
#include "exception/objectexception.h"

#include <vector>

class CompositeObject : public Object
{
public:
    CompositeObject() = default;
    ~CompositeObject() = default;

    void addModel(std::shared_ptr<Object> object);
    void removeModel(size_t index);

    void addCamera(std::shared_ptr<Object> object);
    void removeCamera(size_t index);

    std::shared_ptr<Object> getModel(size_t index);
    std::shared_ptr<Object> getCamera(size_t index);

    ObjIter objectBegin();
    ObjIter objectEnd();
	
    ObjIter modelIndex(size_t index);
    ObjIter cameraIndex(size_t index);

private:
    std::vector<std::shared_ptr<Object>> objects;
	std::vector<bool> isModel;
	size_t modelsAmount;
	size_t camerasAmount;
};

#endif // COMPOSITEOBJECT_H
