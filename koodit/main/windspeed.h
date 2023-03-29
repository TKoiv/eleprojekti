#include <EEPROM.h>
#define TIMSK1  TIMSK

int period = 0.1;                
int fanSampleRate = 1; 
int fanPin = A2;

int highest = 0;     / 
int seconds = 0;     
int promAddr = 0;    

timer1_init();

void timer1_init() {
  
  cli(); // stop interrupts
  TCCR1A = 0; // set entire TCCR1A register to 0
  TCCR1B = 0; // same for TCCR1B
  TCNT1  = 0; // initialize counter value to 0
  // set compare match register for 1 Hz increments
  OCR1A = 62499; // = 16000000 / (256 * 1) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS12, CS11 and CS10 bits for 256 prescaler
  TCCR1B |= (1 << CS12) | (0 << CS11) | (0 << CS10);
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  sei(); // allow interrupts 
}


ISR(TIMER1_COMPA_vect) {        
  seconds++;
  if (seconds >= period) {
    seconds = 0;
    //Serial.print("m/s: ");
    //Serial.println(highest * 0.109 * 0.44);
    
    EEPROM.write(promAddr++, highest);
 
    highest = 0;
  }
}



float windspeed_measurement() 
{
  int newReading = analogRead(fanPin);
  
    if (newReading > highest)
    {
        highest = newReading;
    }

    delay(fanSampleRate);
    
    return highest;
}
