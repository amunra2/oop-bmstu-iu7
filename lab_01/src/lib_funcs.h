#ifndef LIB_FUNCS_H
#define LIB_FUNCS_H

#include "ui_mainwindow.h"
#include "read_file.h"

using graph_canvas = QGraphicsScene;

struct canvas_s
{
    graph_canvas *field;
    double width;
    double height;
};

using canvas_t = struct canvas_s;

void clear_canvas(canvas_t canvas);

err_t draw_line_func_parse(dot_t point1, dot_t point2, canvas_t canvas);


#endif // LIB_FUNCS_H
