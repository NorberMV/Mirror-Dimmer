/* Title : Mirror dimmer
 *  Description: This sketch allows to the user to dim the lights of a LED bulbs through a circuit made with a 
 *  potentiometer and a MOSFET transistor module. 
 *  Authors: Norberto Moreno Vélez, Andres Isaza
 *  Fecha: 10/02/2021
  */


int sensorData;
int dataRead = A0;
int percentLecture;
int out_pin = 3;

void setup() {
   Serial.begin(115200); 
   pinMode(out_pin,OUTPUT);
}

/* Dimmer function: Read the analogue signal  
and returns and mapped signal to perform the 8 bit PWM */

int getDimm() {
  sensorData= analogRead(dataRead);
  percentLecture = map(sensorData, 0, 1023, 0, 255);
  return percentLecture;
}

void loop() {
  Serial.print("Output PWM resolution: ");
  int data = getDimm();
  Serial.println(data); // Display the 8 bit resolution output
  analogWrite(out_pin, data);
  delay(30);
}

