#ifndef CHANGE_FIGURE_H
#define CHANGE_FIGURE_H

#include <math.h>
#include "error_list.h"
#include "read_file.h"

#define PI 3.1415
#define TO_RADIANS 360


struct change_s
{
    double chg_x;
    double chg_y;
    double chg_z;
};

using change_t = struct change_s;


err_t spin_dot(dot_t &point, dot_t center, const change_t spin_angles);

err_t move_dot(dot_t &point, const change_t move);

err_t scale_dot(dot_t &point, dot_t center, const change_t scale);


#endif // CHANGE_FIGURE_H
