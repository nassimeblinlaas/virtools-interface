CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET(CXX_DISABLE_WERROR true)

INCLUDE(cmake/base.cmake)
INCLUDE(cmake/idl.cmake)
INCLUDE(cmake/python.cmake)
INCLUDE(cmake/boost.cmake)

SET(PROJECT_NAME virtools-corba)
SET(PROJECT_DESCRIPTION "Corba server for virtoolsexe")
SET(PROJECT_URL "")

SET(${PROJECT_NAME}_HEADERS
  include/gepetto/virtools/corba/virtools-manager.h
  include/gepetto/virtools/corba/server.hh
  include/gepetto/virtools/corba/client.hh
  include/gepetto/virtools/corba/fwd.hh
  )

SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

SETUP_PROJECT ()

# Dependencies
ADD_REQUIRED_DEPENDENCY("omniORB4 >= 4.1.4")
ADD_REQUIRED_DEPENDENCY("openthreads >= 3.2")
ADD_REQUIRED_DEPENDENCY("gepetto-viewer")
ADD_REQUIRED_DEPENDENCY("urdfdom")
ADD_REQUIRED_DEPENDENCY("eigen3 >= v3.0.5")
ADD_REQUIRED_DEPENDENCY("virtools")
SEARCH_FOR_BOOST()

PKG_CONFIG_APPEND_LIBS(${PROJECT_NAME})

INCLUDE_DIRECTORIES(SYSTEM ${EIGEN3_INCLUDE_DIRS})

ADD_SUBDIRECTORY(src)

SETUP_PROJECT_FINALIZE()
