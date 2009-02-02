#include <Python.h>
#include <PRP/Message/proEventData.h>
#include "pyEventData.h"

extern "C" {

static PyObject* pyCoopEventData_new(PyTypeObject* type, PyObject* args, PyObject* kwds) {
    pyCoopEventData* self = (pyCoopEventData*)type->tp_alloc(type, 0);
    if (self != NULL) {
        self->fThis = new proCoopEventData();
        self->fPyOwned = true;
    }
    return (PyObject*)self;
}

static PyObject* pyCoopEventData_Convert(PyObject*, PyObject* args) {
    pyEventData* evt;
    if (!PyArg_ParseTuple(args, "O", &evt)) {
        PyErr_SetString(PyExc_TypeError, "Convert expects a proEventData");
        return NULL;
    }
    if (!pyEventData_Check((PyObject*)evt)) {
        PyErr_SetString(PyExc_TypeError, "Convert expects a proEventData");
        return NULL;
    }
    return pyCoopEventData_FromCoopEventData(proCoopEventData::Convert(evt->fThis));
}

static PyObject* pyCoopEventData_getID(pyCoopEventData* self, void*) {
    return PyInt_FromLong(self->fThis->getID());
}

static PyObject* pyCoopEventData_getSerial(pyCoopEventData* self, void*) {
    return PyInt_FromLong(self->fThis->getSerial());
}

static int pyCoopEventData_setID(pyCoopEventData* self, PyObject* value, void*) {
    if (value == NULL || !PyInt_Check(value)) {
        PyErr_SetString(PyExc_TypeError, "id should be an int");
        return -1;
    }
    self->fThis->setID(PyInt_AsLong(value));
    return 0;
}

static int pyCoopEventData_setSerial(pyCoopEventData* self, PyObject* value, void*) {
    if (value == NULL || !PyInt_Check(value)) {
        PyErr_SetString(PyExc_TypeError, "serial should be an int");
        return -1;
    }
    self->fThis->setSerial(PyInt_AsLong(value));
    return 0;
}

static PyMethodDef pyCoopEventData_Methods[] = {
    { "Convert", (PyCFunction)pyCoopEventData_Convert, METH_VARARGS | METH_STATIC,
      "Convert a proEventData to a proCoopEventData" },
    { NULL, NULL, 0, NULL }
};

static PyGetSetDef pyCoopEventData_GetSet[] = {
    { "id", (getter)pyCoopEventData_getID, (setter)pyCoopEventData_setID, NULL, NULL },
    { "serial", (getter)pyCoopEventData_getSerial, (setter)pyCoopEventData_setSerial, NULL, NULL },
    { NULL, NULL, NULL, NULL, NULL }
};

PyTypeObject pyCoopEventData_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                  /* ob_size */
    "PyPlasma.proCoopEventData",        /* tp_name */
    sizeof(pyCoopEventData),            /* tp_basicsize */
    0,                                  /* tp_itemsize */

    NULL,                               /* tp_dealloc */
    NULL,                               /* tp_print */
    NULL,                               /* tp_getattr */
    NULL,                               /* tp_setattr */
    NULL,                               /* tp_compare */
    NULL,                               /* tp_repr */
    NULL,                               /* tp_as_number */
    NULL,                               /* tp_as_sequence */
    NULL,                               /* tp_as_mapping */
    NULL,                               /* tp_hash */
    NULL,                               /* tp_call */
    NULL,                               /* tp_str */
    NULL,                               /* tp_getattro */
    NULL,                               /* tp_setattro */
    NULL,                               /* tp_as_buffer */

    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, /* tp_flags */
    "proCoopEventData wrapper",         /* tp_doc */

    NULL,                               /* tp_traverse */
    NULL,                               /* tp_clear */
    NULL,                               /* tp_richcompare */
    0,                                  /* tp_weaklistoffset */
    NULL,                               /* tp_iter */
    NULL,                               /* tp_iternext */

    pyCoopEventData_Methods,            /* tp_methods */
    NULL,                               /* tp_members */
    pyCoopEventData_GetSet,             /* tp_getset */
    NULL,                               /* tp_base */
    NULL,                               /* tp_dict */
    NULL,                               /* tp_descr_get */
    NULL,                               /* tp_descr_set */
    0,                                  /* tp_dictoffset */

    NULL,                               /* tp_init */
    NULL,                               /* tp_alloc */
    pyCoopEventData_new,                /* tp_new */
    NULL,                               /* tp_free */
    NULL,                               /* tp_is_gc */

    NULL,                               /* tp_bases */
    NULL,                               /* tp_mro */
    NULL,                               /* tp_cache */
    NULL,                               /* tp_subclasses */
    NULL,                               /* tp_weaklist */
};

PyObject* Init_pyCoopEventData_Type() {
    pyCoopEventData_Type.tp_base = &pyEventData_Type;
    if (PyType_Ready(&pyCoopEventData_Type) < 0)
        return NULL;

    Py_INCREF(&pyCoopEventData_Type);
    return (PyObject*)&pyCoopEventData_Type;
}

int pyCoopEventData_Check(PyObject* obj) {
    if (obj->ob_type == &pyCoopEventData_Type
        || PyType_IsSubtype(obj->ob_type, &pyCoopEventData_Type))
        return 1;
    return 0;
}

PyObject* pyCoopEventData_FromCoopEventData(proCoopEventData* evt) {
    if (evt == NULL) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    pyCoopEventData* pyobj = PyObject_New(pyCoopEventData, &pyCoopEventData_Type);
    pyobj->fThis = evt;
    pyobj->fPyOwned = false;
    return (PyObject*)pyobj;
}

}