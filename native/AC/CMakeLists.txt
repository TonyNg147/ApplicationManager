project(AC)
set(CMAKE_PREFIX_PATH "~/Qt/6.2.7/gcc_64")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt6 COMPONENTS AppManLauncherPrivate 
                 COMPONENTS Quick)
set(SOURCES main.cpp)
qt6_add_resources(SOURCES HMIResources.qrc)
qt6_add_executable(AC ${SOURCES})

target_include_directories(AC PUBLIC View
                              PRIVATE ${PROJECT_SOURCE_DIR}/../UICommon/HMIController/ScreenManager
                              PRIVATE ${PROJECT_SOURCE_DIR}/../UICommon/HMIController/ViewController
                              PRIVATE ${PROJECT_SOURCE_DIR}/../UICommon/HMIController/HMIDefines
                              )
target_link_directories(AC PRIVATE ${PROJECT_BINARY_DIR}/../../apps/libraries)
target_link_libraries(AC PRIVATE Qt6::AppManLauncherPrivate
                         PRIVATE Qt6::Quick
                         PRIVATE UICommon)

set_target_properties(AC
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../../apps/AC
)

