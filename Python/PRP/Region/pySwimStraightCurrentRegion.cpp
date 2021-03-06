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

#include "PRP/KeyedObject/pyKey.h"
#include <PRP/Region/plSwimRegion.h>

PY_PLASMA_NEW(SwimStraightCurrentRegion, plSwimStraightCurrentRegion)

PY_PROPERTY(float, SwimStraightCurrentRegion, nearDist, getNearDist, setNearDist)
PY_PROPERTY(float, SwimStraightCurrentRegion, farDist, getFarDist, setFarDist)
PY_PROPERTY(float, SwimStraightCurrentRegion, nearVel, getNearVel, setNearVel)
PY_PROPERTY(float, SwimStraightCurrentRegion, farVel, getFarVel, setFarVel)
PY_PROPERTY(plKey, SwimStraightCurrentRegion, currentObj, getCurrentObj, setCurrentObj)

PyGetSetDef pySwimStraightCurrentRegion_GetSet[] = {
    pySwimStraightCurrentRegion_nearDist_getset,
    pySwimStraightCurrentRegion_farDist_getset,
    pySwimStraightCurrentRegion_nearVel_getset,
    pySwimStraightCurrentRegion_farVel_getset,
    pySwimStraightCurrentRegion_currentObj_getset,
    PY_GETSET_TERMINATOR
};

PY_PLASMA_TYPE(SwimStraightCurrentRegion, plSwimStraightCurrentRegion,
               "plSwimStraightCurrentRegion wrapper")

PY_PLASMA_TYPE_INIT(SwimStraightCurrentRegion) {
    pySwimStraightCurrentRegion_Type.tp_new = pySwimStraightCurrentRegion_new;
    pySwimStraightCurrentRegion_Type.tp_getset = pySwimStraightCurrentRegion_GetSet;
    pySwimStraightCurrentRegion_Type.tp_base = &pySwimRegionInterface_Type;
    if (PyType_CheckAndReady(&pySwimStraightCurrentRegion_Type) < 0)
        return NULL;

    Py_INCREF(&pySwimStraightCurrentRegion_Type);
    return (PyObject*)&pySwimStraightCurrentRegion_Type;
}

PY_PLASMA_IFC_METHODS(SwimStraightCurrentRegion, plSwimStraightCurrentRegion);
