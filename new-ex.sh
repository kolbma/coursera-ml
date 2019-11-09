#!/bin/sh

exnr="$1"
exname="$2"

PATH="/usr/bin:/bin:/usr/sbin:/sbin"

script=`basename "$0"`
scriptdir=`cd \`pwd\` && echo "$PWD"`

exnr=`echo "$exnr" | tr -d -c '[:digit:]'`

if [ "x$exnr" != "x$1" ] ; then
    echo "$script: 1st argument needs to be exercise number" >&2
    exit 1
fi

exdir="$scriptdir/ex$exnr"
if [ ! -d "$exdir" ] ; then
    mkdir "$exdir"
fi

filenamelist() {
    exdir="$1"
    exnr="$2"
    exname="$3"
    echo "$exdir/$exname.hpp"
    echo "$exdir/$exname.cpp"
    echo "$exdir/${exname}_main.cpp"
    echo "$scriptdir/tests/ex${exnr}/${exname}_main.cpp"
}

filenamelist "$exdir" "$exnr" "$exname" | while read f ; do
    if [ -e "$f" ] ; then
        echo "$script: file $f already exists" >&2
        exit 1
    fi
done
rc=$?
if [ "$rc" -ne 0 ] ; then
    exit "$rc"
fi

exnameupcase=`echo "$exname" | tr '[:lower:]' '[:upper:]'`

cat >"$scriptdir/tests/ex${exnr}/${exname}_main.cpp" <<EOS
// test $exname
#include <cassert>
#include "../../ex${exnr}/${exname}.hpp"

using namespace std;

int main()
{
    assert(0 == 1);
    return -1;
}
EOS

cat >"$exdir/$exname.hpp" <<EOS
// $exname.hpp
#ifndef COURSERA_${exnameupcase}_HPP
#define COURSERA_${exnameupcase}_HPP



#endif // COURSERA_${exnameupcase}_HPP
EOS

cat >"$exdir/${exname}.cpp" <<EOS
// $exname.cpp
#include "$exname.hpp"

EOS

cat >"$exdir/${exname}_main.cpp" <<EOS
// ${exname}_main.cpp
#include "$exname.hpp"

using namespace std;

int main(int argc, char **argv)
{

    return 0;
}
EOS

sed -i "/^endif()/i \    add_executable(test_${exname} ${exname}_main.cpp) \
\n    add_dependencies(test_${exname} ${exname}) \
\n    target_link_libraries(test_${exname} \${CMAKE_BINARY_DIR}/ex${exnr}/CMakeFiles/${exname}.dir/${exname}.cpp.o) \
\n    # target_link_libraries(test_${exname} \${ARMADILLO_LIBRARIES} \${CMAKE_BINARY_DIR}/ex${exnr}/CMakeFiles/${exname}.dir/${exname}.cpp.o) \
\n \
\n    add_test(NAME ${exname}Test COMMAND test_${exname})\n" \
"$scriptdir/tests/ex${exnr}/CMakeLists.txt"

cat >>"$exdir/CMakeLists.txt" <<EOS

add_executable(${exname} ${exname}.cpp ${exname}_main.cpp)
# target_link_libraries(${exname} \${ARMADILLO_LIBRARIES})
EOS

exit 0
