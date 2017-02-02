#define ledPin D1 //GPIO5
#define sw D4 //GPIO2

int st_sw = 0;
int st = 0;
int last_st_sw = 1;

void setup() {
  pinMode(ledPin, OUTPUT); // Set pin mode
  pinMode(sw, INPUT_PULLUP);
}

void loop() {
  st_sw = digitalRead(sw); // Read input port1
  if ((st_sw == 0) && (last_st_sw == 1)) // Check current status
  {
    st = ~st; // Toggle
    digitalWrite(ledPin, st); // Drive LED1
    delay(250);
  }
  last_st_sw = st_sw; // Update current status
}
