#ifndef FACADE_HPP
#define FACADE_HPP

#include "facade.h"

void Facade::addModel(BaseUploader& upld, BaseBuilder& bld)
{
    this->scene.addModel(uploadManager.uploadModel(upld, bld));
}

void Facade::removeModel(size_t index)
{
    this->scene.removeModel(index);
}

void Facade::addCamera()
{
    Camera* cameraPtr = new Camera();
    std::shared_ptr<Object> camera(cameraPtr);
    this->scene.addCamera(camera);
}

void Facade::removeCamera(size_t index)
{
    this->scene.removeCamera(index);
}

#include <qdebug.h>

void Facade::transformModel(BaseTransformator& tr, int modelIndex)
{
    ObjIter begin = (modelIndex == -1) ? this->scene.modelBegin() :
                                         this->scene.modelIndex(modelIndex);
    ObjIter end = (modelIndex == -1) ? this->scene.modelEnd() :
                                       this->scene.modelIndex(modelIndex + 1);

    this->modelManager.transform(tr, begin, end);
}

void Facade::transformCamera(BaseTransformator &tr, size_t cameraIndex)
{
    ObjIter begin = this->scene.cameraIndex(cameraIndex);
    ObjIter end = this->scene.cameraIndex(cameraIndex + 1);
    this->cameraManager.transform(tr, begin, end);
}

void Facade::draw(BaseDrawer& drw, size_t cameraIndex)
{
    ObjIter begin = this->scene.modelBegin();
    ObjIter end = this->scene.modelEnd();
    this->drawManager.drawModel(drw, begin, end, this->scene.getCamera(cameraIndex));
}

#endif // FACADE_HPP

