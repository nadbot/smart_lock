//www.elegoo.com
//2016.12.9

/* @file CustomKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates changing the keypad size and key values.
|| #
*/
#include <Keypad.h>
#include <ESP8266WiFi.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
//byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
//byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

const char *ssid = "ESP8266 Access Point"; // The name of the Wi-Fi network to connect to
const char *password = "thereisnospoon";   // The password required to connect to it, leave blank for an open network


// For ESP8266 Microcontroller
byte rowPins[ROWS] = {D1, D2, D3, D4}; 
byte colPins[COLS] = {D5, D6, D7, D8}; 

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

String password = "976431";

void setup(){
  Serial.begin(115200);
}

String entered = "";

void loop() {
  char key = customKeypad.getKey();

  if (key){
    Serial.println(key);
    if(key != '#'){
      entered = entered + key;
    }
    if(key == '#'){
      Serial.println("Pressed #");
      Serial.println(entered);
      if(entered == password){
        Serial.println("Correct password");
      }else {
        Serial.println("Wrong password");
      }
      entered = "";
    }
  }
}
//void loop(){
//  String enteredString = "";
//  char key = 'a';
//  while(true){
//    key = customKeypad.getKey();
//    while (key == NO_KEY) key = customKeypad.getKey();
//    Serial
//    if(key == '#'){
//      break;
//    }
//    enteredString = enteredString + key;
//  }
//    Serial.println(enteredString);
//    if(enteredString == password){
//      Serial.println("Correct password");
//    }
//    
//}
