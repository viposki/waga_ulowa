#include "dht_sensor.hpp"
#include "dht_config.hpp"
#include "scale.hpp"
#include "sim800.hpp"
#include "screen.hpp"

#include <Wire.h>

// HX711 circuit wiring
constexpr int LOADCELL_DOUT_PIN = 2;
constexpr int LOADCELL_SCK_PIN = 3;
constexpr int CALIBRATION_VALUE = -5450;

Screen *screen = nullptr;
Scale scale(CALIBRATION_VALUE);
// DHTSensor *insideSensor = nullptr;
// DHTSensor *outsideSensor = nullptr;

Sim800 simCard;

void setup()
{
  Serial.begin(9600);
  screen = new Screen(0x27, 16, 2);

  screen->showText("Start!");

  scale.init(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

  // insideSensor = new DHTSensor(INSIDE_DHT_SENSOR_PIN, INSIDE_DHT_SENSOR_TYPE);
  // outsideSensor = new DHTSensor(OUTSIDE_DHT_SENSOR_PIN, OUTSIDE_DHT_SENSOR_TYPE);
}

void loop() {
  // Wait a few seconds between measurements.
  delay(1000);
  screen->clear();

  // String number = "+48501819171";
  // String text = "Cześć Karol! Co słychać";
  // Serial.print("Before send SMS!");
  // simCard.sendSMS(number, text);
  // Serial.print("After send SMS!");

  String scaleText = "Waga: ";

  // int value = scale.getUnits();
  Serial.print("WAGA: ");
  // Serial.print(value);

  // // scaleText += String();
  // screen->setCursor(0, 0);
  // screen->showText(scaleText.c_str());

  // float temperature = insideSensor->readTemperature();
  // float humidity = insideSensor->readHumidity();

  // String text = "Hum1 " + String(12) + "%";
  // screen->setCursor(0, 0);
  // screen->showText(text.c_str());
  // text = "Temp1 " + String(-10);
  // screen->setCursor(0, 1);
  // screen->showText(text.c_str());

  // delay(3000);
  // screen->clear();

  // temperature = outsideSensor->readTemperature();
  // humidity = outsideSensor->readHumidity();

  // text = "Hum2 " + String(humidity) + "%";
  // screen->setCursor(0, 0);
  // screen->showText(text.c_str());

  // text = "Temp2 " + String(temperature);
  // screen->setCursor(0, 1);
  // screen->showText(text.c_str());
}