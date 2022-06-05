#include<DS3231.h>

DS3231 rtc(SDA,SCL);

void setup()
{
 rtc.begin();

  rtc.setTime(22, 0, 0);
  rtc.setDate(4, 6, 2022);
  rtc.setDOW(6);
}

void loop()
{  
}
