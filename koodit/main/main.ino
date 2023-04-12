#include "hum_temp_sensor.h"
#include "lumen.h"
#include "windspeed.h"

float temperature;
float humidity;
int lumen;
float windspeed;


void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(2,OUTPUT);

}

void loop() {
    digitalWrite(2, HIGH); // turn on LED
    delay(500); // wait for 500ms
    digitalWrite(2, LOW); // turn off LED
    delay(500); // wait for 500ms


temperature = temp_measurement();
humidity = hum_measurement();
lumen = lumen_measurement();
windspeed =windspeed_measurement();

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


delay(2000);

}
