//
// Created by amunra23 on 22.05.2021.
//

#include "../../inc/facade/facade.h"


void Facade::exec(BaseCommand &command)
{
    command.exec();
}
