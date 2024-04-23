#include <Servo.h>
#include <HCSR04.h>

#define echoPin 12
#define servoPin 5
#define sensorPin 4
#define triggerPin 14

Servo servo;

void setup() {
  Serial.begin(115200);
  servo.attach(servoPin);
  servo.write(90);
  pinMode(sensorPin, INPUT);
  HCSR04.begin(triggerPin, echoPin);
}

void loop() {
  int sensorVal = digitalRead(4);
  double* distances = HCSR04.measureDistanceCm();


  Serial.print("Dados do sensor: ");
  Serial.println(sensorVal);
  Serial.print("Distante do objeto: ");
  Serial.print(distances[0]);
  Serial.println(" cm");

  
  if (distances[0] > 0 && distances[0] < 5) {
    Serial.println("Objeto detetado");

    if (sensorVal == 1) {
      delay(1500);
      servo.write(160);
      delay(5000);
      servo.write(90);
    }
    else {
      delay(1500);
      servo.write(0);
      delay(5000);
      servo.write(90);
    }
  }
}
