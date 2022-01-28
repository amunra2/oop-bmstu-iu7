#include "figure_work.h"


void figure_free(figure_t &figure)
{
    free_points(figure.points);
    free_links(figure.links);
}


err_t load_figure(figure_t &figure, filename_t filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        return ERR_FILE_OPEN;
    }

    figure_t temp_figure;

    err_t rc = read_figure(temp_figure, file); // fixed

    fclose(file);

    if (rc == OK)
    {
        figure_free(figure);
        figure = temp_figure;
    }

    return rc;
}


err_t draw_figure(points_t const &points, links_t const &links, canvas_t canvas)
{
    if ((points.data == NULL) || (links.data == NULL))
    {
        return ERR_MEMORY_ALLOCATE;
    }

    if (canvas.field == NULL)
    {
        return ERR_NO_FIELD;
    }

    clear_canvas(canvas);

    err_t rc = draw_object(points, links, canvas);

    return rc;
}



err_t spin_figure(points_t &points, dot_t center, change_t spin_angles)
{
    if (points.data == NULL)
    {
        return ERR_NO_FIGURE;
    }

    err_t rc = OK;

    for (int i = 0; i < points.len && rc == OK; i++)
    {
        rc = spin_dot(points.data[i], center, spin_angles);
    }

    return rc;
}


err_t scale_figure(points_t &points, dot_t center,  change_t scale_koefs)
{
    if (points.data == NULL)
    {
        return ERR_NO_FIGURE;
    }

    err_t rc = OK;

    for (int i = 0; i < points.len && rc == OK; i++)
    {
        rc = scale_dot(points.data[i], center, scale_koefs);
    }

    return rc;
}


err_t move_figure(points_t &points, dot_t &center, change_t movements)
{
    if (points.data == NULL)
    {
        return ERR_NO_FIGURE;
    }

    err_t rc = OK;

    for (int i = 0; i < points.len && rc == OK; i++)
    {
        rc = move_dot(points.data[i], movements);
    }

    if (rc == OK)
    {
        move_dot(center, movements);
    }

    return rc;
}
