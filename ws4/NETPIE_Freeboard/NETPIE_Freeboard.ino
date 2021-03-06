#include <DHT.h> 
#include <ESP8266WiFi.h> 
#include <MicroGear.h>

//const char* ssid = "itbakery-wifi"; 
//const char* password = "itbakery@9";

const char* ssid = "dragons"; 
const char* password = "dragonsoffice";

#define APPID "TrainIoT" // AppID
#define KEY "Ct0kTCsmAEQphIk" // Device Key
#define SECRET "9AScuAJcCiAHfK4w13zW5P65E" //Secret Device Key
#define ALIAS "piedht" // Alias
WiFiClient client;
int timer = 0; 
char str[32];
#define DHTTYPE DHT11 //Define sensor type 
#define DHTPIN D6 // Define sensor pin GPIO12
DHT dht(DHTPIN, DHTTYPE, 15); //Initialize DHT sensor

int humid; 
int temp;
MicroGear microgear(client);

void onMsghandler(char *topic, uint8_t* msg, unsigned int msglen) {
      Serial.print("Incoming message --> ");
      msg[msglen] = '\0';
      Serial.println((char *)msg);
}

void onConnected(char *attribute, uint8_t* msg, unsigned int msglen) {
      Serial.println("Connected to NETPIE...");
      microgear.setAlias(ALIAS);
}
void setup() { 
  dht.begin();
  
  microgear.on(MESSAGE,onMsghandler);
  microgear.on(CONNECTED,onConnected);
  Serial.begin(115200);
  Serial.println("Starting...");

  if (WiFi.begin(ssid, password)) {
      while (WiFi.status() != WL_CONNECTED) {
          delay(500);
          Serial.print(".");
      }
  }
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
  microgear.init(KEY,SECRET,ALIAS);
  microgear.connect(APPID);
}

void loop() {
  if (microgear.connected()) {
      Serial.println("connected");
      if (timer >= 1000) {
          humid = dht.readHumidity();
          temp = dht.readTemperature();
          sprintf(str,"%d,%d",humid,temp);
          Serial.println(str);
          Serial.println("Sending --> "); 
          microgear.publish("/dht",str);
          timer = 0;
      }
      else timer += 100;
  }
  else { 
    Serial.println("connection lost, reconnect...");
    if (timer >= 5000) { 
      microgear.connect(APPID);
      timer = 0;
      }
      else timer += 100;
  }
  delay(100);
}

