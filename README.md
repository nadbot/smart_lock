# smart_lock
Code for automatic sliding lock.
One ESP8266 is connected to the servo motor and will unlock/lock the door, when it receives a http request on the specific url. 
The other (or arduino) is connected to the keypad. Once the correct password is entered, it sends a wifi request to the other esp, causing the locking/unlocking of the door

## Requirements
- Sliding lock
- 2 ESP8266 (for me Wemos D1 mini)
- Servo motor
- Membrance switch module (keypad)
- wires, paper clip (for connecting servo to lock)

## Wemos D1 Mini
TODO change name
TODO fix servo control (moves too much/little)

Code, that creates an access point and web server. When url /open is called, servo motor unlocks door, when /lock is called, servo motor locks door

