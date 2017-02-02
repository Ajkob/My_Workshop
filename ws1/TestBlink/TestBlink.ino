/*
 ESP8266 Blink by Prarinya Ekapho
 Blink the blue LED on the NodeMCU ESP8266 V.2 module
 This example code is in the public domain
 
 The blue LED on the NodeMCU ESP8266 V.2 module is connected on board and GPIO16 
 
 Note that this sketch uses LED_BUILTIN to find the pin with the internal LED
*/
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
                                    // but actually the LED is on; this is because 
                                    // it is acive low on the NodeMCU ESP8266 V.2)
  delay(1000);                      // Wait for a second
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(2000);                      // Wait for two seconds (to demonstrate the active low LED)
}

