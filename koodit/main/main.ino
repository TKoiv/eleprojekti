#include "hum_temp_sensor.h"
#include "lumen.h"

float temperature ;
float humidity ;
int lumen;

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


  Serial.print(taulukko[0]);
  Serial.print(" ");
  Serial.print(taulukko[1]);
  Serial.print(" ");
  Serial.println(taulukko[2]);


}
