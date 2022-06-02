#include <stdio.h>
#include "D:\\python10\\include\\Python.h"
#define panic(x, msg)  \
    if (x)             \
    {                  \
        printf(msg);   \
        Py_Finalize(); \
    }

int main()
{
    PyObject *pModule, *pFunc, *pArgs;
    Py_Initialize();
    panic(!Py_IsInitialized(), "fail to initialize.\n");
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./')");
    pModule = PyImport_ImportModule("callpy");
    panic(!pModule, "fail to import file.\n");
    pFunc = PyObject_GetAttrString(pModule, "number");
    panic(!pFunc, "fail to import func.\n");
    pArgs = PyTuple_New(1);
    PyTuple_SetItem(pArgs, 0, PyLong_FromLong(5));
    PyObject_CallObject(pFunc, pArgs);
    Py_Finalize();
    printf("success");
    return 0;
}