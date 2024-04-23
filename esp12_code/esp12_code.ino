#include <Servo.h>
#include <HCSR04.h>
#include <ESP8266WiFi.h>
#include <WiFiManager.h>
#include <FirebaseArduino.h>

#define echoPin 14
#define servoPin 4
#define sensorPin 5
#define intern_led 2
#define triggerPin 12

#define FIREBASE_HOST "swiss-33a45-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "Uu4HXaqCiW4K5F142RKwhYja4omslXqPzhqmxRMm"

Servo servo;

void internetError();

void setup() {
  WiFi.mode(WIFI_AP_STA);
  WiFiManager manager;
  Serial.begin(115200);
  servo.attach(servoPin);
  servo.write(90);
  pinMode(sensorPin, INPUT);
  pinMode(intern_led, OUTPUT);
  HCSR04.begin(triggerPin, echoPin);
  bool res;
  res = manager.autoConnect("ESP8266Config", "123456789");

  if (!res) {
    Serial.println("Falha ao se conectar, verifique as credencias!");
  }
  else {
    Serial.println("SWISS conectado ao WiFi com sucesso!");
  }
  WiFi.begin();
  internetError();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  if (WiFi.status() == 3) {
    digitalWrite(intern_led, LOW);
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
        Firebase.setInt("swiss/system/angle_servo", 160);
      }
      else {
        delay(1500);
        servo.write(0);
        delay(5000);
        servo.write(90);
        Firebase.setInt("swiss/system/angle_servo", 0);
      }
    }
  }
  else {
    internetError();
    Serial.println("Desconectado");
  }
}

void internetError()
{
  Serial.println("Erro de conexao a Internet/WiFi/Firebase");
  Serial.println("Se o erro prevalecer, clique no botão para reconfigurar o WiFi do sistema!!!");
  digitalWrite(intern_led, LOW);
  delay(500);
  digitalWrite(intern_led, HIGH);
  delay(500);
}
