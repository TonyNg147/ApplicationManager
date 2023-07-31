project(UICommon)
set(CMAKE_PREFIX_PATH "~/Qt/6.2.7/gcc_64")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt6 COMPONENTS Quick)
set(SOURCES HMIController/ScreenManager/ScreenManager.cpp
            HMIController/ViewController/HMIController.cpp
            HMIController/HMIDefines/ViewEnums.h)
add_library(UICommon SHARED ${SOURCES})

target_include_directories(UICommon PUBLIC HMIController/ScreenManager
                                    PUBLIC HMIController/ViewController
                                    PUBLIC HMIController/HMIDefines)
target_link_libraries(UICommon PUBLIC Qt6::Quick)
message(${PROJECT_BINARY_DIR}/../../apps/libraries)
set_target_properties(UICommon
    PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../../apps/libraries
)

