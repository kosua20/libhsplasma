/* This file is part of HSPlasma.
*
* HSPlasma is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* HSPlasma is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with HSPlasma.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "pySwimRegion.h"

#include <PRP/Region/plSwimRegion.h>
#include "PRP/Object/pyObjInterface.h"

extern "C" {

PY_PLASMA_NEW(SwimRegionInterface, plSwimRegionInterface)

PY_PROPERTY(float, SwimRegionInterface, downBuoyancy, getDownBuoyancy, setDownBuoyancy)
PY_PROPERTY(float, SwimRegionInterface, upBuoyancy, getUpBuoyancy, setUpBuoyancy)
PY_PROPERTY(float, SwimRegionInterface, maxUpwardVel, getMaxUpwardVel, setMaxUpwardVel)

PyGetSetDef pySwimRegionInterface_GetSet[] = {
    pySwimRegionInterface_downBuoyancy_getset,
    pySwimRegionInterface_upBuoyancy_getset,
    pySwimRegionInterface_maxUpwardVel_getset,
    PY_GETSET_TERMINATOR
};

PY_PLASMA_TYPE(SwimRegionInterface, plSwimRegionInterface,
               "plSwimRegionInterface wrapper")

PY_PLASMA_TYPE_INIT(SwimRegionInterface) {
    pySwimRegionInterface_Type.tp_new = pySwimRegionInterface_new;
    pySwimRegionInterface_Type.tp_getset = pySwimRegionInterface_GetSet;
    pySwimRegionInterface_Type.tp_base = &pyObjInterface_Type;
    if (PyType_CheckAndReady(&pySwimRegionInterface_Type) < 0)
        return NULL;

    PY_TYPE_ADD_CONST(SwimRegionInterface, "kDisable", plSwimRegionInterface::kDisable);

    Py_INCREF(&pySwimRegionInterface_Type);
    return (PyObject*)&pySwimRegionInterface_Type;
}

PY_PLASMA_IFC_METHODS(SwimRegionInterface, plSwimRegionInterface);

}