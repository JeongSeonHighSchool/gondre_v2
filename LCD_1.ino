#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN 2

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
 
LiquidCrystal_I2C lcd(0x27, 16, 2);
 
 
void setup()
{
  lcd.init();
  lcd.backlight();
  pinMode(3,OUTPUT);
  
  Serial.begin(9600);
}
 
 
void loop()
{
  

  int h = dht.readHumidity();

  int t = dht.readTemperature();

  lcd.setCursor(0,0);
  lcd.print("Humi:");

  lcd.print(h);

  lcd.println("% ");
  lcd.setCursor(0,1);

  lcd.print("Temp:");

  lcd.print(t);

  lcd.print("'C");
  delay(1000);
  if(h>=80){
    //servo 작동 가습기 off    
    digitalWrite(3,LOW);
    delay(1000);
  }
   else if(h<=60){
    //servo 작동 가습기 on
    digitalWrite(3,HIGH);
    delay(1000);
   }
    
  
}
