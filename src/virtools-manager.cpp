// Copyright (c) 2015, Joseph Mirabel
// Authors: Joseph Mirabel (joseph.mirabel@laas.fr)
//
// This file is part of gepetto-viewer.
// gepetto-viewer is free software: you can redistribute it
// and/or modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation, either version
// 3 of the License, or (at your option) any later version.
//
// gepetto-viewer is distributed in the hope that it will be
// useful, but WITHOUT ANY WARRANTY; without even the implied warranty
// of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Lesser Public License for more details.  You should have
// received a copy of the GNU Lesser General Public License along with
// gepetto-viewer. If not, see <http://www.gnu.org/licenses/>.

#include "gepetto/virtools/corba/virtools-manager.h"
#include <boost/thread.hpp>
#include <iostream>

#include "gepetto/virtools/corba/virtools-interface.hh"

namespace virtools {
    VirtoolsManager::VirtoolsManager () : virtools_(new Virtools)
    {
	std::cout << "constructeur de virtoolsmanager\n";
    }

	void VirtoolsManager::fonc(){
		std::cout << "virtools-manager.cpp:fonc()\n";
        this->virtools_->fonc();
	}

	VirtoolsManagerPtr_t VirtoolsManager::create(){
		VirtoolsManagerPtr_t ptr (new VirtoolsManager());
		return ptr;
	}

} // namespace graphics
