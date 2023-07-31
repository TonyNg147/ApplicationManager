project(APP_MAN)
cmake_minimum_required(VERSION 3.6)
set(CMAKE_PREFIX_PATH "~/Qt/6.2.7/gcc_64")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
if(NOT DEFINED INSTALL_EXAMPLESDIR)
  set(INSTALL_EXAMPLESDIR "Qt")
endif()

set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}/applicationmanager/AM")
message(${INSTALL_EXAMPLEDIR})
find_package(Qt6 COMPONENTS AppManMainPrivate)

qt6_am_add_systemui_wrapper(AM
    CONFIG_YAML am-config.yaml
    EXTRA_FILES apps system-ui
)
add_subdirectory(native)