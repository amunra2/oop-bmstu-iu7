//
// Created by amunra23 on 22.05.2021.
//

#ifndef LOAD_MODEL_MODERATOR_H
#define LOAD_MODEL_MODERATOR_H

#include "abstract_load_moderator.h"
#include "../../loader/base_loader_model.h"
#include "../../loader/base_loader.h"
#include "../../builder/builder_model.h"

class LoadModelModerator : public AbstractLoadModerator
{
public:
    explicit LoadModelModerator(std::shared_ptr<BaseLoaderModel> loader);

    ~LoadModelModerator() = default;

    std::shared_ptr<Object> load(std::string &file_name) override;

private:
    std::shared_ptr<BuilderModel> _builder;
    std::shared_ptr<BaseLoaderModel> _loader;
};

#endif //LOAD_MODEL_MODERATOR_H
