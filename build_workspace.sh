#!/bin/bash
#
# File: create-debug-makefiles.sh
#
# This creates a the debug makefiles.
#
# Date: Sat Oct 20 18:40:00 EST 2018
# Author: carlos.chacon
#

ARCH=""
CMAKELISTS_DIR="."
BUILD_DIR="build"
CMAKE_USER_OPTIONS=""

for i in "$@"
do
  case $i in
    arch=*)
      ARCH="${i#*=}"
      shift
      ;;
    cmakelists=*)
      CMAKELISTS_DIR="${i#*=}"
      shift
      ;;
    builddir=*)
      BUILD_DIR="${i#*=}"
      shift
      ;;
    *)
      CMAKE_USER_OPTIONS=(${CMAKE_USER_OPTIONS} "$i")
      shift
      ;;
  esac
done

if [ -f ${CMAKELISTS_DIR}/VERSION ]
then
  . ${CMAKELISTS_DIR}/VERSION
  CMAKE_USER_OPTIONS=(${CMAKE_USER_OPTIONS[@]} "-DVERSION_MAJOR=${VERSION_MAJOR}" "-DVERSION_MINOR=${VERSION_MINOR}" "-DVERSION_REVISION=${VERSION_REVISION}" "-DVERSION_BUILD=${VERSION_BUILD}")
fi

CMAKE_USER_OPTIONS=(${CMAKE_USER_OPTIONS[@]} "-DCMAKE_BUILD_TYPE=Debug")

rm -rf ${BUILD_DIR}/CMakeCache.txt ${BUILD_DIR}/CMakeFiles
cmake "${CMAKE_OPTIONS[@]}" "${CMAKE_USER_OPTIONS[@]}" -B${BUILD_DIR} -H${CMAKELISTS_DIR}
