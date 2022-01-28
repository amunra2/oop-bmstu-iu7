#include "lib_funcs.h"


void clear_canvas(canvas_t canvas) // canvas (fixed)
{
    canvas.field->clear();
}


err_t draw_line_func_parse(dot_t point1, dot_t point2, canvas_t canvas)
{
    if (canvas.field == NULL)
    {
        return ERR_NO_FIELD;
    }

    canvas.field->addLine(point1.x, point1.y, point2.x, point2.y, QPen(Qt :: blue, 3));

    return OK;
}
