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

#ifndef _DRIVERMODEL_EVENT_H
#define _DRIVERMODEL_EVENT_H

#include <functional>
#include "DriverModel.Meta.hpp"

meta_enum_class(DriverModelDataEventKind, int,
     DRIVER_DATA_TIMESTEP = 102,
     DRIVER_DATA_TIME = 103,
     DRIVER_DATA_PARAMETERFILE = 104,
     DRIVER_DATA_STATUS = 105,
     DRIVER_DATA_STATUS_DETAILS = 106,
     DRIVER_DATA_USE_UDA = 107,
     DRIVER_DATA_WANTS_ALL_SIGNALS = 108,
     DRIVER_DATA_MAX_NUM_INDICES = 109,
     DRIVER_DATA_VEH_ID = 201,
     DRIVER_DATA_VEH_LANE = 202,
     DRIVER_DATA_VEH_ODOMETER = 203,
     DRIVER_DATA_VEH_LANE_ANGLE = 204,
     DRIVER_DATA_VEH_LATERAL_POSITION = 205,
     DRIVER_DATA_VEH_VELOCITY = 206,
     DRIVER_DATA_VEH_ACCELERATION = 207,
     DRIVER_DATA_VEH_LENGTH = 208,
     DRIVER_DATA_VEH_WIDTH = 209,
     DRIVER_DATA_VEH_WEIGHT = 210,
     DRIVER_DATA_VEH_MAX_ACCELERATION = 211,
     DRIVER_DATA_VEH_TURNING_INDICATOR = 212,
     DRIVER_DATA_VEH_CATEGORY = 213,
     DRIVER_DATA_VEH_PREFERRED_REL_LANE = 214,
     DRIVER_DATA_VEH_USE_PREFERRED_LANE = 215,
     DRIVER_DATA_VEH_DESIRED_VELOCITY = 216,
     DRIVER_DATA_VEH_X_COORDINATE = 217,
     DRIVER_DATA_VEH_Y_COORDINATE = 218,
     DRIVER_DATA_VEH_REAR_X_COORDINATE = 808,
     DRIVER_DATA_VEH_REAR_Y_COORDINATE = 809,
     DRIVER_DATA_VEH_TYPE = 219,
     DRIVER_DATA_VEH_COLOR = 220,
     DRIVER_DATA_VEH_CURRENT_LINK = 221,
     DRIVER_DATA_VEH_NEXT_LINKS = 222,
     DRIVER_DATA_VEH_ACTIVE_LANE_CHANGE = 223,
     DRIVER_DATA_VEH_REL_TARGET_LANE = 224,
     DRIVER_DATA_VEH_INTAC_STATE = 225,
     DRIVER_DATA_VEH_INTAC_TARGET_TYPE = 226,
     DRIVER_DATA_VEH_INTAC_TARGET_ID = 227,
     DRIVER_DATA_VEH_INTAC_HEADWAY = 228,
     DRIVER_DATA_VEH_Z_COORDINATE = 229,
     DRIVER_DATA_VEH_REAR_Z_COORDINATE = 230,
     DRIVER_DATA_VEH_UDA = 231,
     DRIVER_DATA_NVEH_ID = 301,
     DRIVER_DATA_NVEH_LANE_ANGLE = 302,
     DRIVER_DATA_NVEH_LATERAL_POSITION = 303,
     DRIVER_DATA_NVEH_DISTANCE = 304,
     DRIVER_DATA_NVEH_REL_VELOCITY = 305,
     DRIVER_DATA_NVEH_ACCELERATION = 306,
     DRIVER_DATA_NVEH_LENGTH = 307,
     DRIVER_DATA_NVEH_WIDTH = 308,
     DRIVER_DATA_NVEH_WEIGHT = 309,
     DRIVER_DATA_NVEH_TURNING_INDICATOR = 310,
     DRIVER_DATA_NVEH_CATEGORY = 311,
     DRIVER_DATA_NVEH_LANE_CHANGE = 312,
     DRIVER_DATA_NVEH_TYPE = 313,
     DRIVER_DATA_NVEH_UDA = 314,
     DRIVER_DATA_NVEH_X_COORDINATE = 315,
     DRIVER_DATA_NVEH_Y_COORDINATE = 316,
     DRIVER_DATA_NVEH_Z_COORDINATE = 317,
     DRIVER_DATA_NVEH_REAR_X_COORDINATE = 318,
     DRIVER_DATA_NVEH_REAR_Y_COORDINATE = 319,
     DRIVER_DATA_NVEH_REAR_Z_COORDINATE = 320,
     DRIVER_DATA_NO_OF_LANES = 401,
     DRIVER_DATA_LANE_WIDTH = 501,
     DRIVER_DATA_LANE_END_DISTANCE = 502,
     DRIVER_DATA_CURRENT_LANE_POLY_N = 551,
     DRIVER_DATA_CURRENT_LANE_POLY_X = 552,
     DRIVER_DATA_CURRENT_LANE_POLY_Y = 553,
     DRIVER_DATA_CURRENT_LANE_POLY_Z = 554,
     DRIVER_DATA_RADIUS = 601,
     DRIVER_DATA_MIN_RADIUS = 602,
     DRIVER_DATA_DIST_TO_MIN_RADIUS = 603,
     DRIVER_DATA_SLOPE = 604,
     DRIVER_DATA_SLOPE_AHEAD = 605,
     DRIVER_DATA_SIGNAL_DISTANCE = 701,
     DRIVER_DATA_SIGNAL_STATE = 702,
     DRIVER_DATA_SIGNAL_STATE_START = 703,
     DRIVER_DATA_SPEED_LIMIT_DISTANCE = 704,
     DRIVER_DATA_SPEED_LIMIT_VALUE = 705,
     DRIVER_DATA_PRIO_RULE_DISTANCE = 706,
     DRIVER_DATA_PRIO_RULE_STATE = 707,
     DRIVER_DATA_ROUTE_SIGNAL_DISTANCE = 708,
     DRIVER_DATA_ROUTE_SIGNAL_STATE = 709,
     DRIVER_DATA_ROUTE_SIGNAL_SWITCH = 710,
     DRIVER_DATA_ROUTE_SIGNAL_CYCLE = 711,
     DRIVER_DATA_CONFL_AREAS_COUNT = 712,
     DRIVER_DATA_CONFL_AREA_TYPE = 713,
     DRIVER_DATA_CONFL_AREA_YIELD = 714,
     DRIVER_DATA_CONFL_AREA_DISTANCE = 715,
     DRIVER_DATA_CONFL_AREA_LENGTH = 716,
     DRIVER_DATA_CONFL_AREA_VEHICLES = 717,
     DRIVER_DATA_CONFL_AREA_TIME_ENTER = 718,
     DRIVER_DATA_CONFL_AREA_TIME_IN = 719,
     DRIVER_DATA_CONFL_AREA_TIME_EXIT = 720,
     DRIVER_DATA_WANTS_SUGGESTION = 801,
     DRIVER_DATA_DESIRED_ACCELERATION = 802,
     DRIVER_DATA_DESIRED_LANE_ANGLE = 803,
     DRIVER_DATA_ACTIVE_LANE_CHANGE = 804,
     DRIVER_DATA_REL_TARGET_LANE = 805,
     DRIVER_DATA_SIMPLE_LANECHANGE = 806,
     DRIVER_DATA_USE_INTERNAL_MODEL = 807,
     DRIVER_DATA_WANTS_ALL_NVEHS = 810,
     DRIVER_DATA_ALLOW_MULTITHREADING = 811
     );

