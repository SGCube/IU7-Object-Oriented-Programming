#ifndef MODELBUILDER_HPP
#define MODELBUILDER_HPP

#include "builder.h"

ModelBuilder::ModelBuilder() : model(nullptr) {}

std::shared_ptr<Model> ModelBuilder::getModel() const
{
    return model;
}

void ModelBuilder::buildModel()
{
    model = std::make_shared<Model>();
}

void ModelBuilder::buildVertex(double x, double y, double z)
{
    if (!isModelBuilt())
        throw NoObjectToBuildException();

    Vertex vertex(x, y, z);
    this->model->addVertex(vertex);
}

void ModelBuilder::buildEdge(size_t src, size_t purp)
{
    if (!isModelBuilt())
        throw NoObjectToBuildException();

    Edge edge(src, purp);
    this->model->addEdge(edge);
}

bool ModelBuilder::isModelBuilt() const
{
    return this->model != nullptr;
}

#endif // MODELBUILDER_HPP

