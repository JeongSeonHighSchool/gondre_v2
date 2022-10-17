#include <Servo.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN 2

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
 
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo;
int value = 0;
int pan = 22;
int pan_2 = 30;
int pan_3 = 36;
void setup()
{
  lcd.init();
  lcd.backlight();
  pinMode(3,OUTPUT);
  pinMode(pan,OUTPUT);
  pinMode(pan_2,OUTPUT);
  pinMode(pan_3,OUTPUT);
  
  servo.attach(7);
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
  
  if(h>=90){
    value = 90;  
    servo.write(value);
    delay(500);
    value = 0;
    servo.write(value);
    delay(500);
    value = 90;
    servo.write(value);
    delay(500);
    digitalWrite(3,LOW);
    digitalWrite(pan,HIGH);
    digitalWrite(pan_2,HIGH);
    digitalWrite(pan_3,HIGH);
    delay(1000);
  }
   else if(h<=70){
    value = 90;  
    servo.write(value);
    delay(500);
    value = 0;
    servo.write(value);
    delay(500);
    value = 90;
    servo.write(value);
    delay(500);//servo 작동 가습기 on
    digitalWrite(3,HIGH);
    digitalWrite(pan,LOW);
    digitalWrite(pan_2,LOW);
    digitalWrite(pan_3,LOW);
    delay(1000);
    
   }
   
  
}
