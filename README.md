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
- TODO change name
- TODO fix servo control (moves too much/little)
- TODO fix error (still works after reset without problems) 
    - serial.serialutil.SerialException: could not open port 'COM6': PermissionError(13, 'Access is denied.', None, 5)
    
    
Code, that creates an access point and web server. When url /open is called, servo motor unlocks door, when /lock is called, servo motor locks door
https://tttapa.github.io/ESP8266/Chap07%20-%20Wi-Fi%20Connections.html


## Keypad
- TODO currently only opens door if password is correct (need to lock it somehow, maybe through a button next to lock?)
- TODO add display to show entered letters (as *)
- TODO fix bug, that client says timeout even though it sends the get request

https://diyi0t.com/keypad-arduino-esp8266-esp32/


# Future elements

## Have button on keyboard (of PC in different network)
- Connect 2 networks: https://speedify.com/blog/combining-internet-connections/how-to-join-two-wi-fi-networks-at-once/
- Change function of button (example f10)

## Have button on lock to lock it after entering room
