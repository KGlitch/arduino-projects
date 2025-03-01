 #include <LiquidCrystal.h>

// LCD initialisieren: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int buzzerPin = 6;  // Buzzer an Pin 6
int countdown = 10; // Countdown-Wert

void setup() {
  lcd.begin(16, 2);  // 16 Zeichen, 2 Zeilen
  pinMode(buzzerPin, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print("Countdown:");
}

void loop() {
  for (int i = countdown; i >= 0; i--) {
    lcd.setCursor(0, 1);
    lcd.print("   "); // Lösche vorherige Zahl
    lcd.setCursor(0, 1);
    lcd.print(i);
    
    // Kurzer Piepton bei jedem Countdown-Schritt
    tone(buzzerPin, 1000, 200);
    delay(1000); // 1 Sekunde warten
  }

  // Endet der Countdown, langer Piepton
  lcd.setCursor(0, 1);
  lcd.print("Fertig!");
  
  tone(buzzerPin, 1000, 2000); // Langer Ton für 2 Sekunden
  delay(2000);
  
  noTone(buzzerPin);
  while (true); // Stoppt das Programm
}
