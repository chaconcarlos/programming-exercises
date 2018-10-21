#!/bin/bash
#
# File: create-debug-makefiles.sh
#
# This creates a the debug makefiles.
#
# Date: Sat Oct 20 18:40:00 EST 2018
# Author: carlos.chacon
#

if [ -d build ]; then
  echo "Removing build directory..."
  rm -rf build &> /dev/null
fi

# deletes auto-generated source files
echo "Removing auto-generated source files..."
find ./ -type f -name "*~" -exec rm -f {} \; &> /dev/null
find ./ -type f -name "config.h" -exec rm -f {} \; &> /dev/null
rm -rf _CPack_Packages

# deletes build system generated files
echo "Removing generated files by the build system..."

echo "Removing generated files by the applications..."
rm -rf *.log &> /dev/null

echo "Done"
