
#ifndef FFF_CLIENT_HH
#define FFF_CLIENT_HH

#include <iostream>
#include <omniORB4/CORBA.h>
#include <gepetto/virtools/corba/virtools-interface.hh>


namespace virtools {
namespace corbaServer {
  class Client
  {
    public:
      typedef CORBA::ULong WindowID;

      Client (int argc, char* argv[]);

      ~Client ();

      void connect (const char* iiop = "corbaloc:iiop:192.168.0.12:2809/NameService");

      gepetto::corbaserver::VirtoolsInterface_var& gui () {
        return gui_;
      }

    private:
      gepetto::corbaserver::VirtoolsInterface_var gui_;

      CORBA::ORB_var orb_;
  };
}
}

#endif
