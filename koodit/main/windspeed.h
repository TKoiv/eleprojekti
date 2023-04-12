int pin = PA2;
int highest;



float windspeed_measurement() {
  float measure = analogRead(pin);
  float voltage = measure * 5 / 1023;
  //Serial.println(voltage,3);
  return voltage;

}