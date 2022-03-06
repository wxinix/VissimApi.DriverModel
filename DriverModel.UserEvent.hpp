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

#include "DriverModel.Event.hpp"

template<>
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_STATUS>
{
    static constexpr DriverModelSetValFunc on_setval {
        nullptr
    };

    static constexpr DriverModelGetValFunc on_getval {
        [](int index1, int index2, int index3, int* int_value, double* double_value, char** str_value) {
            *int_value = 0;
            return 1;
        }
    };
};

template<>
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_TIMESTEP>
{
    static constexpr DriverModelSetValFunc on_setval{
        [](int index1, int index2, int index3, int int_value, double double_value, char* string_value) {
            return 1;
        }
    };

    static constexpr DriverModelGetValFunc on_getval{
        nullptr
    };
};

template<>
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_TIME>
{
    static constexpr DriverModelSetValFunc on_setval{
        [](int index1, int index2, int index3, int int_value, double double_value, char* string_value) {
            return 1;
        }
    };

    static constexpr DriverModelGetValFunc on_getval{
        nullptr
    };
};

template<>
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_USE_UDA>
{
    static constexpr DriverModelSetValFunc on_setval{
        [](int index1, int index2, int index3, int int_value, double double_value, char* string_value) {
            return 0; // Does not use any UDAs. 
        }
    };

    static constexpr DriverModelGetValFunc on_getval{
        nullptr
    };
};