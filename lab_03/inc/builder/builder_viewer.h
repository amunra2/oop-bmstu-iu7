//
// Created by amunra23 on 22.05.2021.
//

#ifndef BUILDER_VIEWER_H
#define BUILDER_VIEWER_H

#include "../viewer/viewer.h"
#include "base_builder.h"

class BuilderViewer : public BaseBuilder
{
public:
    BuilderViewer() = default;
    ~BuilderViewer() = default;

    void build() override;
    void build_position(const double x, const double y, const double z);
    bool is_build() const override;

    std::shared_ptr<Object> get() override;

private:
    std::shared_ptr<Viewer> _viewer_ptr;
};

#endif //BUILDER_VIEWER_H
