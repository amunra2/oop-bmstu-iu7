#include "change_figure.h"


static double cosinus(const double angle)
{
    return cos(angle * PI / TO_RADIANS);
}


static double sinus(const double angle)
{
    return sin(angle * PI / TO_RADIANS);
}


static err_t spin_x(dot_t &point, const double angle) // center add (fixed)
{
    double y_tmp = point.y;
    double cos_of_angle = cosinus(angle);
    double sin_of_angle = sinus(angle);

    point.y = point.y * cos_of_angle + point.z * sin_of_angle;
    point.z = point.z * cos_of_angle - y_tmp * sin_of_angle;

    return OK;
}


static err_t spin_y(dot_t &point, const double angle)
{
    double x_tmp = point.x;
    double cos_of_angle = cosinus(angle);
    double sin_of_angle = sinus(angle);

    point.x = point.x * cos_of_angle + point.z * sin_of_angle;
    point.z = point.z * cos_of_angle - x_tmp * sin_of_angle;

    return OK;
}


static err_t spin_z(dot_t &point, const double angle)
{
    double x_tmp = point.x;
    double cos_of_angle = cosinus(angle);
    double sin_of_angle = sinus(angle);

    point.x = point.x * cos_of_angle + point.y * sin_of_angle;
    point.y = point.y * cos_of_angle - x_tmp * sin_of_angle;

    return OK;
}


err_t spin_dot(dot_t &point, dot_t center, const change_t spin_angles)
{
    point.x -= center.x;
    point.y -= center.y;
    point.z -= center.z;

    err_t rc = OK;

    rc = spin_x(point, spin_angles.chg_x);

    if (rc != OK)
    {
        return rc;
    }

    rc = spin_y(point, spin_angles.chg_y);

    if (rc != OK)
    {
        return rc;
    }

    rc = spin_z(point, spin_angles.chg_z);

    point.x += center.x;
    point.y += center.y;
    point.z += center.z;

    return rc;
}


err_t scale_dot(dot_t &point, dot_t center, const change_t scale)
{
    point.x = point.x * scale.chg_x + (1 - scale.chg_x) * center.x;
    point.y = point.y * scale.chg_y + (1 - scale.chg_y) * center.y;
    point.z = point.z * scale.chg_z + (1 - scale.chg_z) * center.z;

    return OK;
}


err_t move_dot(dot_t &point, const change_t move)
{
    point.x += move.chg_x;
    point.y += move.chg_y;
    point.z += move.chg_z;

    return OK;
}
