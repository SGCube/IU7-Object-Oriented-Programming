#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include "gui/drawer.h"
#include "scene/scene.h"
#include "exception/drawexception.h"

class DrawManager
{
public:
    DrawManager() = default;
    ~DrawManager() = default;

    void drawModel(BaseDrawer &drw, const ObjIter& b, const ObjIter& e, \
                   std::shared_ptr<Object> camera);

private:
    static constexpr double coeff3D = 0.5;

    double getX(const double x, const double z) const;
    double getY(const double y, const double z) const;
};

#endif // DRAWMANAGER_H
