#ifndef READ_FILE_H
#define READ_FILE_H

#include "stdio.h"
#include "stdlib.h"

#include "error_list.h"


struct link_dots_s
{
    int point_begin;
    int point_end;
};

using link_dots_t = struct link_dots_s;


struct links_s
{
    link_dots_t *data;
    int len;
};

using links_t = struct links_s;


struct dot_s
{
    double x;
    double y;
    double z;
};

using dot_t = struct dot_s;


struct points_s
{
    dot_t *data;
    int len;
};

using points_t = struct points_s;


struct figure_s
{
    points_t points;
    links_t links;
    dot_t center;
};

using figure_t = struct figure_s;


void points_init(points_t &points);

void free_points(points_t &points);

void links_init(links_t &links);

void free_links(links_t &links);

void center_init(dot_t &center);

err_t read_figure(figure_t &figure, FILE *file);

figure_t &figure_init(void);


#endif // READ_FILE_H
