//
// Created by amunra23 on 19.05.2021.
//

#include "../../../inc/managers/load/abstract_load_moderator.h"

void AbstractLoadModerator::set_loader(std::shared_ptr<BaseLoader> loader)
{
    _loader = loader;
}

