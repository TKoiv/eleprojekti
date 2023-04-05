#include <WiFi.h>
#include <HTTPClient.h>
#define RXp2 16
#define TXp2 17
const char* ssid = "harrypotter";
const char* password = "ananas123";
String data = "";
String data2 = "";
//Your Domain name with URL path or IP address with path
String serverName = "https://ryhma5eleprojekti.000webhostapp.com";

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastTime = 0;
// Timer set to 10 minutes (600000)
//unsigned long timerDelay = 600000;
// Set timer to 5 seconds (5000)
unsigned long timerDelay = 5000;

void setup() {
  Serial.begin(115200); 
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
 
  Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
}

void loop() {
  //Send an HTTP POST request every 10 minutes
  if ((millis() - lastTime) > timerDelay) {
    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
      HTTPClient http;
      bool breakloop = true;

      while(Serial2.available() || breakloop == true) {
        String data = Serial2.readStringUntil('\n');
        data2 = data;
        data2.trim();
        Serial.println("Received data: " + data);
        breakloop = false;
        delay(500);
      }
      Serial.print("datapaska : ");
      Serial.println(data2);
      String serverPath = serverName;
      serverPath += "/handler.php?temp=";
      serverPath += data2;
      Serial.print("serverpath : ");
      Serial.println(serverPath);
      // Your Domain name with URL path or IP address with path
      http.begin(serverPath.c_str());
  
     
      // If you need Node-RED/server authentication, insert user and password below
      //http.setAuthorization("REPLACE_WITH_SERVER_USERNAME", "REPLACE_WITH_SERVER_PASSWORD");
      
      // Send HTTP GET request
      int httpResponseCode = http.GET();
      
      if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println(payload);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      // Free resources
      http.end();
    }
    else 
    {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
}