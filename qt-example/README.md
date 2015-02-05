qt-connector-example
=====================

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


