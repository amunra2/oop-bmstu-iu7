//
// Created by amunra23 on 22.05.2021.
//

#ifndef CREATOR_CFG_H
#define CREATOR_CFG_H

#pragma onсe

#include <memory>
#include "abstract_cfg.h"

class CreatorConfig {
public:
    std::shared_ptr<AbstractConfig> get_config(std::shared_ptr<std::string> source = nullptr);

private:
    void create_instance(std::shared_ptr<std::string> &source);

    std::shared_ptr<AbstractConfig> _config;
};


#endif //LAB_03_CREATOR_CFG_H
