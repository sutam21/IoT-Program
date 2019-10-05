/*            Sutam Project
      Control Relay Use Voice With Bluetooth
      Creator : Rafli Setiawan
      Inpiration By : Duwiarsana
 */

#include <SoftwareSerial.h>
SoftwareSerial bluetooth(0,1); // pin RX | TX
String voice;
#define relay 8

void setup() {
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
}

void loop() {
  while (Serial.available()){
    delay(10);
    char c = Serial.read();
    if(c == '#'){break;}
    voice += c;
  }
  if (voice.length() > 0) {
    Serial.println(voice);
//-----------------------------------------------------------------------//

// menyalakan relay
  if(voice == "hidupkan relay"){
  digitalWrite(relay, LOW);
  /* COM ke NO (Tertutup) Maka listrik akan dialirkan ke COM dan NO
  sehingga pada keadaan ini COM ke NC(Terbuka / tidak ada aliran yang masuk) */
  }
  
  else if(voice == "matikan relay"){
    digitalWrite(relay, HIGH);
    /* COM ke NO (Tertutup) Maka listrik akan dialirkan ke COM dan NC
    sehingga pada keadaan ini COM ke NO(Terbuka / tidak ada aliran yang masuk) */
  }
  
voice="";}}
