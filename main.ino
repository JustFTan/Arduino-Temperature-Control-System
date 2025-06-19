#include "DHT.h"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
#define DHTPIN 5
#define DHTTYPE DHT11
#define FAN 4
#define BUZZER 3


DHT dht(DHTPIN, DHTTYPE);

void setup() {

  Serial.begin(9600);
  pinMode(FAN, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(DHTPIN, INPUT);

  lcd.begin();
  dht.begin();
  
  lcd.setCursor(0, 0);
  lcd.print("<< TugasBesar >>");
  lcd.setCursor(0, 1);
  lcd.print("<Kelompok  TE48>");
  delay(5000);
}

void loop() {
 
  float t = dht.readTemperature();

  Serial.println(t);

  if (t < 30){

    lcd.setCursor(0, 0);
    lcd.print("SISTEM PENDINGIN");

    lcd.setCursor(0, 1);
    lcd.print("<Temp: ");
    lcd.print(t);
    lcd.print((char)223);
    lcd.print("C >");
    

    digitalWrite(FAN, LOW);

  }else if (t > 30 && t < 40) {

    lcd.setCursor(0, 0);
    lcd.print("!KIPAS MENYALA! ");
    lcd.setCursor(0, 1);
    lcd.print("<Temp: ");
    lcd.print(t);
    lcd.print((char)223);
    lcd.print("C >");

    digitalWrite(FAN, HIGH);
    digitalWrite(BUZZER, LOW);

  }else if( t > 40){

    lcd.setCursor(0, 0);
    lcd.print("!!! ALARM ON !!!");
    lcd.setCursor(0, 1);
    lcd.print("WARNING OVERHEAT");

    digitalWrite(BUZZER, HIGH);
  } 
  delay(500);
}
