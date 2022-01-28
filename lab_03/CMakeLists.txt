cmake_minimum_required(VERSION 3.0)
project(lab_03)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)



add_executable(${PROJECT_NAME}
        src/main.cpp
        inc/mainwindow.h
        design.h
        src/mainwindow.cpp
        inc/model/dot.h
        src/model/dot.cpp
        src/model/link.cpp
        inc/model/link.h
        src/model/ModelStructure.cpp
        inc/model/ModelStructure.h
        src/model/Model.cpp
        inc/model/Model.h
        inc/model/object.h
        src/model/composite.cpp
        inc/model/composite.h
        src/viewer/viewer.cpp
        inc/viewer/viewer.h
        inc/visitor.h
        src/scene/scene.cpp
        inc/scene/scene.h
        inc/managers/base_manager.h
        src/managers/scene/scene_manager.cpp
        inc/managers/scene/scene_manager.h
        inc/managers/scene/scene_manager_creator.h
        src/managers/scene/scene_manager_creator.cpp
        inc/managers/transform/transform_manager_creator.h
        inc/managers/transform/transform_manager.h
        src/managers/transform/transform_manager.cpp
        src/managers/transform/transform_manager_creator.cpp
        src/managers/draw/draw_manager.cpp
        inc/managers/draw/draw_manager.h
        inc/managers/draw/draw_manager_creator.h
        src/managers/draw/draw_manager_creator.cpp
        inc/drawer/abstract_drawer.h
        inc/drawer/abstract_drawer_factory.h
        inc/drawer/drawer_qt.h
        src/drawer/drawer_qt.cpp
        inc/drawer/drawer_qt_factory.h
        src/drawer/drawer_qt_factory.cpp
        inc/managers/load/load_manager.h
        src/managers/load/load_manager.cpp
        inc/managers/load/abstract_load_moderator.h
        src/managers/load/abstract_load_moderator.cpp
        inc/managers/load/load_manager_creator.h
        src/managers/load/load_manager_creator.cpp
        inc/builder/base_builder.h
        inc/builder/builder_model.h
        src/builder/builder_model.cpp
        inc/builder/builder_viewer.h
        src/builder/builder_viewer.cpp
        src/builder/builder_scene.cpp
        inc/builder/builder_scene.h
        inc/loader/base_loader.h
        inc/loader/base_loader_model.h
        inc/loader/loader_model_file.h
        src/loader/loader_model_file.cpp
        inc/loader/base_loader_viewer.h
        inc/loader/loader_viewer_file.h
        src/loader/loader_viewer_file.cpp
        src/loader/loader_scene_file.cpp
        inc/loader/loader_scene_file.h
        inc/loader/base_loader_scene.h
        inc/managers/load/load_model_moderator.h
        src/managers/load/load_model_moderator.cpp
        src/managers/load/load_model_moderator_creator.cpp
        inc/managers/load/load_model_moderator_creator.h
        inc/managers/load/load_scene_moderator.h
        inc/managers/load/load_scene_moderator_creator.h
        src/managers/load/load_scene_moderator.cpp
        src/managers/load/load_scene_moderator_creator.cpp
        inc/commands/base_command.h
        inc/commands/viewer_command.h
        src/commands/viewer_command.cpp
        src/commands/model_command.cpp
        inc/commands/model_command.h
        src/commands/scene_command.cpp
        inc/commands/scene_command.h
        inc/facade/facade.h
        src/facade/facade.cpp
        inc/exceptions.h
        inc/cfg/abstract_cfg.h
        inc/cfg/creator_cfg.h
        src/cfg/creator_cfg.cpp
        src/cfg/configuration.cpp
        inc/cfg/configuration.h
        )
        
find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED} config++)
