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
    void removeModel(const size_t index);

    void addCamera(std::shared_ptr<Object> object);
    void removeCamera(const size_t index);

    std::shared_ptr<Object> getModel(const size_t index);
    std::shared_ptr<Object> getCamera(const size_t index);

    ObjIter modelBegin();
    ObjIter modelEnd();
	
	ObjIter cameraBegin();
    ObjIter cameraEnd();
	
    ObjIter modelIndex(const size_t index);
    ObjIter cameraIndex(const size_t index);

private:
    std::vector<std::shared_ptr<Object>> models;
	std::vector<std::shared_ptr<Object>> cameras;
};

#endif // COMPOSITEOBJECT_H
