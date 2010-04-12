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

#ifndef _PYSPAWNMODIFIER_H
#define _PYSPAWNMODIFIER_H

extern "C" {

typedef struct {
    PyObject_HEAD
    class plSpawnModifier* fThis;
    bool fPyOwned;
} pySpawnModifier;

extern PyTypeObject pySpawnModifier_Type;
PyObject* Init_pySpawnModifier_Type();
int pySpawnModifier_Check(PyObject* obj);
PyObject* pySpawnModifier_FromSpawnModifier(class plSpawnModifier* mod);

}

#endif
