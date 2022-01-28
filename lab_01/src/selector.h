#ifndef SELECTOR_H
#define SELECTOR_H

#include "figure_work.h"

enum Actions {
    DRAW,
    LOAD,
    SCALE,
    SPIN,
    MOVE,
    QUIT
};


struct event_s
{
    canvas_t canvas;
    change_t change;
    filename_t file_name;
};

using event_t = struct event_s;

err_t select_action(Actions action, event_t event);



#endif // SELECTOR_H
