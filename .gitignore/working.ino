const int trigPin = 9; //naming a constant value / giving a variable name / #define acts as a find and replace
const int echoPin = 10;
const int led =  3;

int sensorValue;
const int analogInPin = A0;
int LEDbrightness;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT); //trigPin is sending out the signal
  pinMode(echoPin, INPUT); //echoPin is retrieving information, therefore it is INPUT
}

void loop() {
  
  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1; //Time it took for the echo to be received and divided in half then divided by the speed of sound
  
  Serial.print(distance);
  Serial.println(" cm");
//  delay(50); //delay half a second before repeating the loop

  //digitalWrite(led, LOW);

  sensorValue = analogRead(analogInPin);

  LEDbrightness = map(sensorValue, 0, 100, 0, 255);
 
  if (distance <= 20 ){
   digitalWrite(led, LEDbrightness);
  } else {
 digitalWrite(led, LOW);
  }
}
