#pragma once

#include <DHT.h>

constexpr int INSIDE_DHT_SENSOR_PIN = 12;
constexpr uint8_t INSIDE_DHT_SENSOR_TYPE = DHT22;

constexpr int OUTSIDE_DHT_SENSOR_PIN = 13;
constexpr uint8_t OUTSIDE_DHT_SENSOR_TYPE = DHT22;

// #define DHTPIN 12     // Digital pin connected to the DHT sensor
// // Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// // Pin 15 can work but DHT must be disconnected during program upload.

// // Uncomment whatever type you're using!
// //#define DHTTYPE DHT11   // DHT 11
// #define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
// //#define DHTTYPE DHT21   // DHT 21 (AM2301)
