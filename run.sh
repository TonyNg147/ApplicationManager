#!/bin/sh
version=$(ls ~/Qt/ | grep "[0-9]")
LD_LIBRARY_PATH=$HOME/Qt/${version}/gcc_64/lib${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}:$PWD/build/apps/libraries
export LD_LIBRARY_PATH
QT_PLUGIN_PATH=$HOME/Qt/${version}/gcc_64/plugins${QT_PLUGIN_PATH:+:$QT_PLUGIN_PATH}
export QT_PLUGIN_PATH
exec "$HOME"/Qt/"$version"/gcc_64/bin/appman -c "$PWD"/build/am-config.yaml "$@"