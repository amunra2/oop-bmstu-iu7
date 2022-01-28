//
// Created by amunra23 on 22.05.2021.
//


#include "../../../inc/managers/load/load_scene_moderator_creator.h"
#include "../../../inc/cfg/configuration.h"
#include "../../../inc/cfg/creator_cfg.h"
#include "../../../inc/loader/loader_scene_file.h"

std::shared_ptr<LoadSceneModerator> LoadSceneModeratorCreator::create_moderator()
{
    if (nullptr == _moderator)
    {
        create_instance();
    }

    return _moderator;
}

std::shared_ptr<LoadSceneModerator> LoadSceneModeratorCreator::create_moderator(const std::shared_ptr<BaseLoaderScene> &loader)
{
    if (nullptr == _moderator)
    {
        create_instance();
    }

    _moderator->set_loader(loader);

    return _moderator;
}

void LoadSceneModeratorCreator::create_instance()
{
    static std::shared_ptr<LoadSceneModerator> moderator;

    if (!moderator)
    {
        std::shared_ptr<BaseLoaderScene> loader;

        switch (CreatorConfig().get_config()->get_load_source())
        {
            case AbstractConfig::FILE:

            default:
                loader = std::shared_ptr<BaseLoaderScene>(new SceneLoaderFile);

        }

        moderator = std::make_shared<LoadSceneModerator>(loader);
    }

    _moderator = moderator;
}


