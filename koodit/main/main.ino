#include "hum_temp_sensor.h"
#include "lumen.h"
#include "windspeed.h"

float temperature ;
float humidity ;
int lumen ;
float windspee d;

float taulukko[4];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();

}

void loop() {
  // put your main code here, to run repeatedly:

  temperature = temp_measurement();
  taulukko[0] = temperature;
  humidity = hum_measurement();
  taulukko[1] = humidity;
  lumen = lumen_measurement();
  taulukko[2] = lumen;
  windspeed = windspeed_measurement();
  taulukko[3] = windspeed;


  Serial.print(taulukko[0]);
  Serial.print("°C");
  Serial.print(" ");
  Serial.print(taulukko[1]);
  Serial.print("%");
  Serial.print(" ");
  Serial.println(taulukko[2]);
  Serial.print("lux");
  Serial.print(" ");
  Serial.println(taulukko[3]);
  Serial.print("m/s");
  Serial.print(" ");


}
