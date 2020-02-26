#ifndef DRAWER_H
#define DRAWER_H

#include <QGraphicsScene>

class BaseDrawer
{
public:
    BaseDrawer() = default;
    virtual ~BaseDrawer() = default;

    virtual void drawLine(const double x1, const double y1, const double x2,
                          const double y2) = 0;
};

class ModelDrawer : public BaseDrawer
{
public:
    ModelDrawer(QGraphicsScene* scene_) : BaseDrawer(), scene(scene_) {}
    ~ModelDrawer() = default;

    void drawLine(const double x1, const double y1, const double x2,
                  const double y2) override
    {
        scene->addLine(x1, y1, x2, y2);
    }

private:
    QGraphicsScene* scene;
};

#endif // DRAWER_H
