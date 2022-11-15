#include <SoftwareSerial.h> // TX RX software library for bluetooth
#include <Servo.h> // servo library 

Servo dispenseServo;

int bluetoothTx = 10; // bluetooth tx to 10 pin
int bluetoothRx = 11; // bluetooth rx to 11 pin

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

const int power_led = 9;
const int connection_led = 8;
const int success_led = 7;
const int put_trash_push_button = 2;

int is_connected = 0;
int buttonState = 0;          //variables for reading the pushbutton status

String incoming_Val;

void setup() {
  dispenseServo.attach(6);
  dispenseServo.write(90);
  Serial.begin(9600);// serial monitor stuff
  bluetooth.begin(9600); // Bluetooth connection

  pinMode(power_led, OUTPUT);
  pinMode(connection_led, OUTPUT);
  pinMode(success_led, OUTPUT);

  pinMode(put_trash_push_button, INPUT);
  digitalWrite(put_trash_push_button, HIGH);

  digitalWrite(power_led, HIGH); 
}

void loop() {
  if (bluetooth.available()){
    Serial.println("COnnecteddd!");
    incoming_Val = bluetooth.readString();
    Serial.println(incoming_Val);
    if(incoming_Val == "1"){
      Serial.println("IThaa poiii");
      dispenseServo.write(180);
      digitalWrite(success_led, HIGH);
      delay(1500);
      dispenseServo.write(90);
      digitalWrite(success_led, LOW); 
    }
  }
  // buttonState = digitalRead(put_trash_push_button); //read the state of the pushbutton value
  //   if (buttonState == LOW){
  //     Serial.println("Button pressed");
  //     dispenseServo.write(180);
  //     digitalWrite(success_led, HIGH); 
  //     bluetooth.write("+1");
  //     delay(1500);
  //     digitalWrite(success_led, LOW); 
  //     dispenseServo.write(90);
  //   }
      
    
  

}
