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

#include <memory>

#include "meta_enum/include/meta_enum.hpp"
#include "vissim_drivermodel_base.hpp"

namespace vissim_drivermodel {

// All enumerator in upper case consistent with Vissim
meta_enum_class(
  DataKind,
  int,
  Timestep = 102,
  Time = 103,
  ParameterFile = 104,
  Status = 105,
  StatusDetails = 106,
  UseUDA = 107,
  WantsAllSignals = 108,
  MaxNumIndices = 109,
  VehID = 201,
  VehLane = 202,
  VehOdometer = 203,
  VehLaneAngle = 204,
  VehLateralPos = 205,
  VehVelocity = 206,
  VehAccel = 207,
  VehLen = 208,
  VehWidth = 209,
  VehWeight = 210,
  VehMaxAccel = 211,
  VehTurningIndicator = 212,
  VehCategory = 213,
  VehPreferredRelLane = 214,
  VehUsePreferredLane = 215,
  VehDesiredVelocity = 216,
  VehCoord_X = 217,
  VehCoord_Y = 218,
  VehRearCoord_X = 808,
  VehRearCoord_Y = 809,
  VehType = 219,
  VehColor = 220,
  VehCurlink = 221,
  VehNextLinks = 222,
  VehActiveLaneChange = 223,
  VehRelTargetLane = 224,
  VehIntacState = 225,
  VehIntacTargetType = 226,
  VehIntacTargetID = 227,
  VehIntacHeadway = 228,
  VehCoord_Z = 229,
  VehRearCoord_Z = 230,
  VehUDA = 231,
  NVehID = 301,
  NVehLaneAngle = 302,
  NVehLateralPos = 303,
  NVehDistance = 304,
  NVehRelVelocity = 305,
  NVehAccel = 306,
  NVehLen = 307,
  NVehWidth = 308,
  NVehWeight = 309,
  NVehTurningIndicator = 310,
  NVehCategory = 311,
  NVehLaneChange = 312,
  NVehType = 313,
  NVehUDA = 314,
  NVehCoord_X = 315,
  NVehCoord_Y = 316,
  NVehCoord_Z = 317,
  NVehRearCoord_X = 318,
  NVehRearCoord_Y = 319,
  NVehRearCoord_Z = 320,
  NumLanes = 401,
  LaneWidth = 501,
  LaneEndDistance = 502,
  CurrentLanePoly_N = 551,
  CurrentLanePoly_X = 552,
  CurrentLanePoly_Y = 553,
  CurrentLanePoly_Z = 554,
  Radius = 601,
  MinRadius = 602,
  DistToMinRadius = 603,
  Slope = 604,
  SlopeAhead = 605,
  SignalDistance = 701,
  SignalState = 702,
  SignalStateStart = 703,
  SpeedLimitDistance = 704,
  SpeedLimitValue = 705,
  PrioRuleDistance = 706,
  PrioRuleState = 707,
  RouteSignalDistance = 708,
  RouteSignalState = 709,
  RouteSignalSwitch = 710,
  RouteSignalCycle = 711,
  ConflAreaCount = 712,
  ConflAreaType = 713,
  ConflAreaYield = 714,
  ConflAreaDistance = 715,
  ConflAreaLength = 716,
  ConflAreaVehicles = 717,
  ConflAreaTimeEnter = 718,
  ConflAreaTimeIn = 719,
  ConflAreaTimeExit = 720,
  WantSuggestion = 801,
  DesiredAccel = 802,
  DesiredLaneAngle = 803,
  ActiveLaneChange = 804,
  RelTargetLane = 805,
  SimpleLaneChange = 806,
  UseInternalModel = 807,
  WantAllNVehs = 810,
  AllowMultithreading = 811
);

meta_enum_class(
  CommandKind,
  int,
  // All enumerator in upper case consistent with Vissim
  Init = 0,
  CreateDriver = 1,
  KillDriver = 2,
  MoveDriver = 3
);

struct Functor {
public:
  void set_drivermodel(std::shared_ptr<DriverModel> a_model) {
    m_drivermodel = a_model;
  };

