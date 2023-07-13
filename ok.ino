#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 12);
boolean ind = false;
#define pinSensor A1 //Pin Sensor Water Level
int nilai = 0; // Menyimpan data sensor di Variable Nilai
int val = 0;
//kelompok 2 source code
void setup() {
Serial.begin(9600);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(13, OUTPUT);
//pinMode(3, OUTPUT);
digitalWrite(13, LOW);
lcd.begin();
lcd.backlight();
lcd.print("aktif");
}

void loop() {
int ketinggian = readSensor();
Serial.print("Ketinggian Air :" );
Serial.println(ketinggian);
if(ketinggian > 250){
  lcd.setCursor(1,1);
  lcd.clear();
  digitalWrite(7, HIGH);
  Serial.println("HIGH");
  digitalWrite(8, HIGH);
  lcd.print("Air full   ");
}else{
  lcd.setCursor(1,1);
  lcd.clear();
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  Serial.println("LOW");
  lcd.print("Mengisi Air");
}
delay(2000);
}
int readSensor() {
  digitalWrite(13, HIGH);  
  delay(10);              
  val = analogRead(pinSensor);
  digitalWrite(13, LOW);   
  return val;            
}
