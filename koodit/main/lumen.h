/* Photocell reading program */
// Constants
#define DELAY 500 // Delay between two measurements in ms
#define VIN 5 // V power voltage
#define R 100000 //ohm resistance value
// Parameters
const int sensorPin = A1; // Pin connected to sensor
//Variables
int sensorVal; // Analog value from the sensor
int lux; //Lux value

int lumen_measurement() {
  sensorVal = analogRead(sensorPin);
  delay(DELAY);
  //lux=sensorRawToPhys(sensorVal);
  float Vout = float(sensorVal) * (VIN / float(1023));// Conversion analog to voltage
  float RLDR = (R * (VIN - Vout))/Vout; // Conversion voltage to resistance
  int phys=500/(RLDR/1000); // Conversion resitance to lumen
  return phys;
}