  std::shared_ptr<DriverModel> drivermodel() {
    return m_drivermodel;
  };

private:
  std::shared_ptr<DriverModel> m_drivermodel{ nullptr };
};

struct GetvalFunctor : public Functor {
  virtual int operator()(int index1, int index2, int index3, int* int_value, double* double_value, char** string_value) {
    return 0;
  }
};

struct SetvalFunctor : public Functor {
  virtual int operator()(int index1, int index2, int index3, int int_value, double double_value, char* string_value) {
    return 0;
  }
};

struct RuncmdFunctor : public Functor {
  virtual int operator()() {
    return 1;
  }
};

template <DataKind kind>
struct GetvalEventHandler : GetvalFunctor {};

template <DataKind kind>
struct SetvalEventHandler : SetvalFunctor {};

template <CommandKind kind>
struct RuncmdEventHandler : RuncmdFunctor {};

struct EventRegistry {
  using SetvalFunctors = std::array<std::unique_ptr<SetvalFunctor>, 0x0400>;
  using GetvalFunctors = std::array<std::unique_ptr<GetvalFunctor>, 0x0400>;
  using RuncmdFunctors = std::array<std::unique_ptr<RuncmdFunctor>, 0x0008>;

  static void init() {
    constexpr auto num_data_event = DataKind_meta.members.size();
    init_setval_handlers<num_data_event>();
    init_getval_handlers<num_data_event>();

    constexpr auto num_cmd_event = CommandKind_meta.members.size();
    init_runcmd_handlers<num_cmd_event>();
  }

  static void set_drivermodel(std::shared_ptr<DriverModel> a_model) {
    for (const auto& setval_handler : setval_handlers) {
      if (setval_handler) {
        setval_handler->set_drivermodel(a_model);
      }
    }

    for (const auto& getval_handler : getval_handlers) {
      if (getval_handler) {
        getval_handler->set_drivermodel(a_model);
      }
    }

    for (const auto& runcmd_handler : runcmd_handlers) {
      if (runcmd_handler) {
        runcmd_handler->set_drivermodel(a_model);
      }
    }
  }

  static GetvalFunctors getval_handlers;
  static RuncmdFunctors runcmd_handlers;
  static SetvalFunctors setval_handlers;

private:
  template <int N, int I = 0>
  static void init_setval_handlers() {
    if constexpr (I < N) {
      constexpr auto kind = DataKind_meta.members[I].value;
      constexpr auto index = static_cast<int>(kind);
      setval_handlers[index] = std::make_unique<SetvalEventHandler<kind>>();
      init_setval_handlers<I + 1, N>();
    }
  }

  template <int N, int I = 0>
  static void init_getval_handlers() {
    if constexpr (I < N) {
      constexpr auto kind = DataKind_meta.members[I].value;
      constexpr auto index = static_cast<int>(kind);
      getval_handlers[index] = std::make_unique<GetvalEventHandler<kind>>();
      init_getval_handlers<I + 1, N>();
    }
  }

  template <int N, int I = 0>
  static void init_runcmd_handlers() {
    if constexpr (I < N) {
      constexpr auto kind = CommandKind_meta.members.at(I).value;
      constexpr auto index = static_cast<int>(kind);
      runcmd_handlers[index] = std::make_unique<RuncmdEventHandler<kind>>();
      init_runcmd_handlers<I + 1, N>();
    }
  }
};

EventRegistry::GetvalFunctors EventRegistry::getval_handlers;
EventRegistry::RuncmdFunctors EventRegistry::runcmd_handlers;
EventRegistry::SetvalFunctors EventRegistry::setval_handlers;

// ----------------------------------------------------------------
// Specialization of event handers to overwrite the default ones.
// ----------------------------------------------------------------
template <>
struct SetvalEventHandler<DataKind::Status> : SetvalFunctor {
  int operator()(int index1, int index2, int index3, int int_value, double double_value, char* string_value) override {
    return 1;
  }
};

template <>
struct SetvalEventHandler<DataKind::Timestep> : SetvalFunctor {
  int operator()(int index1, int index2, int index3, int int_value, double double_value, char* string_value) override {
    return 1;
  }
};

template <>
struct SetvalEventHandler<DataKind::Time> : SetvalFunctor {
  int operator()(int index1, int index2, int index3, int int_value, double double_value, char* string_value) override {
    return 1;
  }
};

//-----------------------------------------------------------------

}  // namespace vissim_drivermodel
#endif
