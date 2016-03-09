qt-connector-example
=====================

Requiremments:

QJSon from http://qjson.sourceforge.net

Install:

build from source or install as package (e.g. Ubuntu: "apt-get install libqjson0 libqjson-dev"

You may need to add the include path to CMakeLists.txt if libqjson is not installed in a default location (e.g. /usr/local/lib & /usr/local/include).

And may be you need to change the path to libqjson.so from trhe default which is /usr/lib/libqjson.so

If so, add e.g.

SET (QJSON_LIB /usr/lib/x86_64-linux-gnu/libqjson.so)

to your local.cmake


Prepare configuration settings
    
    cp local.cmake.template local.cmake

Compile with

    mkdir build
    cd build
    cmake ..
    make

Start:

    cd build
    cd src
    { echo '{"interval": 5 }' ; cat ; } | ./connector-qt-example


