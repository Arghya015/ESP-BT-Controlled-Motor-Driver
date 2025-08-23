#include "BluetoothSerial.h"
BluetoothSerial SerialBT;

int IN1 = 18;
int IN2 = 19;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  Serial.begin(115200);
  SerialBT.begin("ESP Controlled Motor");
  Serial.println("Bluetooth connected!!");
}

void loop() {
  if(SerialBT.available()) {
    char command = SerialBT.read();
    
     // Forwardchar 
    if (command == 'F') { 
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  Serial.println("Forward");
   } 
  // Backward
  else if(command == 'B') {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  Serial.println("Backward");
   }
  else if(command == 'S'){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  Serial.println("Stopped");
   }
  }
}
