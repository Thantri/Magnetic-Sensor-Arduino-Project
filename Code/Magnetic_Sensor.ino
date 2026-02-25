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

void loop() {
  int rawValue = analogRead(A0); // Read once per loop for consistency
  Serial.println(rawValue);

  lcd.setCursor(0, 0);
  lcd.print("FluxDensity    "); // Clear trailing characters

  lcd.setCursor(0, 1);
  
  // 511.5 is the mid-point (0 Gauss) for a 5V supply
  // We calculate the difference from 0 Gauss
  float gaussValue = (rawValue - 511.5) * (5000.0 / 1024.0) / 1.4;

  lcd.print(gaussValue, 2); // Show 2 decimal places
  lcd.print(" G        ");

  delay(500); // Higher delay for readability
}
