//
// Created by amunra23 on 22.05.2021.
//

#ifndef LOAD_SCENE_MODERATOR_H
#define LOAD_SCENE_MODERATOR_H

//
// Created by amunra23 on 22.05.2021.
//

#ifndef LOAD_MODEL_MODERATOR_H
#define LOAD_MODEL_MODERATOR_H

#include "abstract_load_moderator.h"
#include "../../loader/base_loader_scene.h"
#include "../../loader/base_loader.h"
#include "../../builder/builder_scene.h"

class LoadSceneModerator : public AbstractLoadModerator
{
public:
    explicit LoadSceneModerator(std::shared_ptr<BaseLoaderScene> loader);

    ~LoadSceneModerator() = default;

    std::shared_ptr<Object> load(std::string &file_name) override;

private:
    std::shared_ptr<BuilderScene> _builder;
    std::shared_ptr<BaseLoaderScene> _loader;
};

#endif //LOAD_MODEL_MODERATOR_H


#endif //LOAD_SCENE_MODERATOR_H
