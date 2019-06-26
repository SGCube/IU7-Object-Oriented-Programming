#ifndef SCENE_CPP
#define SCENE_CPP

#include "scene.h"

void Scene::addModel(const std::shared_ptr<Object>& object)
{
    this->composite.addModel(object);
}

void Scene::removeModel(const size_t index)
{
    this->composite.removeModel(index);
}

void Scene::addCamera(const std::shared_ptr<Object>& object)
{
    this->composite.addCamera(object);
}

void Scene::removeCamera(size_t index)
{
    this->composite.removeCamera(index);
}

std::shared_ptr<Object> Scene::getModel(size_t index)
{
    return this->composite.getModel(index);
}

std::shared_ptr<Object> Scene::getCamera(size_t index)
{
    return this->composite.getCamera(index);
}

ObjIter Scene::objectBegin()
{
    return this->composite.objectBegin();
}

ObjIter Scene::objectEnd()
{
    return this->composite.objectEnd();
}

ObjIter Scene::modelIndex(size_t index)
{
    return this->composite.modelIndex(index);
}

ObjIter Scene::cameraIndex(size_t index)
{
    return this->composite.cameraIndex(index);
}

#endif // SCENE_CPP

