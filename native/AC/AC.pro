QT += quick appman_launcher-private
TEMPLATE=app
include(View/View.pri)
include(HMIController/HMIController.pri)
RESOURCES+= \
            HMIResources.qrc
SOURCES+= \
        main.cpp

TARGET=AC
DESTDIR = $$OUT_PWD/../../apps/AC
LIBS+= -L $$OUT_PWD/../../apps/libraries -lUICommon

INCLUDEPATH += \
             $$PWD/../UICommon/HMIController/HMIDefines \
             $$PWD/../UICommon/HMIController/ScreenManager \
             $$PWD/../UICommon/HMIController/ViewController 
