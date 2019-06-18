#include "drawmanager.h"

void DrawManager::drawModel(BaseDrawer& drw, const ObjIter& b, const ObjIter& e, \
               std::shared_ptr<Object> camera)
{
    std::shared_ptr<Camera> cm = std::static_pointer_cast<Camera>(camera);
    for (ObjIter iter = b; iter != e; iter++)
    {
        if (!(*iter))
            throw NoObjectToDrawException();

		std::shared_ptr<Model> model = std::static_pointer_cast<Model>(*iter);

		const std::vector<Edge> edges = model->getEdges();
		if (edges.empty())
			throw NoEdgesToDrawException();

		std::vector<Vertex> vertices = model->getVertices();
		if (vertices.empty())
			throw NoVerticesToDrawException();

		for (size_t i = 0; i < vertices.size(); ++i)
		{
			vertices[i].move(cm->getMoveX(), cm->getMoveY(), cm->getMoveZ());
			vertices[i].scale(cm->getScaleX(), cm->getScaleY(), cm->getScaleZ());

			vertices[i].rotateX(cm->getRotateX());
			vertices[i].rotateY(cm->getRotateY());
			vertices[i].rotateZ(cm->getRotateZ());
		}

		for (size_t i = 0; i < edges.size(); ++i)
		{
			const Vertex& v1 = vertices[edges[i].getStart()];
			const Vertex& v2 = vertices[edges[i].getEnd()];
			drw.drawLine(getX(v1.getX(), v1.getZ()),
						 getY(v1.getY(), v1.getZ()),
						 getX(v2.getX(), v2.getZ()),
						 getY(v2.getY(), v2.getZ()));
		}
    }
}

double DrawManager::getX(const double x, const double z) const
{
    return x + z * coeff3D;
}

double DrawManager::getY(const double y, const double z) const
{
    return -y - z * coeff3D;
}
