// Use the Adafruit DHT Sensor Library
// (this also requires the Adafruit Unified Sensor Library)
#include "DHT.h"

// Arduino pin connected to the DHT-11's data pin.
#define DHTPIN A0

// Type of DHT sensor.
#define DHTTYPE DHT11

// Initialize DHT sensor.
DHT dht(DHTPIN, DHTTYPE);


float hum_measurement(){
    // Wait a few seconds between measurements.
  delay(500);

  // Read humidity.
  float h = dht.readHumidity();

  return h;
}

float temp_measurement(){
    // Wait a few seconds between measurements.
  delay(500);

  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  return t;
}