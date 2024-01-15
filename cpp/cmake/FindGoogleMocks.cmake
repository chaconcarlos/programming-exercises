#
# File: FindGoogleMocks.cmake
#
# Date: Mon Oct 18 09:21:00 EST 2013
# Author: richard.bastos
#
# Revision $Revision: 1$
#
# Copyright 2012 Smartmatic Corp. All Rights Reserved.
#
# Confidential Information of Smartmatic Labs. Not for disclosure or distribution
# prior written consent. This software contains code, techniques and know-how which
# is confidential and proprietary to Smartmatic.
#
# Use of this software is subject to the terms of an end user license agreement.
#
# Try to find libgmock library
# Once done this will define
#
# GOOGLE_MOCKS_FOUND  - if false, do not try to link to libgmock
# GOOGLE_LIBRARIES    - the library to link against
# GOOGLE_INCLUDE_DIRS - where to find headers.
#

INCLUDE (FindPackageHandleStandardArgs)

FIND_PACKAGE (Threads REQUIRED)

FIND_PATH (
  GOOGLE_MOCKS_INCLUDE_DIRS
  NAME gmock-actions.h
  DOC "Directory containing gmock-actions.h"
  PATH
    /usr/include
    /usr/local/include
    /opt/local/include
  PATH_SUFFIXES gmock
)

FIND_LIBRARY (
  GOOGLE_MOCKS_LIBRARY
  NAMES gmock gmock_main
  DOC "Path to the Google Mocks library"
  PATHS
    /usr/lib
    /usr/local/lib
    /opt/local/lib
)

FIND_PACKAGE_HANDLE_STANDARD_ARGS (GoogleMocks REQUIRED_VARS GOOGLE_MOCKS_LIBRARY GOOGLE_MOCKS_INCLUDE_DIRS)

SET (GOOGLE_MOCKS_LIBRARIES ${GOOGLE_MOCKS_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})

MARK_AS_ADVANCED (GOOGLE_MOCKS_LIBRARIES GOOGLE_MOCKS_INCLUDE_DIRS)
