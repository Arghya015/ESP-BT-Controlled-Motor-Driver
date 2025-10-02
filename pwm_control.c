const int potPin = A0;
const int in1 = 8;
const int in2 = 4;
const int ena = 9; // PWM pin (Uno: 3,5,6,9,10,11 are PWM)

void setup(){
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(ena, OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void loop(){
  int pot = analogRead(potPin);          // 0-1023
  int speed = map(pot, 0, 1023, 0, 255); // 0-255 for analogWrite

  // Optional: choose direction based on pot mid point
if (pot > 350) {               // Forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(ena, map(pot, 350, 1023, 0, 255));  
} 
else if (pot < 350) {          // Reverse
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ena, map(pot, 350, 0, 0, 255));    
} 
else {                         // Stop
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(ena, 0);
}
}
