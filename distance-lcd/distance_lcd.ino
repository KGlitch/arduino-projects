// Definiere die Pins für Trigger und Echo
#define trigPin 3
#define echoPin 2
#define ledPin 4

void setup() {
  // Initialisiere die serielle Kommunikation
  Serial.begin(9600);
  
  // Setze den Trigger-Pin als Ausgang und den Echo-Pin als Eingang
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  long duration;
  int distance;
  
  // Stelle sicher, dass der Trigger-Pin LOW ist
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sende einen 10 Mikrosekunden langen HIGH-Puls aus
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Messe die Zeit, bis der Echo-Pin wieder LOW wird
  duration = pulseIn(echoPin, HIGH);
  
  // Berechne die Entfernung in Zentimetern
  // Schallgeschwindigkeit ca. 0,034 cm/µs; geteilt durch 2 (Hin- und Rückweg)
  distance = duration * 0.034 / 2;

  if (distance < 10) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  
  // Ausgabe der gemessenen Entfernung
  Serial.print("Entfernung: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(500); // Warte 500 ms bis zur nächsten Messung
}
