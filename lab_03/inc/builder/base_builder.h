//
// Created by amunra23 on 20.05.2021.
//

#ifndef BASE_BUILDER_H
#define BASE_BUILDER_H

#include "../model/object.h"

class BaseBuilder
{
public:
    BaseBuilder() = default;
    ~BaseBuilder() = default;

    virtual std::shared_ptr<Object> get() = 0;

    virtual void build() = 0;
    virtual bool is_build() const = 0;
};

#endif //BASE_BUILDER_H
