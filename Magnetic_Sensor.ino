#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x20, 16, 2);
char ADCSHOW[5];
void setup()
{
	// initialize the LCD
	lcd.begin();

	// Turn on the blacklight and print a message.
	lcd.backlight();
  Serial.begin(9600);
}

void loop()
{
Serial.println(analogRead(A0));

lcd.print("FluxDensity");//showing name

lcd.setCursor(0, 1);//move to second line

lcd.print("(In Gauss):");// showing units
if(analogRead(A0)<490){
String ADCVALUE = String(((analogRead(A0)-511.5)*0.001));

 /* Now since the default reference if 5V and resolution is 10bit so for every 5/1024 = 4.9mV, we get one increment is count, The sensor provides increment voltage range of 1.4mV for every 1Gauss increment if field.
So we need to divide ADC value by 3.49 for getting the gauss value, now the 0 gauss output of sensor is 2.5V so we need to subtract that first. To hold a 0V read at 0Gauss field. */
 // Convert the reading to a char array

delay(300);
ADCVALUE.toCharArray(ADCSHOW, 5);

lcd.print(ADCSHOW);//showing the field strength value

lcd.print("G  ");

lcd.setCursor(0, 0);// set the cursor to column 0, line 0
}
/*if(analogRead(A0)>490 && analogRead(A0)<530){
String ADCVALUE = String(((analogRead(A0)-510)*0.001)+0.35);

 /* Now since the default reference if 5V and resolution is 10bit so for every 5/1024 = 4.9mV, we get one increment is count, The sensor provides increment voltage range of 1.4mV for every 1Gauss increment if field.
So we need to divide ADC value by 3.49 for getting the gauss value, now the 0 gauss output of sensor is 2.5V so we need to subtract that first. To hold a 0V read at 0Gauss field. 
 // Convert the reading to a char array

delay(300);
ADCVALUE.toCharArray(ADCSHOW, 5);

lcd.print(ADCSHOW);//showing the field strength value

lcd.print("G  ");

lcd.setCursor(0, 0);// set the cursor to column 0, line 0
}
if(analogRead(A0)>530){
String ADCVALUE = String(((analogRead(A0)-511.5)*0.001));

 /* Now since the default reference if 5V and resolution is 10bit so for every 5/1024 = 4.9mV, we get one increment is count, The sensor provides increment voltage range of 1.4mV for every 1Gauss increment if field.
So we need to divide ADC value by 3.49 for getting the gauss value, now the 0 gauss output of sensor is 2.5V so we need to subtract that first. To hold a 0V read at 0Gauss field. 
 // Convert the reading to a char array

delay(300);
ADCVALUE.toCharArray(ADCSHOW, 5);

lcd.print(ADCSHOW);//showing the field strength value

lcd.print("G  ");

lcd.setCursor(0, 0);// set the cursor to column 0, line 0
}*/
}
