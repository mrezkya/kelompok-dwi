#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 12);
boolean ind = false;
#define pinSensor A1 //Pin Sensor Water Level
int nilai = 0; // Menyimpan data sensor di Variable Nilai
void setup() {
Serial.begin(9600);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(13, OUTPUT);
pinMode(3, OUTPUT);
digitalWrite(13, HIGH);
lcd.begin();
lcd.backlight();
lcd.print("aktif");
}

void loop() {
int ketinggian = bacaSensor();
Serial.print("Ketinggian Air :" );
Serial.println(ketinggian);
delay(200);
if(ketinggian > 500){
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
}

int bacaSensor(){
nilai = analogRead(pinSensor);
return nilai;
}
