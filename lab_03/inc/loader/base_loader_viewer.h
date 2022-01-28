//
// Created by amunra23 on 22.05.2021.
//

#ifndef LOADER_VIEWER_H
#define LOADER_VIEWER_H

#include "base_loader.h"
#include "../builder/builder_viewer.h"

class BaseLoaderViewer : public BaseLoader
{
public:
    virtual std::shared_ptr<Object> load(std::shared_ptr<BuilderViewer> builder) = 0;
};

#endif //LOADER_VIEWER_H
