#include<DS3231.h>
#include"LiquidCrystal_I2C.h"

DS3231 rtc(SDA,SCL);
LiquidCrystal_I2C lcd(0x27,20,4);

void setup()
{
  rtc.begin();
  lcd.init();
  lcd.backlight();
}

char tempF[6];
float temperature;

void loop()
{
 char * str;

  str = rtc.getTimeStr();
  lcd.setCursor(0,0);
  lcd.print("Time: ");
  lcd.print(str);

  str = rtc.getDateStr();
  lcd.setCursor(0,1);
  lcd.print("Date: ");
  lcd.print(str);
  
  str = rtc.getDOWStr();
  lcd.setCursor(0,2);
  lcd.print("Day: ");
  lcd.print(str);

  lcd.setCursor(0,3);
  lcd.print("Temperature: ");
  temperature = rtc.getTemp();
  dtostrf(temperature,5,1,tempF);

  lcd.print(tempF);
  lcd.print((char)223);
  lcd.print("c");

  delay(1000);
}
