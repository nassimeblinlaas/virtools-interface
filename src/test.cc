//
//  basic-scene.cc
//  Test SceneViewer with C++ CORBA client interface.
//
//  Created by Joseph Mirabel in June 2015.
//  Copyright (c) 2014 LAAS-CNRS. All rights reserved.
//

#include <gepetto/virtools/corba/client.hh>

int main(int argc, const char ** argv)
{
    using namespace virtools;
    using namespace corbaServer;
    using namespace std;

    Client client (0, NULL);
    client.connect ();
	client.gui()->fonc();

    cout<< "après fonc\n";

    client.gui()->fonc();

    cout<< "après fonc\n";


    return 0;
}
