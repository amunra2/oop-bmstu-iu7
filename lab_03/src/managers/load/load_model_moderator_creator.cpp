//
// Created by amunra23 on 22.05.2021.
//

#include "../../../inc/managers/load/load_model_moderator_creator.h"
#include "../../../inc/cfg/creator_cfg.h"
#include "../../../inc/loader/loader_model_file.h"

std::shared_ptr<LoadModelModerator> LoadModelModeratorCreator::create_moderator()
{
    if (nullptr == _moderator)
    {
        create_instance();
    }

    return _moderator;
}

std::shared_ptr<LoadModelModerator> LoadModelModeratorCreator::create_moderator(const std::shared_ptr<BaseLoaderModel> &loader)
{
    if (nullptr == _moderator)
    {
        create_instance();
    }

    _moderator->set_loader(loader);

    return _moderator;
}

void LoadModelModeratorCreator::create_instance()
{
    static std::shared_ptr<LoadModelModerator> moderator;

    if (!moderator)
    {
        std::shared_ptr<BaseLoaderModel> loader;

        switch (CreatorConfig().get_config()->get_load_source())
        {
            case AbstractConfig::FILE:

            default:
                loader = std::shared_ptr<BaseLoaderModel>(new ModelLoaderFile);

        }

        moderator = std::make_shared<LoadModelModerator>(loader);
    }

    _moderator = moderator;
}

