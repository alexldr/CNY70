#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 9, 11, 5, 4, 3, 2);
void setup() 
{
  lcd.begin(16,2);
  pinMode (A0,INPUT);
  Serial.begin(9600);
}

float v=0;
float Van=0;
float sig=0;

void loop() 
{
  delay(1500);
  v=analogRead(A0);
  Van=v*5/1023;
  sig=(((0.5381) - (sqrt(pow(-0.5381,2)-(4*0.015*(3.9098-Van)))))/(2*0.015));

  lcd.setCursor(0,0);
  lcd.print("Distancia: ");
  lcd.setCursor(0,1);
  lcd.print(sig);
  lcd.print(" milimetros");

}
