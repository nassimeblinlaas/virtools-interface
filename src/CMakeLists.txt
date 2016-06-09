SET(LIBRARY_NAME ${PROJECT_NAME})
SET(IDL_SOURCES
  virtools-interface
  )

OMNIIDL_INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/idl)
INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR}/src)
FOREACH(IDL ${IDL_SOURCES})
  GENERATE_IDL_CPP (gepetto/virtools/corba/${IDL}
    ${CMAKE_SOURCE_DIR}/idl/gepetto/virtools)
ENDFOREACH()

ADD_LIBRARY(${LIBRARY_NAME}
  SHARED
  virtools-interface.impl.cpp
  virtools-interface.impl.hh
  virtools-manager.cpp
  server.cc
  client.cc
  server-private.cc
  server-private.hh
  ${CMAKE_CURRENT_BINARY_DIR}/gepetto/virtools/corba/virtools-interface_idl.py
  ${CMAKE_CURRENT_BINARY_DIR}/gepetto/virtools/corba/virtools-interface.hh
  ${CMAKE_CURRENT_BINARY_DIR}/gepetto/virtools/corba/virtools-interfaceSK.cc
)

PKG_CONFIG_USE_DEPENDENCY(${LIBRARY_NAME} omniORB4)
PKG_CONFIG_USE_DEPENDENCY(${LIBRARY_NAME} urdfdom)
PKG_CONFIG_USE_DEPENDENCY(${LIBRARY_NAME} virtools)
TARGET_LINK_LIBRARIES(${LIBRARY_NAME} ${Boost_LIBRARIES})

INSTALL(TARGETS ${LIBRARY_NAME} DESTINATION lib)

# search for python
FINDPYTHON()

MAKE_DIRECTORY(${CMAKE_CURRENT_BINARY_DIR}/gepetto/virtools/corba)

FOREACH (IDL ${IDL_SOURCES})
  ADD_CUSTOM_COMMAND(
    OUTPUT
    ${CMAKE_CURRENT_BINARY_DIR}/gepetto/virtools/corba/${IDL}_idl.py
    COMMAND ${OMNIIDL}
    ARGS -bpython -Wbpackage="" -I${CMAKE_SOURCE_DIR}/idl
    ${CMAKE_SOURCE_DIR}/idl/gepetto/virtools/${IDL}.idl
    MAIN_DEPENDENCY
    ${CMAKE_SOURCE_DIR}/idl/gepetto/virtools/${IDL}.idl
    )
  SET_SOURCE_FILES_PROPERTIES(
    ${CMAKE_CURRENT_BINARY_DIR}/gepetto/virtools/corba/${IDL}_idl.py
    PROPERTIES GENERATED ON
    )
  INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/gepetto/virtools/corba/${IDL}.hh
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/gepetto/virtools/corba)

  STRING(REGEX REPLACE "-" "_"
    IDL_UNDERSCORE "${IDL}")

  INSTALL(
    FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${IDL_UNDERSCORE}_idl.py
    DESTINATION ${PYTHON_SITELIB}/gepetto/corbaserver
    )
ENDFOREACH()

INSTALL(
  FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/gepetto/corbaserver/__init__.py
  DESTINATION ${PYTHON_SITELIB}/gepetto/corbaserver
  )
INSTALL(
  FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/gepetto/corbaserver/client.py
  DESTINATION ${PYTHON_SITELIB}/gepetto/corbaserver
  )
INSTALL(
  FILES
  ${CMAKE_SOURCE_DIR}/idl/gepetto/virtools/virtools-interface.idl
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/idl/gepetto/corbaserver
)

INSTALL (FILES
  ${CMAKE_CURRENT_BINARY_DIR}/gepetto/virtools/corba/virtools-interface.hh
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/gepetto/virtools/corba
  )

# Standalone corba server
ADD_EXECUTABLE (gepetto-virtools-server corbaserver.cc)
TARGET_LINK_LIBRARIES(gepetto-virtools-server ${LIBRARY_NAME})
#TARGET_LINK_LIBRARIES(gepetto-viewer-server ${Boost_LIBRARIES})

ADD_EXECUTABLE (virtools-test test.cc)
TARGET_LINK_LIBRARIES(virtools-test ${LIBRARY_NAME})
PKG_CONFIG_USE_DEPENDENCY(virtools-test virtools)

INSTALL (TARGETS gepetto-virtools-server DESTINATION bin)
