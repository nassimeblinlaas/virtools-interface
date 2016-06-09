//
//  GraphicalInterface.impl.cc
//  Corbaserver for gepetto-viewer
//
//  Author: Mathieu Geisert, Florent Lamiraux
//  Copyright (c) 2014 LAAS-CNRS. All rights reserved.
//

#include <iostream>
#include "gepetto/virtools/corba/server.hh"
#include "virtools-interface.impl.hh"

namespace virtools {
  namespace corbaServer {
    namespace impl {


      VirtoolsInterface::VirtoolsInterface (corbaServer::Server* server) : virtoolsManager_(server->virtoolsManager())
      {
      }

	void VirtoolsInterface::fonc() throw (Error){
		std::cout<< "virt inter impl cc fonc()\n";
		virtoolsManager_->fonc();

	}

    } //end namespace impl
  } //end namespace corbaServer
} //end namespace graphics
