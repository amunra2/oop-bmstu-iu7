//
// Created by amunra23 on 22.05.2021.
//

#ifndef LOADER_VIEWER_FILE_H
#define LOADER_VIEWER_FILE_H

#include "base_loader_viewer.h"

class ViewerLoaderFile : public BaseLoaderViewer
{
public:
    ViewerLoaderFile();
    explicit ViewerLoaderFile(std::shared_ptr<std::ifstream> &file_in);

    ~ViewerLoaderFile() override = default;

    void open(std::string &file_name) override;
    void close() override;

    std::shared_ptr<Object> load(std::shared_ptr<BuilderViewer> builder) override;

protected:
    std::shared_ptr<std::ifstream> _file;
};

#endif //LOADER_VIEWER_FILE_H
