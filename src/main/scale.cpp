#include "scale.hpp"

Scale::Scale(float calibrationValue, int readingTimes):
  mScaleSensor(),
  mCalibrationValue(calibrationValue),
  mReadingTimes(readingTimes)
{
  Serial.print("Scale!");
}

void Scale::init(unsigned char dout, unsigned char sck)
{
  mScaleSensor.begin(dout, sck);
  mScaleSensor.set_scale();
  reset();
  calibrate(mCalibrationValue);

  Serial.print("Begin scale!");
}

void Scale::calibrate(float value)
{
  mScaleSensor.set_scale(value);
}

void Scale::reset()
{
  mScaleSensor.tare();
}

bool Scale::isReady()
{
  return mScaleSensor.is_ready();
}

void Scale::powerOn()
{
  mScaleSensor.power_up();
}

void Scale::powerOff()
{
  mScaleSensor.power_down();
}

void Scale::setReadingTimes(int readingTimes)
{
  if (mReadingTimes != readingTimes)
  {
    mReadingTimes = readingTimes;
  }
}

float Scale::getUnits()
{
  // Wartość zwracana jest średnią wartością z mReadingTimes odczytów.
  return mScaleSensor.get_units(mReadingTimes);
}