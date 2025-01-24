#include <MD_Parola.h>
#include "RTClib.h"
#include"Wire.h"

RTC_DS1307 RTC;
DateTime now;
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN    10
int i;
MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
 
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
char monthOfTheYear[12][12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
void setup()
{
  Serial.begin(9600);
 
  P.begin();
  P.setInvert(false); 
  P.setIntensity(1);
  Wire.begin();
  RTC.begin();
//  if (! RTC.isrunning())
//      {
//        //Serial.println("RTC is NOT running!");
//        RTC.adjust(DateTime(__DATE__, __TIME__));
//      }
      //RTC.adjust(DateTime(__DATE__, __TIME__)); //sets date and time 

  P.displayText("DIGITAL CLOCK PROJECT" , PA_CENTER, 50, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT); 
  while (!P.displayAnimate());
}
 
const char *ZiuaCurenta = " ";
 
String Hour;
String TIMP=" ";
String ORA=" ";
String MINUT=" ";
String SECUNDA=" ";
String DATA="";
 
String Day;
String Month;
String Year;
String HumSTR;
String CelSTR;
String FarSTR;
 
void loop()
{
  now = RTC.now(); 
  String DayOfWeek = daysOfTheWeek[now.dayOfTheWeek()];
  String MonthOfYear = monthOfTheYear[now.month() - 1];
  const char *DayOfWeekC = DayOfWeek.c_str();
  const char *MonthOfYearC = MonthOfYear.c_str();
 
  ORA = (now.hour());
  if (ORA.length() < 2)
         {
           ORA = "0"+ ORA;
         }
 
  MINUT = (now.minute());
  if (MINUT.length() < 2)
         {
           MINUT = "0"+ MINUT;
         }
 
  TIMP = ORA + ":" + MINUT;
 
  const char *Timp = TIMP.c_str();
 
  Day = now.day();
  Month = now.month();
  Year = now.year();
 
  const char *Ziua = Day.c_str();
  const char *Luna = Month.c_str();
  const char *Anul = Year.c_str();
 
  String Date = Day + "/" + Month + "/" + Year;
  const char *Data = Date.c_str(); 
    
    if(i==0)
    {
       P.displayText("WELCOME TO PHYTEC EMBEDDED IOT LAB!" , PA_CENTER, 50, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT); 
         while (!P.displayAnimate());
    }
      if(i==1)
    {
       P.displayText("PHYTEC EXPO" , PA_CENTER, 50, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT); 
         while (!P.displayAnimate());
    }
    
    else if (i == 2)
    {
        P.displayText(DayOfWeekC, PA_CENTER, 50, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT); 
         while (!P.displayAnimate());
    }
    else if (i == 3)
    {
        P.displayText(Ziua, PA_CENTER, 100, 1000, PA_SCROLL_LEFT, PA_SCROLL_LEFT); 
         while (!P.displayAnimate());
    }
    else if (i == 4)
    {
        P.displayText(MonthOfYearC, PA_CENTER, 50, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT); 
         while (!P.displayAnimate());
    }
    else if (i == 5)
    {
        P.displayText(Anul, PA_CENTER, 10, 3000, PA_SCROLL_DOWN, PA_SCROLL_DOWN); 
         while (!P.displayAnimate());
    }
    else if (i == 6)
    {
        P.displayText(Timp, PA_CENTER, 50, 5000, PA_SCROLL_DOWN, PA_SCROLL_DOWN); //for setting time
         while (!P.displayAnimate());
    }
     i= i+1; 
     if (i > 6) 
       {  
         i=0;
       }
 
}
