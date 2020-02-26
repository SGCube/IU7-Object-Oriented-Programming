#include "model.h"

Model::Model(const std::vector<Vertex> vertices_, const std::vector<Edge> edges_)
{
	vertices = vertices_;
	edges = edges_;
}

Model::Model(const Model& model)
{
	this->vertices = model.vertices;
	this->edges = model.edges;
}

Model::Model(Model&& model)
{
	this->vertices = model.vertices;
	this->edges = model.edges;
	model.~Model();
}

Model& Model::operator=(const Model& model)
{
	this->vertices = model.vertices;
	this->edges = model.edges;
	return *this;
}

Model& Model::operator=(Model&& model)
{
	this->vertices = model.vertices;
	this->edges = model.edges;
	model.~Model();
	return *this;
}

std::vector<Vertex> Model::getVertices() const
{
	return vertices;
}

std::vector<Edge> Model::getEdges() const
{
	return edges;
}

void Model::addVertex(const Vertex &vertex)
{
	vertices.push_back(vertex);
}

void Model::addEdge(const Edge& edge)
{
	edges.push_back(edge);
}

void Model::move(double dx, double dy, double dz)
{
	for (size_t i = 0; i < vertices.size(); i++)
		vertices[i].move(dx, dy, dz);
}

void Model::scale(double kx, double ky, double kz)
{
	for (size_t i = 0; i < vertices.size(); i++)
		vertices[i].scale(kx, ky, kz);
}

void Model::rotate(double ax, double ay, double az)
{
	for (size_t i = 0; i < vertices.size(); i++)
	{
		vertices[i].rotateX(ax);
		vertices[i].rotateY(ay);
		vertices[i].rotateZ(az);
	}
}
