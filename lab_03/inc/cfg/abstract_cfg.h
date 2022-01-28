//
// Created by amunra23 on 22.05.2021.
//

#ifndef ABSTRACT_CFG_H
#define ABSTRACT_CFG_H

#include <memory>
#include <string>

class AbstractConfig
{
public:
    explicit AbstractConfig(std::shared_ptr<std::string> source = nullptr) : _source(source) { };
    virtual void read_cfg(std::shared_ptr<std::string> source = nullptr) = 0;

    enum frames { QT };
    enum sources { FILE };

    virtual AbstractConfig::frames get_frame() = 0;
    virtual AbstractConfig::sources get_load_source() = 0;

protected:
    std::shared_ptr<std::string> _source;
};

#endif //ABSTRACT_CFG_H
