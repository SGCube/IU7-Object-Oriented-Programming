#ifndef SCENE_H
#define SCENE_H

#include "object/composite.h"

#include <iostream>
#include <memory>
#include <vector>

class Scene
{
public:
    Scene() = default;
    ~Scene() = default;

    void addModel(const std::shared_ptr<Object>& model);
    void removeModel(size_t index);

    void addCamera(const std::shared_ptr<Object>& camera);
    void removeCamera(size_t index);

    std::shared_ptr<Object> getModel(size_t index);
    std::shared_ptr<Object> getCamera(size_t index);

    ObjIter objectBegin();
    ObjIter objectEnd();
	
    ObjIter modelIndex(size_t index);
    ObjIter cameraIndex(size_t index);
	
private:
	CompositeObject composite;
};

#endif // SCENE_H

