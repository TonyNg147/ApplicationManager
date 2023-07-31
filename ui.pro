TEMPLATE = app
CONFIG += am-systemui

OTHER_FILES += \
    am-config.yaml \
    system-ui/*.qml \
    system-ui/*.png \
    apps/AC/

target.path = $$[QT_INSTALL_EXAMPLES]/applicationmanager/application-features
INSTALLS += target

AM_COPY_DIRECTORIES += apps system-ui
AM_COPY_FILES += am-config.yaml

prefix_build:tpath = $$target.path
else:tpath = $$OUT_PWD
AM_DEFAULT_ARGS = -c $$tpath/am-config.yaml
