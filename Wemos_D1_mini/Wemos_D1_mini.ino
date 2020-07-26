/*

 This example connects to an unencrypted Wifi network.
 Then it prints the  MAC address of the Wifi shield,
 the IP address obtained, and other network details.

 Circuit:
 * WiFi shield attached

 created 13 July 2010
 by dlf (Metodo2 srl)
 modified 31 May 2012
 by Tom Igoe
 */


#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include <Servo.h>

#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

ESP8266WebServer server(80);

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

const char *ssid = "ESP8266 Access Point"; // The name of the Wi-Fi network that will be created
const char *password = "thereisnospoon";   // The password required to connect to it, leave blank for an open network

void setup() {
  Serial.begin(115200);         // Start the Serial communication to send messages to the computer
  delay(10);
  Serial.println('\n');
  
//  WiFi.begin(ssid, password);             // Connect to the network
//  Serial.print("Connecting to ");
//  Serial.print(ssid); Serial.println(" ...");
//
//  int i = 0;
//  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
//    delay(1000);
//    Serial.print(++i); Serial.print(' ');
//  }
//
//  Serial.println('\n');
//  Serial.println("Connection established!");  
//  Serial.print("IP address:\t");
//  Serial.println(WiFi.localIP());         // Send the IP address of the ESP8266 to the computer

  // Create an access point (to have a small local wifi network, to which the other ESP8266 can connect)
  WiFi.softAP(ssid, password);             // Start the access point
  Serial.print("Access Point \"");
  Serial.print(ssid);
  Serial.println("\" started");

  Serial.print("IP address:\t");
  Serial.println(WiFi.softAPIP());

  myservo.attach(4);  // attaches the servo on pin 4 to the servo object

  //  start web server
  
  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);

  server.on("/open", []() {
    open();
    server.send(200, "text/plain", "Opening door");
  });
  server.on("/lock", []() {
    close();
    server.send(200, "text/plain", "Locking door");
  });
  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
//  Serial.println("Opening");
//  open();
//  delay(10000);
//  close();
  server.handleClient();
  MDNS.update();
}

// Servo

//////////////////////////////////////////////////////////////////
// TODO check why close does nothing and open continues forever //
//////////////////////////////////////////////////////////////////

void close(){
  for (pos = 0; pos <= 360; pos += 10) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
void open(){
  for (pos = 360; pos >= 0; pos -= 10) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

// Web server

void handleRoot() {
  server.send(200, "text/plain", "hello from esp8266!");
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}
