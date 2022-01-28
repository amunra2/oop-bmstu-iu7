#ifndef TRANSFORM_MANAGER_H
#define TRANSFORM_MANAGER_H

#include "../base_manager.h"
#include "../../model/object.h"


class TransformManager : public BaseManager
{
public:
    TransformManager() = default;
    TransformManager(const TransformManager &manager) = delete;
    TransformManager &operator = (const TransformManager &manager) = delete;

    ~TransformManager() = default;

    // Actions
    static void move_object(const std::shared_ptr<Object> &object, const double &dx, const double &dy, const double &dz);
    static void scale_object(const std::shared_ptr<Object> &object, const double &kx, const double &ky, const double &kz);
    static void spin_object(const std::shared_ptr<Object> &object, const double &ox, const double &oy, const double &oz);


    static void transform_object(const std::shared_ptr<Object> &object, const Dot &move, const Dot &scale, const Dot &spin);
};


#endif //TRANSFORM_MANAGER_H
