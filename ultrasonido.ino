#define TRIG_PIN 14
#define ECHO_PIN 27

void setup() {

  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  unsigned long duracion = pulseIn(ECHO_PIN, HIGH, 30000UL);

  if (duracion==0) {

    Serial.println("No se detectó eco");

  } else {

    float distancia = duracion * 0.0343f / 2.0f;

    Serial.print("Distancia: ");
      Serial.print(distancia, 1);
      Serial.println(" cm");
  }

  delay(500);
}