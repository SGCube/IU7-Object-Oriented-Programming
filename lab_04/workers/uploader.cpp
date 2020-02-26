#ifndef UPLOADER_HPP
#define UPLOADER_HPP

#include "uploader.h"

ModelUploader::ModelUploader(const std::string& fileName) :
	fileName(fileName) {}

std::shared_ptr<Model> ModelUploader::uploadModel(BaseBuilder& builder)
{
    try
    {
        builder.buildModel();

        size_t countEdges;
        size_t src, purp;

        file >> countEdges;

        for (size_t i = 0; i < countEdges; ++i)
        {
            file >> src >> purp;
            builder.buildEdge(src, purp);
        }

        size_t countVertices;
        double x, y, z;

        file >> countVertices;

        for (size_t i = 0; i < countVertices; ++i)
        {
            file >> x >> y >> z;
            builder.buildVertex(x, y, z);
        }
    }
    catch (const std::ifstream::failure& e)
    {
        throw ReadFileException();
    }

    return builder.getModel();
}

void ModelUploader::openSrc()
{
    this->file.open(this->fileName);
    if (!file)
        throw OpenFileException();
}

void ModelUploader::closeSrc()
{
    try
    {
        this->file.close();
    }
    catch (const std::ifstream::failure& e)
    {
        throw CloseFileException();
    }
}

#endif // UPLOADER_HPP

