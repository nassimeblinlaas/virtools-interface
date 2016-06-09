#include <iostream>
#include "gepetto/virtools/corba/server.hh"

using virtools::corbaServer::Server;

int main (int argc, const char* argv[])
{
  virtools::VirtoolsManagerPtr_t wm = virtools::VirtoolsManager::create ();
  Server server (wm, argc, argv, false); // dernier arg : autorise ou non multithread (original = true)

  server.startCorbaServer ();
  server.processRequest(true);
}
