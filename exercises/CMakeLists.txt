#
# File: CMakeLists.txt
#
# Date: Sat Oct 20 19:00:00 EST 2018
# Author: carlos.chacon
#

FILE (GLOB children RELATIVE ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_LIST_DIR}/*)
STRING (REGEX REPLACE "CMake[^;]+;?" "" children "${children}")

FOREACH(child ${children})
  IF(IS_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/${child})
    ADD_SUBDIRECTORY (${child})
  ENDIF()
ENDFOREACH()
