#include <Wire.h>  // Comes with Arduino IDE
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16,2);
//LiquidCrystal_I2C lcd(0x27, 16,2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  lcd.init();
  for(int i = 0; i<3; i++)
  {
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }
  lcd.backlight();
  
  lcd.setCursor(0,0);
  lcd.print(".........");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print(".........");
  delay(8000);
 }

void loop()
{
  {
  // when characters arrive over the serial port...
  if(Serial.available()){
    // wait a bit for the entire message to arrrive
    delay(300);
    // clear the screen
    lcd.clear();
    // read all the available characters
    while(Serial.available()>0)
    {
      // display each character to the LCD
      lcd.write(Serial.read());
    }
   }
  }
}
 
