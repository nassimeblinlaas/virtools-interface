// Copyright (c) 2014, LAAS-CNRS
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

#ifndef SCENEVIEWER_WINDOWMANAGERS_HH
#define SCENEVIEWER_WINDOWMANAGERS_HH

#include <gepetto/virtools/virtools.hh>
#include "gepetto/virtools/corba/virtools-interface.hh"

namespace virtools {


    DEF_CLASS_SMART_PTR(VirtoolsManager)
    //DEF_CLASS_SMART_PTR(x)

    class VirtoolsManager
    {
        public:

        private:
		VirtoolsPtr_t virtools_;
        protected:
            /**
              \brief Default constructor
              */
            VirtoolsManager ();

        public:
            static VirtoolsManagerPtr_t create ();

            virtual void fonc();
    };
} /* namespace graphics */

#endif /* SCENEVIEWER_WINDOWMANAGERS_HH */
