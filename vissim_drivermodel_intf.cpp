/*
MIT License

Copyright(c) 2022 Wuping Xin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sub license, and /or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


#include <windows.h>
#include "vissim_drivermodel_intf.h"
#include "vissim_drivermodel_event.hpp"
#include "vissim_drivermodel_logic.hpp"

using namespace vissim_drivermodel;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
  switch (ul_reason_for_call) {

  case DLL_PROCESS_ATTACH:
    EventRegistry::init();
    EventRegistry::set_drivermodel(Factory::CreateDriverModel());
    break;

  case DLL_PROCESS_DETACH:
    break;

  case DLL_THREAD_ATTACH:
    break;

  case DLL_THREAD_DETACH:
    break;

  default:
    break;
  }

  return true;
}

DRIVERMODEL_API int DriverModelSetValue(int type, int index1, int index2, int int_value, double double_value, char* string_value)
{
  return (*(EventRegistry::setval_handlers[type]))({ index1, index2, -1, int_value, double_value, string_value });
}

DRIVERMODEL_API int DriverModelSetValue3(int type, int index1, int index2, int index3, int int_value, double double_value, char* string_value)
{
  return (*(EventRegistry::setval_handlers[type]))({ index1, index2, index3, int_value, double_value, string_value });
}

DRIVERMODEL_API int DriverModelGetValue(int type, int index1, int index2, int* int_value, double* double_value, char** string_value)
{
  return (*(EventRegistry::getval_handlers[type]))({ index1, index2, -1, int_value, double_value, string_value });
}

DRIVERMODEL_API int DriverModelGetValue3(int type, int index1, int index2, int index3, int* int_value, double* double_value, char** string_value)
{
  return (*(EventRegistry::getval_handlers[type]))({ index1, index2, index3, int_value, double_value, string_value });
}

DRIVERMODEL_API  int  DriverModelExecuteCommand(int number)
{
  return (*(EventRegistry::runcmd_handlers[number]))();
}
