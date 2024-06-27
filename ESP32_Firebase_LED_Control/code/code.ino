#include <WiFi.h>                                                
#include <IOXhop_FirebaseESP32.h>  

#define url "https://ledcontrol-afc17-default-rtdb.firebaseio.com/"           // replace with your Firebase URL
#define api "hhhP7agEBLLBA7m4fHXV2SdQFzp07FNSvwjTx7DJ" // replace with your secret key
#define SSID "NOHOTSPOT"       // replace with your SSID
#define PASSWORD "8270225079"

int firebasestatus=0;

void setup() {
  Serial.begin(115200);
  pinMode(2,OUTPUT);
  WiFi.begin(SSID,PASSWORD);
  while (WiFi.status() != WL_CONNECTED) { //connected to wifi process
  Serial.print(".");
  delay(500);
  }
  Firebase.begin(url,api);
  Firebase.setInt("ledstatus",0);
}

void loop() {
  firebasestatus=Firebase.getInt("ledstatus");// Read the value from Firebase
  if(firebasestatus==1){
    Serial.println("led is ON");
    digitalWrite(2,HIGH);//Turn ON the inbuit led in ESP32
  }
  else{
    Serial.println("led is OFF");
    digitalWrite(2,LOW);//Turn OFF the inbuilt led in ESP32
  }

}
