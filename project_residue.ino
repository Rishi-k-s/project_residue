#include <SoftwareSerial.h> // TX RX software library for bluetooth
#include <Servo.h> // servo library 

Servo dispenseServo;

int bluetoothTx = 10; // bluetooth tx to 10 pin
int bluetoothRx = 11; // bluetooth rx to 11 pin

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

const int power_led = 9;
const int connection_led = 8;
const int success_led = 7;
const int put_trash_push_button = 6;

int is_connected = 0;

void setup() {
  dispenseServo.attach(6);
  Serial.begin(9600);// serial monitor stuff
  bluetooth.begin(9600); // Bluetooth connection

  pinMode(power_led, OUTPUT);
  pinMode(connection_led, OUTPUT);
  pinMode(success_led, OUTPUT);

  pinMode(put_trash_push_button, INPUT);

  digitalWrite(power_led, HIGH); 
}

void loop() {
  if(bluetooth.available()){
    Serial.write("")
  }

}
