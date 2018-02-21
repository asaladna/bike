#include <math.h>
#include "EmonLib.h"

EnergyMonitor emon1;
String toPrint1, toPrint2;
double Irms, thePower;
char buffer1[30], buffer2[30];

void setup()
{
 Serial.begin(9600);
 emon1.current(0, 111.1);  //pin for current measurement, calibration value
 pinMode(0, OUTPUT);   //enable UEXT power supply
 digitalWrite(0, LOW);
}
void loop()
{
 Irms = emon1.calcIrms(1480); // measure current
 thePower = Irms*230.0;   // we assume voltage is 230VAC if you add transformer to connect to other input you can measure real voltage too

 toPrint1 = String((int)thePower) + "." + String(((unsigned int)(thePower*100))%100) + "," + String((int)Irms) + "." + String(((unsigned int)(Irms*100))%100) + " ";
 //toPrint2 = String((int)Irms) + "." + String(((unsigned int)(Irms*100))%100) + " ";
 toPrint1.toCharArray(buffer1, 30);
 //toPrint2.toCharArray(buffer2, 30);
 Serial.println(toPrint1);
 //Serial.println(toPrint2);
 //Serial.println("----");
 
 
 delay(400);
}
