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

#include "pyAGChannel.h"

#include <PRP/Avatar/plScalarChannel.h>
#include "PRP/pyCreatable.h"

PY_PLASMA_NEW(ScalarBlend, plScalarBlend)

PY_PLASMA_TYPE(ScalarBlend, plScalarBlend, "plScalarBlend wrapper")

PY_PLASMA_TYPE_INIT(ScalarBlend) {
    pyScalarBlend_Type.tp_new = pyScalarBlend_new;
    pyScalarBlend_Type.tp_base = &pyScalarChannel_Type;
    if (PyType_CheckAndReady(&pyScalarBlend_Type) < 0)
        return NULL;

    Py_INCREF(&pyScalarBlend_Type);
    return (PyObject*)&pyScalarBlend_Type;
}

PY_PLASMA_IFC_METHODS(ScalarBlend, plScalarBlend)
