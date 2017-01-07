//SCL as D1/GPIO5
//SCA as D2/GPIO4
//#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// Initial I2C-LCD
// Address is 0x27 (for PCF8574) or 0x3F (for PCF8574A)
// Type 16 characters 2 lines
//LiquidCrystal_I2C lcd(0x3F, 16, 2);
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup()
{
lcd.init(); // Start
lcd.backlight(); // Enable LED backlight

}
void loop(){
 // put your main code here, to run repeatedly: 
lcd.setCursor(0,0); // Set home cursor
lcd.print("Line 1 Hello "); // Display message on line 1 (upper)
lcd.setCursor(0, 1); // Set new position
lcd.print("Line 2 Hello "); // Display message on line 2 (lower)
delay(5000);
lcd.clear();
delay(5000);

}
