#include <iostream>
#include "gepetto/virtools/corba/client.hh"
 
namespace virtools {

namespace corbaServer{

using CORBA::Exception;
    using CORBA::Object_var;
    using CORBA::SystemException;
    using CORBA::ORB_init;
    using CORBA::PolicyList;
    using omniORB::fatalException;

Client::Client(int argc, char *argv[]) :
      orb_ (CORBA::ORB_init (argc, argv))
    {
    }

void Client::connect (const char* iiop)
    {
	std::cout << "1 void Client::connect (const char* iiop)\n";
      // Get a reference to the Naming Service
      CORBA::Object_var rootContextObj = orb_->string_to_object(iiop);
      CosNaming::NamingContext_var nc =
        CosNaming::NamingContext::_narrow(rootContextObj.in());

      // Bind robotObj with name Robot to the hppContext:
      CosNaming::Name name;
      name.length(2);
      name[0].id = (const char *) "gepetto";
      name[0].kind = (const char *) "virtools";
      name[1].id = (const char *) "corbaserver";
      name[1].kind = (const char *) "interface";
	std::cout << "2 void Client::connect (const char* iiop)\n";
      // Invoke the root context to retrieve the object reference
      CORBA::Object_var managerObj = nc->resolve(name);
      // Narrow the previous object to obtain the correct type
      gui_ = gepetto::corbaserver::VirtoolsInterface::_narrow(managerObj.in());
    }

    /// \brief Shutdown CORBA server
    Client::~Client()
    {
      if (!CORBA::is_nil(orb_)) {
        try {
          orb_->destroy();
          std::cout << "Ending CORBA..." << std::endl;
        } catch(const CORBA::Exception& e) {
          std::cout << "orb->destroy failed" << std::endl;
        }
      }
    

}

}
}
