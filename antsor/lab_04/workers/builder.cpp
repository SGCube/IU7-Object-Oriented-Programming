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

void ModelBuilder::buildVertex(const double x, const double y, const double z)
{
    if (!isModelBuilt())
        throw NoObjectToBuildException();

    Vertex vertex(x, y, z);
    this->model->addVertex(vertex);
}

void ModelBuilder::buildEdge(const size_t src, const size_t purp)
{
    if (!isModelBuilt())
        throw NoObjectToBuildException();

    Edge edge(src, purp);
    this->model->addEdge(edge);
}

bool ModelBuilder::isModelBuilt() const
{
    return (this->model == nullptr) ? false : true;
}

#endif // MODELBUILDER_HPP

