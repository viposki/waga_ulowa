#pragma once

#include <HX711.h>

constexpr int DEFAULT_TIMES = 5;

class Scale
{
public:
  Scale(float calibrationValue, int readingTimes = DEFAULT_TIMES);
  Scale(const Scale&) = delete;
  Scale(Scale&&) = delete;

  ~Scale() = default;

  Scale& operator=(const Scale&) = delete;
  Scale& operator=(Scale&&) = delete;

  void init(unsigned char dout, unsigned char sck);

  void calibrate(float value);
  void reset();
  bool isReady();
  void powerOn();
  void powerOff();

  void setReadingTimes(int readingTimes);
  float getUnits();

private:
  HX711 mScaleSensor;
  float mCalibrationValue;
  int mReadingTimes;
};