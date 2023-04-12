#include "DHT.h"
#define DHTPIN A0
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

//measures humidity and temperature

float hum_measurement(){
  delay(500);
  float h = dht.readHumidity();
  return h;
}

float temp_measurement(){
  delay(500);
  float t = dht.readTemperature();
  return t;
}