// Copyright (C) 2014 LAAS-CNRS.
//
// This file is part of the SceneViewer-corba.
//
// This software is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the
// implied warranties of fitness for a particular purpose.
//
// See the COPYING file for more information.

#ifndef SCENEVIEWER_CORBASERVER_FWD_HH
# define SCENEVIEWER_CORBASERVER_FWD_HH

//FIXME: should be replaced by CORBA base types forward declarations.
# include <omniORB4/CORBA.h>

namespace virtools 
{
  namespace corbaServer
  {
    class Server;
 
    namespace impl
    {
      using CORBA::Boolean;
      using CORBA::Double;
      using CORBA::Short;
      using CORBA::SystemException;
      using CORBA::ULong;
      using CORBA::UShort;

      class VirtoolsInterface;
      class Server;
    } // end of namespace impl
  } // end of namespace corbaServer.
} // end of namespace hpp.

#endif //! SCENEVIEWER_CORBASERVER_FWD_HH

