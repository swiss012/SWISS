#include <Servo.h>

Servo servo1;
int pos = 0;    

void setup() {
  Serial.begin(115200);
  servo1.attach(10);
  servo1.write(90);
}

void loop() {
  servo1.write(90);
  Serial.println("Lixeira fechada");
  delay(3000);
  servo1.write(0);
  Serial.println("Lixeira aberta em frente");
  delay(3000);
  servo1.write(90);
  Serial.println("Lixeira fechada");
  delay(3000);
  servo1.write(140);
  Serial.println("Lixeira aberta em atrás");
  delay(3000);
}
