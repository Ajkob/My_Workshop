/*
 ESP8266 Blink by Prarinya Ekapho
 Blink the blue LED on the NodeMCU ESP8266 V.2 module
 This example code is in the public domain
 
 The blue LED on the NodeMCU ESP8266 V.2 module is connected to GPIO1 
 (which is also the TXD pin; so we cannot use Serial.print() at the same time)
 
 Note that this sketch uses LED_BUILTIN to find the pin with the internal LED
*/
#define ledPin1 D1 //GPIO5
void setup() {
  pinMode(ledPin1, OUTPUT);     // Initialize the ledPin1 pin as an output
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(ledPin1, HIGH);   // Turn the LED on (Note that LOW is the voltage level
                                    // but actually the LED is on; this is because 
                                    // it is acive low on the NodeMCU ESP8266 V.2)
  delay(1000);                      // Wait for a second
  digitalWrite(ledPin1, LOW);  // Turn the LED off by making the voltage HIGH
  delay(2000);                      // Wait for two seconds (to demonstrate the active low LED)
}
