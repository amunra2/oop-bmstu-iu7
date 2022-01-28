#include "../../inc/drawer/drawer_qt_factory.h"

DrawerQtFactory::DrawerQtFactory(QGraphicsScene *scene)
{
    _scene = scene;
}

std::unique_ptr<AbstractDrawer> DrawerQtFactory::graphic_create()
{
    return std::unique_ptr<AbstractDrawer>(new DrawerQt(_scene));
}



