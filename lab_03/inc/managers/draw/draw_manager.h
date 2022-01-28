#ifndef DRAW_MANAGER_H
#define DRAW_MANAGER_H

#include "../base_manager.h"
#include "../../model/dot.h"
#include "../../model/composite.h"
#include "../../model/object.h"
#include "../../viewer/viewer.h"

#include "../../drawer/abstract_drawer.h"
#include "../../visitor.h"

class DrawManager : public BaseManager, public Visitor
{
public:
    DrawManager() = default;
    DrawManager(const DrawManager &manager) = delete;
    DrawManager &operator = (const DrawManager &manager) = delete;

    ~DrawManager() = default;

    // Setters
    void set_viewer(std::shared_ptr<Viewer> viewer);
    void set_drawer(std::shared_ptr<AbstractDrawer> drawer);

    // Actions
    void visit(const Model &model) override;
    void visit(const Viewer &viewer) override {};
    void visit(const Composite &composite) override {};

private:
    Dot get_dot_proection(const Dot &dot);

    std::shared_ptr<Viewer> _viewer;
    std::shared_ptr<AbstractDrawer> _drawer;

};

#endif //DRAW_MANAGER_H
