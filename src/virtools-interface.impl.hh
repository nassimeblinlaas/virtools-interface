//
//  GraphicalInterface.impl.hh
//  Corbaserver for SceneViewer
//
//  Created by Mathieu Geisert on November 2014.
//  Copyright (c) 2014 LAAS-CNRS. All rights reserved.
//

#ifndef SCENEVIEWER_CORBASERVER_GRAPHICALINTERFACE_HH
#define SCENEVIEWER_CORBASERVER_GRAPHICALINTERFACE_HH

#include <omniORB4/CORBA.h>

#include "gepetto/virtools/corba/server.hh"
#include "gepetto/virtools/corba/virtools-interface.hh"

namespace virtools {
namespace corbaServer {
namespace impl {


class VirtoolsInterface :
    public virtual POA_gepetto::corbaserver::VirtoolsInterface
{
private:
	typedef gepetto::Error Error;
	VirtoolsManagerPtr_t virtoolsManager_;
public:
    /**
        \brief Default constructor
        */
    VirtoolsInterface (corbaServer::Server* server);

	virtual void fonc() throw (Error);
}; // end of class

} /* namespace impl */
} /* namespace corbaServer */
} /* namespace fff*/

#endif /* SCENEVIEWER_CORBASERVER_GRAPHICALINTERFACE_HH */
