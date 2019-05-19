#include <DHT.h>
#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>

#define DHTPIN 2
#define DHTTYPE DHT11

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  //Serial.begin(9600);
  lcd.begin(16,2);   // Inicjalizacja LCD 2x16
  lcd.backlight(); // zalaczenie podwietlenia
  lcd.setCursor(0,0); // Ustawienie kursora w pozycji 0,0 (pierwszy wiersz, pierwsza kolumna)
  dht.begin(); // inicjalizuję czujnik DHT
  

}

void loop() {
  delay(2000); // czekam 2s
  float temp = dht.readTemperature(); // tworzę zmienną typu float przechowującą pomiar temperatury
  float wilg = dht.readHumidity(); // tworzę zmienną typu float przechowującą pomiar wilgotności

  if (isnan(temp) || isnan(wilg)) 
  { // sprawdzam czy nie ma błędu odczytu
    return; // wychodzę z pętli
  }
  lcd.setCursor(0,0);
  lcd.print("TEMP: ");
  lcd.print(temp);
  lcd.print("*C ");
  lcd.setCursor(0,1);
  lcd.print("HUMID: ");
  lcd.print(wilg);
  lcd.print("%");
}
