#include "dht_sensor.hpp"

DHTSensor::DHTSensor(const int pin, const uint8_t type):
  mPin(pin),
  mType(type),
  mSensor(pin, type)
{
  // Connect pin 1 (on the left) of the sensor to +5V
  // NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
  // to 3.3V instead of 5V!
  // Connect pin 2 of the sensor to whatever your DHTPIN is
  // Connect pin 3 (on the right) of the sensor to GROUND (if your sensor has 3 pins)
  // Connect pin 4 (on the right) of the sensor to GROUND and leave the pin 3 EMPTY (if your sensor has 4 pins)
  // Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

  // Initialize DHT sensor.
  // Note that older versions of this library took an optional third parameter to
  // tweak the timings for faster processors.  This parameter is no longer needed
  // as the current DHT reading algorithm adjusts itself to work on faster procs.

  mSensor.begin();
}

String DHTSensor::readHumidity() const
{
  const float humidity = mSensor.readHumidity();
  if (isnan(humidity))
  {
    Serial.println("Failed to read from DHT sensor!");
  }

  return String(humidity);
}

String DHTSensor::readTemperature() const
{
  const float temperature = mSensor.readTemperature();
  if (isnan(temperature))
    {
      Serial.println("Failed to read from DHT sensor!");
    }

  return String(temperature);
}