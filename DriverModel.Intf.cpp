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

#ifndef _CONSOLE
#include <windows.h>
#endif

#include "DriverModel.Intf.h"
#include "DriverModel.Event.hpp"
#include "DriverModel.Meta.hpp"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call) {

	case DLL_PROCESS_ATTACH:
		DriverModelEventRegistry::init_command_event_map();
		DriverModelEventRegistry::init_data_event_map();
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

DRIVERMODEL_API int DriverModelSetValue(int type, int index1, int index2,
	int int_value, double double_value, char* string_value)
{
	auto kind = static_cast<DriverModelDataEventKind>(type);
	DriverModelSetValueFunc set_value_func = DriverModelEventRegistry::set_value_event_map.get(kind);
	if (set_value_func) {
		return set_value_func(index1, index2, -1, int_value, double_value, string_value);
	}
	else {
		return 0;
	};
}

DRIVERMODEL_API int DriverModelSetValue3(int type, int index1, int index2,
	int index3, int int_value, double double_value, char* string_value)
{
	auto kind = static_cast<DriverModelDataEventKind>(type);
	DriverModelSetValueFunc set_value_func = DriverModelEventRegistry::set_value_event_map.get(kind);
	if (set_value_func) {
		return set_value_func(index1, index2, index3, int_value, double_value, string_value);
	}
	else {
		return 0;
	};
}

DRIVERMODEL_API int DriverModelGetValue(int type, int index1, int index2,
	int* int_value, double* double_value, char** string_value)
{
	auto kind = static_cast<DriverModelDataEventKind>(type);
	DriverModelGetValueFunc get_value_func = DriverModelEventRegistry::get_value_event_map.get(kind);
	if (get_value_func) {
		return get_value_func(index1, index2, -1, int_value, double_value, string_value);
	}
	else {
		return 0;
	};
}

DRIVERMODEL_API int DriverModelGetValue3(int type, int index1, int index2,
	int index3, int* int_value, double* double_value, char** string_value)
{
	auto kind = static_cast<DriverModelDataEventKind>(type);
	DriverModelGetValueFunc get_value_func = DriverModelEventRegistry::get_value_event_map.get(kind);
	if (get_value_func) {
		return get_value_func(index1, index2, index3, int_value, double_value, string_value);
	}
	else {
		return 0;
	};
}

DRIVERMODEL_API  int  DriverModelExecuteCommand(int number)
{
	auto kind = static_cast<DriverModelCommandEventKind>(number);
	DriverModelExecuteCommandFunc command_func = DriverModelEventRegistry::command_event_map.get(kind);
	if (command_func) {
		return command_func();
	}
	else {
		return 0;
	};
}