meta_enum_class(DriverModelCommandEventKind, int,
    DRIVER_COMMAND_INIT = 0,
    DRIVER_COMMAND_CREATE_DRIVER = 1,
    DRIVER_COMMAND_KILL_DRIVER = 2,
    DRIVER_COMMAND_MOVE_DRIVER = 3
    );

typedef int (*DriverModelSetValFunc)(int, int, int, int,  double,  char*);
typedef int (*DriverModelGetValFunc)(int, int, int, int*, double*, char**);
typedef int (*DriverModelExeCmdFunc)();

template<DriverModelDataEventKind kind>
struct DriverModelDataEventSink
{
    static constexpr DriverModelSetValFunc on_setval { nullptr };
    static constexpr DriverModelGetValFunc on_getval { nullptr };
};

template<DriverModelCommandEventKind kind>
struct DriverModelCommandEventSink
{
    static constexpr DriverModelExeCmdFunc on_execmd { nullptr };
};

struct DriverModelEventRegistry
{
    static constexpr size_t capacity{ 1024 }; // 1024 function pointers, for better cache line alignment.

    static std::array<DriverModelSetValFunc, DriverModelEventRegistry::capacity> setval_event_map;
    static std::array<DriverModelGetValFunc, DriverModelEventRegistry::capacity> getval_event_map;
    static std::array<DriverModelExeCmdFunc, DriverModelEventRegistry::capacity> execmd_event_map;

    template<int N = 0>
    static void init_data_event_map()
    {
        if constexpr (N < DriverModelDataEventKind_meta.members.size()) {
            setval_event_map[static_cast<int>(DriverModelDataEventKind_meta.members.at(N).value)] =
                DriverModelDataEventSink<DriverModelDataEventKind_meta.members.at(N).value>::on_setval;
            
            getval_event_map[static_cast<int>(DriverModelDataEventKind_meta.members.at(N).value)] =
                DriverModelDataEventSink<DriverModelDataEventKind_meta.members.at(N).value>::on_getval;
            
            init_data_event_map<N+1>();
        }
    }
    
    template<int N = 0>
    static void init_command_event_map()
    {
        if constexpr (N < DriverModelCommandEventKind_meta.members.size()) {
            execmd_event_map[static_cast<int>(DriverModelCommandEventKind_meta.members.at(N).value)] =
                DriverModelCommandEventSink<DriverModelCommandEventKind_meta.members.at(N).value>::on_execmd;
			
            init_command_event_map<N+1>();
        }
    }
};

std::array<DriverModelSetValFunc, DriverModelEventRegistry::capacity> DriverModelEventRegistry::setval_event_map{};
std::array<DriverModelGetValFunc, DriverModelEventRegistry::capacity> DriverModelEventRegistry::getval_event_map{};
std::array<DriverModelExeCmdFunc, DriverModelEventRegistry::capacity> DriverModelEventRegistry::execmd_event_map{};

#include "DriverModel.UserEvent.hpp"

#endif

