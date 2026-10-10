#include <LiquidCrystal.h>
#include <DHT.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
DHT dht(8, DHT11);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  dht.begin();
}

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  lcd.clear();
  if (isnan(t) || isnan(h)) {
    lcd.print("Erro no sensor");
  } else {
    lcd.print("Temperatura: "); lcd.print(t, 0); lcd.print((char)223); lcd.print("C");
    lcd.setCursor(0, 1);
    lcd.print("Humidade: "); lcd.print(h, 0); lcd.print("%");
    Serial.print(t); Serial.print(","); Serial.println(h);
  }
  delay(2000);
}