/* Arduino Impulsive v.1.0
 * This little program is made for an arduino nano. It reacts to interrupts on pin D2 and D3
 * and triggers a message on the serial line to react to the interrupt on a upsteam system (i.e. python script).
 * This is made for a water, gas or energy meter with impulse outputs.
 */

volatile unsigned long t1=0;
volatile unsigned long t2=0;
volatile unsigned long twait=50;
const byte interruptPin1 = 2;
const byte interruptPin2 = 3;

void setup() {
  Serial.begin(115200);
  Serial.println("Arduino Impulsive v.1.0");
  pinMode(interruptPin1, INPUT_PULLUP);
  pinMode(interruptPin2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin1), signal1, FALLING);
  attachInterrupt(digitalPinToInterrupt(interruptPin2), signal2, FALLING);
}

void loop() {
  // loop loop
}

void signal1() {
  if((millis() - t1) > twait) { 
    Serial.println("PIN1 Triggered!");
    t1 = millis();
  }
}
void signal2() {
  if((millis() - t2) > twait) {
    Serial.println("PIN2 Triggered!");
    t2 = millis();
  }
}
