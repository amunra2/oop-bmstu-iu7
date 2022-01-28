//
// Created by amunra23 on 23.05.2021.
//

#include <sstream>
#include "../../inc/cfg/configuration.h"
#include "../../inc/exceptions.h"
#include <libconfig.h++>


Configuration::Configuration(std::shared_ptr<std::string> &source) :
        AbstractConfig(source) { }

void Configuration::read_cfg(std::shared_ptr<std::string> source)
{
    _cfg = std::make_shared<libconfig::Config>();


    try
    {
        _cfg->readFile(_source ? _source->c_str() : source->c_str());
    }
    catch (const libconfig::FileIOException &fioex)
    {
        auto msg = std::string("I/O error while reading file.");
        throw SourceException(msg);
    }
    catch (const libconfig::ParseException &pex)
    {
        std::stringstream msg;

        msg << "Parse error at " << pex.getFile() << ":" << pex.getLine()
            << " - " << pex.getError() << std::endl;

        auto str = msg.str();

        throw SourceException(str);
    }
}

AbstractConfig::frames Configuration::get_frame()
{
    if (!_cfg)
        read_cfg(std::make_shared<std::string>(CFG_FILE));

    auto &root = _cfg->getRoot();

    std::string frame;

    try {
        const auto &ui = root["graphics"];

        if (!ui.lookupValue("frame", frame))
            frame = "qt";

    }
    catch (const libconfig::SettingNotFoundException &nfex) {
        return QT;
    }

    if ("qt" == frame)
    {
        return QT;
    } else {
        return QT;
    }
}


AbstractConfig::sources Configuration::get_load_source() {
    if (!_cfg)
        read_cfg(std::make_shared<std::string>(CFG_FILE));

    auto &root = _cfg->getRoot();

    std::string frame;

    try {
        const auto &ui = root["storage"];

        if (!ui.lookupValue("load_source", frame))
            frame = "file";

    } catch (const libconfig::SettingNotFoundException &nfex) {
        return FILE;
    }

    if ("file" == frame) {
        return FILE;
    } else {
        return FILE;
    }
}







