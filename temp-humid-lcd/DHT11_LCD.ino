#include <DHT.h>
#include <LiquidCrystal.h>

// Pins für den DHT11-Sensor
#define DHTPIN 13      // Datenpin des DHT11-Sensors
#define DHTTYPE DHT11  // Sensor-Typ

// DHT-Sensor initialisieren
DHT dht(DHTPIN, DHTTYPE);

// LCD-Pins (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);  // Serielle Kommunikation starten
  dht.begin();         // DHT-Sensor initialisieren
  lcd.begin(16, 2);    // LCD mit 16 Zeichen & 2 Zeilen initialisieren

  // Begrüßungsnachricht auf LCD anzeigen
  lcd.print("Temp.Messung...");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Temperatur & Luftfeuchtigkeit auslesen
  float temperature = dht.readTemperature(); // Temperatur in Celsius
  float humidity = dht.readHumidity();       // Luftfeuchtigkeit in %

  // Falls keine gültigen Werte ausgelesen wurden
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Fehler beim Auslesen des Sensors!");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensor Fehler");
    delay(2000);
    return;
  }

  // Serielle Ausgabe der Werte
  Serial.print("Temperatur: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Luftfeuchtigkeit: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.println("-----------------------------");

  // LCD-Anzeige aktualisieren
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd
