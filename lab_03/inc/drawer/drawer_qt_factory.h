#ifndef DRAWER_QT_FACTORY_H
#define DRAWER_QT_FACTORY_H

#include "abstract_drawer_factory.h"
#include "drawer_qt.h"

#include "../cfg/abstract_cfg.h"

class DrawerQtFactory : public AbstractDrawerFactory
{
public:
    explicit DrawerQtFactory(QGraphicsScene *scene);

    std::unique_ptr<AbstractDrawer> graphic_create() override;

private:
    QGraphicsScene *_scene;
    std::shared_ptr<AbstractConfig> _conf;
};

#endif //DRAWER_QT_FACTORY_H
