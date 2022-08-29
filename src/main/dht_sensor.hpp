#pragma once

#include <Arduino.h>
#include <DHT.h>

class DHTSensor
{
  public:
    explicit DHTSensor(const int pin, const uint8_t type);
    DHTSensor(const DHTSensor&) = delete;
    DHTSensor(DHTSensor&&) = delete;
    ~DHTSensor() = default;

    DHTSensor& operator=(const DHTSensor&) = delete;
    DHTSensor& operator=(DHTSensor&&) = delete;

    String readHumidity() const;
    String readTemperature() const;

  private:
    const int mPin;
    const uint8_t mType;
    DHT mSensor;
};