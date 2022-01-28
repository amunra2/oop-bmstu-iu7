//
// Created by amunra23 on 23.05.2021.
//

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <memory>
#include <libconfig.h++>

#include "abstract_cfg.h"
#include "../drawer/abstract_drawer.h"

#define CFG_FILE "/home/amunra23/studying/sem4/oop/lab_03/lab_03/data/config.cfg"


class Configuration : public AbstractConfig
{
public:
    explicit Configuration(std::shared_ptr<std::string> &source);
    void read_cfg(std::shared_ptr<std::string> source = nullptr) override;

    AbstractConfig::frames get_frame() override;
    AbstractConfig::sources get_load_source() override;

private:
    std::shared_ptr<libconfig::Config> _cfg;
};



#endif //CONFIGURATION_H
