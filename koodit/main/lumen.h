#define DELAY 500 
#define VIN 5
#define R 100000

const int sensorPin = A1;

int sensorVal; 
int lux; 

//measures lumen

int lumen_measurement() {
  sensorVal = analogRead(sensorPin);
  delay(DELAY);
  float Vout = float(sensorVal) * (VIN / float(1023));// Conversion analog to voltage
  float RLDR = (R * (VIN - Vout))/Vout; // Conversion voltage to resistance
  int phys=500/(RLDR/1000); // Conversion resitance to lumen
  return phys;
}
