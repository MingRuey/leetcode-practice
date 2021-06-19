gtest() {
    if [ -z $1 ] || [ -z $2 ]; then
        echo "Usage: gtest target.cpp test_suite.cpp"
        return 1
    fi

    TARGET=$1;
    SUITE=$2;
    if [ ! -f $1 ]; then
        echo "Target file $1 not exist."
        return 1
    fi
    if [ ! -f $2 ]; then
        echo "TestSuite file $2 not exist."
        return 1
    fi

    odir=$(dirname $(realpath $2))
    id=$(basename $1 | grep -oP "^[\d]+")
    otarget="${odir}/${id}_out.cpp"
    otest="${odir}/${id}_test_out.cpp"
    obin="${odir}/${id}.bin"

    sed -e "1s@^@using namespace std;\n\n@" \
        -e "1s@^@#include <algorithm>\n@" \
        -e "1s@^@#include <vector>\n@" \
        -e "1s@^@#include <set>\n@" \
        -e "1s@^@#include <stdlib.h>\n@" $1 > $otarget

    sed -e "1s@^@#include \"$otarget\"\n\n@" \
        -e "1s@^@#include <gtest/gtest.h>\n@" \
        -e "1s@^@#include <gmock/gmock.h>\n@" $2 > $otest

    echo "\nint main(int argc, char **argv) {\n    testing::InitGoogleTest(&argc, argv);\n    return RUN_ALL_TESTS();\n}" >> $otest

    g++ $otest -o $obin -std=c++11 -lgtest -lpthread
    $obin
}

clear() {
    if [ -z $1 ]; then
        echo "Usage: clear target_directory"
        return 1
    fi

    if [ ! -d $1 ]; then
        echo "directory $1 not exist"
        return 1
    fi

    rm $1/*out*
    rm $/*.bin
}
