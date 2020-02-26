#ifndef MODEL_H
#define MODEL_H

#include <vector>

#include "object.h"
#include "vertex.h"
#include "edge.h"

class Model : public Object
{
public:
	Model() = default;
	Model(const std::vector<Vertex> vertices_, const std::vector<Edge> edges_);
	Model(const Model& model);
	Model(Model&& model);
	~Model() = default;
	
	Model& operator=(const Model& model);
	Model& operator=(Model&& model);
	
	std::vector<Vertex> getVertices() const;
	std::vector<Edge> getEdges() const;
	
	void addVertex(const Vertex& vertex);
	void addEdge(const Edge& edge);
	
	void move(double dx, double dy, double dz);
	void scale(double kx, double ky, double kz);
	void rotate(double ax, double ay, double az);
	
private:
	std::vector<Vertex> vertices;
	std::vector<Edge> edges;
};

#endif // MODEL_H
