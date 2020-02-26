#ifndef MODELUPLOADER_H
#define MODELUPLOADER_H

#include "exception/uploaderexception.h"
#include "workers/builder.h"

#include <fstream>

class BaseUploader
{
public:
    BaseUploader() = default;
    virtual ~BaseUploader() = default;

    virtual std::shared_ptr<Model> uploadModel(BaseBuilder& builder) = 0;
    virtual void openSrc() = 0;
    virtual void closeSrc() = 0;
};

class ModelUploader : public BaseUploader
{
public:
    explicit ModelUploader(const std::string& fileName);
    ~ModelUploader() = default;

    std::shared_ptr<Model> uploadModel(BaseBuilder &builder) override;

    void openSrc() override;
    void closeSrc() override;

private:
    std::string fileName;
    std::ifstream file;
};

#endif // MODELUPLOADER_H

