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
    static constexpr DriverModelSetValFunc on_setval {
        [](int index1, int index2, int index3, int int_value, double double_value, char* string_value) {
            return 1;
        }
    };

    static constexpr DriverModelGetValFunc on_getval {
        nullptr
    };
};

template<>
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_TIME>
{
    static constexpr DriverModelSetValFunc on_setval {
        [](int index1, int index2, int index3, int int_value, double double_value, char* string_value) {
            return 1;
        }
    };

    static constexpr DriverModelGetValFunc on_getval {
        nullptr
    };
};

template<>
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_USE_UDA>
{
    static constexpr DriverModelSetValFunc on_setval {
        [](int index1, int index2, int index3, int int_value, double double_value, char* string_value) {
            return 0; // Does not use any UDAs. 
        }
    };

    static constexpr DriverModelGetValFunc on_getval{
        nullptr
    };
};

template<>
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_VEH_ID>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_VEH_LANE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_VEH_ODOMETER>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_VEH_LANE_ANGLE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_VEH_LATERAL_POSITION>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_VEH_VELOCITY>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_VEH_ACCELERATION>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_VEH_LENGTH>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_VEH_WIDTH>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_VEH_MAX_ACCELERATION>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_VEH_TURNING_INDICATOR>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_VEH_CATEGORY>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_VEH_PREFERRED_REL_LANE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_VEH_USE_PREFERRED_LANE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_VEH_DESIRED_VELOCITY>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_VEH_X_COORDINATE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_VEH_Y_COORDINATE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_VEH_Z_COORDINATE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_VEH_TYPE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_VEH_COLOR>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_VEH_CURRENT_LINK>
{
    static constexpr DriverModelSetValFunc on_setval{
        [](int index1, int index2, int index3, int int_value, double double_value, char* string_value) {
            return 0; // To avoid getting sent lots of DRIVER_DATA_VEH_NEXT_LINKS messages.
        }
    };

    static constexpr DriverModelGetValFunc on_getval{
        nullptr
    };
};

template<>
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_VEH_NEXT_LINKS>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_VEH_ACTIVE_LANE_CHANGE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_VEH_REL_TARGET_LANE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_VEH_INTAC_STATE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_VEH_INTAC_TARGET_TYPE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_VEH_INTAC_TARGET_ID>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_VEH_INTAC_HEADWAY>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_VEH_UDA>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_NVEH_ID>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_NVEH_LANE_ANGLE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_NVEH_LATERAL_POSITION>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_NVEH_DISTANCE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_NVEH_REL_VELOCITY>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_NVEH_ACCELERATION>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_NVEH_LENGTH>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_NVEH_WIDTH>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_NVEH_WEIGHT>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_NVEH_TURNING_INDICATOR>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_NVEH_CATEGORY>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_NVEH_LANE_CHANGE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_NVEH_TYPE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_NVEH_UDA>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_NVEH_X_COORDINATE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_NVEH_Y_COORDINATE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_NVEH_Z_COORDINATE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_NVEH_REAR_X_COORDINATE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_NVEH_REAR_Y_COORDINATE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_NVEH_REAR_Z_COORDINATE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_NO_OF_LANES>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_LANE_WIDTH>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_LANE_END_DISTANCE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_CURRENT_LANE_POLY_N>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_CURRENT_LANE_POLY_X>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_CURRENT_LANE_POLY_Y>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_CURRENT_LANE_POLY_Z>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_RADIUS>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_MIN_RADIUS>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_DIST_TO_MIN_RADIUS>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_SLOPE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_SLOPE_AHEAD>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_SIGNAL_DISTANCE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_SIGNAL_STATE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_SIGNAL_STATE_START>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_SPEED_LIMIT_DISTANCE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_SPEED_LIMIT_VALUE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_PRIO_RULE_DISTANCE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_PRIO_RULE_STATE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_ROUTE_SIGNAL_CYCLE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_ROUTE_SIGNAL_DISTANCE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_ROUTE_SIGNAL_STATE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_CONFL_AREAS_COUNT>
{
    static constexpr DriverModelSetValFunc on_setval{
        [](int index1, int index2, int index3, int int_value, double double_value, char* string_value) {
            return 0;
        }
    };

    static constexpr DriverModelGetValFunc on_getval{
        nullptr
    };
};

template<>
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_CONFL_AREA_TYPE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_CONFL_AREA_YIELD>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_CONFL_AREA_DISTANCE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_CONFL_AREA_LENGTH>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_CONFL_AREA_VEHICLES>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_CONFL_AREA_TIME_ENTER>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_CONFL_AREA_TIME_IN>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_CONFL_AREA_TIME_EXIT>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_DESIRED_ACCELERATION>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_DESIRED_LANE_ANGLE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_ACTIVE_LANE_CHANGE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_REL_TARGET_LANE>
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
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_ROUTE_SIGNAL_SWITCH>
{
    static constexpr DriverModelSetValFunc on_setval{
        [](int index1, int index2, int index3, int int_value, double double_value, char* string_value) {
            return 0;
        }
    };

    static constexpr DriverModelGetValFunc on_getval{
        nullptr
    };
};

template<>
struct DriverModelDataEventSink<DriverModelDataEventKind::DRIVER_DATA_WANTS_SUGGESTION>
{
    static constexpr DriverModelSetValFunc on_setval{
        nullptr
    };

    static constexpr DriverModelGetValFunc on_getval{
        [](int index1, int index2, int index3, int* int_value, double* double_value, char** string_value) {
            *int_value = 1;
            return 1;
        }
    };
};













