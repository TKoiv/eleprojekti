#include "hum_temp_sensor.h"
#include "lumen.h"
#include "windspeed.h"

float temperature;
float humidity;
int lumen;
float windspeed;

float taulukko[4];

void setup() {
  Serial.begin(9600);
  dht.begin();
  timer1_init();

}

void loop() {


temperature = temp_measurement();
humidity = hum_measurement();
lumen = lumen_measurement();
windspeed =windspeed_measurement();

Serial.flush();
Serial.print("temp=");
Serial.print(temperature);
Serial.print("&");

Serial.print("hum=");
Serial.print(humidity);
Serial.print("&");

Serial.print("lux=");
Serial.print(lumen);
Serial.print("&");

Serial.print("wind=");
Serial.println(windspeed);


delay(7500);

}
