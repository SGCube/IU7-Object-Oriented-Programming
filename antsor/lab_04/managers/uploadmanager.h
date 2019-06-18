#ifndef UPLOADMANAGER_H
#define UPLOADMANAGER_H

#include "workers/uploader.h"

class UploadManager
{
public:
    UploadManager() = default;
    ~UploadManager() = default;
    
    std::shared_ptr<Model> uploadModel(BaseUploader& upld, BaseBuilder& bld)
    {
        upld.openSrc();
        std::shared_ptr<Model> model(upld.uploadModel(bld));
        upld.closeSrc();

        return model;
    }
};

#endif // UPLOADMANAGER_H

