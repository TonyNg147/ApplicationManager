find_package(Qt6 COMPONENTS WaylandClient)

if(TARGET Qt::WaylandClient AND TARGET Qt::Widgets)
    add_subdirectory(UICommon)
    add_subdirectory(AC)
endif()
