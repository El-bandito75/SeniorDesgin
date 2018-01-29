
#include <WiFi.h>
//WiFi  wifi = require('WiFi');

const char*  ssid = "nachowifi";
const char* password ="Calicojack16";
WiFiServer mywiFiServer(8080);

//function onWiFiConnect(){
  //var IPobject = wifi.getIP();

  //var IP = IPobject.ip;
  //var MAC = IPobject.mac;
  
//console.log("IP:");
//console.log(IP);

//console.log("MAC:");
//console.log(MAC);
  
//}
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN,OUTPUT);
  Serial.begin(115200);
  delay(1000);
  //wifi.connect(ssid, {password; password}, onWiFiConnect);
  
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
      delay(1000);
      Serial.println("Connecting to WiFI..");   
  }

  Serial.println("Connected to the WiFi network :)");
  Serial.println(WiFi.localIP());
  mywiFiServer.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client = mywiFiServer.available();
  if( client){
  while(client.connected()){
    while(client.available()>0){
      char c = client.read();
      client.write(c);
    }
    delay(10);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(250);
    digitalWrite(LED_BUILTIN, LOW);
    delay(250);
  }  
  client.stop();
  Serial.println("Client disconnected");
  }
  
  

}

