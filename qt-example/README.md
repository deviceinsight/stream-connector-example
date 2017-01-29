qt-connector-example
====================

Install requirements
--------------------

    sudo apt-get install libqt4-dev libqjson-dev


Building the example
--------------------

Create config file:

    cp local.cmake.template local.cmake

Compile with:

    mkdir build
    cd build
    cmake ..
    make

Run the example:

    cd build
    cd src
    { echo '{"interval": 5 }' ; cat ; } | ./connector-qt-example


