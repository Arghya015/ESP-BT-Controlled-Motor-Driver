#include <ESP32Servo.h>
#include <BluetoothSerial.h>


BluetoothSerial SerialBT;
Servo myServo;

int servoPin = 13;  // Servo signal pin

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Servo");  // Bluetooth device name
  myServo.attach(servoPin);

  Serial.println("Bluetooth Servo Control Started...");
  Serial.println("Send angle (0-180) via Bluetooth.");
}

void loop() {
  if (SerialBT.available()) {
    String input = SerialBT.readStringUntil('\n'); // Read until newline
    int angle = input.toInt();

    if (angle >= 0 && angle <= 180) {
      myServo.write(angle);
      Serial.print("Servo moved to: ");
      Serial.println(angle);
    } else {
      Serial.println("Invalid angle! Send value 0-180");
    }
  }
}
