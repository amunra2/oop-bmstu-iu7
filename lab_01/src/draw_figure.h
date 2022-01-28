#ifndef DRAW_FIGURE_H
#define DRAW_FIGURE_H


#include "lib_funcs.h"
#include "ui_mainwindow.h"
#include "read_file.h"

//using graph_canvas = QGraphicsScene;

//struct canvas_s
//{
//    graph_canvas *field;
//    double width;
//    double height;
//};

//using canvas_t = struct canvas_s;


err_t draw_object(points_t const &points, links_t const &links, canvas_t canvas);

void clear_canvas(canvas_t canvas);

#endif // DRAW_FIGURE_H
