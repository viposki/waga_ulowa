#pragma once

#include "sim_types.hpp"

#include <Arduino.h>
#include <Sim800l.h>
#include <SoftwareSerial.h>

enum class SMS_STATUS : bool
{
  FAILURE,
  SUCCESS
};

// TODO: Think about config regarding SIM module.
//       config = { "sms": { "read": boolean, "write": boolean }} etc.
//       Not necessary in the JSON format.

class Sim800
{
public:
  Sim800();
  Sim800(const Sim800&) = delete;
  Sim800(Sim800&&) = delete;

  ~Sim800() = default;

  Sim800& operator=(const Sim800&) = delete;
  Sim800& operator=(Sim800&&) = delete;

  // TODO: After success tests change to CellNumber type.
  void sendSMS(const String& cellNumber, const String& text) const;

private:
  void getRTCTime() const;

  Sim800l mRawSim800;
  Time mRTC;
};