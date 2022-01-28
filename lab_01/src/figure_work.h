#ifndef FIGURE_WORK_H
#define FIGURE_WORK_H

#include "read_file.h"
#include "draw_figure.h"
#include "change_figure.h"

using filename_t = const char *;


err_t load_figure(figure_t &figure, filename_t file_name);

void figure_free(figure_t &figure);

err_t spin_figure(points_t &points, dot_t center, change_t spin_angles);

err_t move_figure(points_t &points, dot_t &center, change_t movements);

err_t scale_figure(points_t &points, dot_t center, change_t scale_koefs);

err_t draw_figure(points_t const &points, links_t const &links, canvas_t canvas);

#endif // FIGURE_WORK_H
