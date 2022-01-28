#include "draw_figure.h"


static err_t draw_figure_side(link_dots_t link, points_t points, canvas_t canvas)
{
    if (points.data == NULL)
    {
        return ERR_MEMORY_ALLOCATE;
    }

    if (canvas.field == NULL)
    {
        return ERR_NO_FIELD;
    }

    dot_t point1 = points.data[link.point_begin];
    dot_t point2 = points.data[link.point_end];

    point1.x += canvas.width / 2;
    point1.y += canvas.height / 2;

    point2.x += canvas.width / 2;
    point2.y += canvas.height / 2;

    err_t rc = draw_line_func_parse(point1, point2, canvas);

    return rc;
}


err_t draw_object(points_t const &points, links_t const &links, canvas_t canvas)
{
    if ((points.data == NULL) || (links.data == NULL))
    {
        return ERR_MEMORY_ALLOCATE;
    }

    if (canvas.field == NULL)
    {
        return ERR_NO_FIELD;
    }

    err_t rc = OK;

    for (int i = 0; i < links.len && rc == OK; i++)
    {
        rc = draw_figure_side(links.data[i], points, canvas);
    }

    return rc;
}
