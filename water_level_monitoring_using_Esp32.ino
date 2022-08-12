#include "config.h"

// set up the 'waterlevl' and 'display' feeds
AdafruitIO_Feed *WaterLevel = io.feed("WaterLevel"); 
AdafruitIO_Feed *Display = io.feed("Show");


// Defining to the pins of esp8266
#define trigPin 16    // trigger pin of ultrasonic sensor  
#define echoPin 14    // echo pin of ultrasonic sensor.
#define green 5       // green led 
#define red 0         //red led
#define buzzer 2      // buzzzer
#define MaxDist 15  // Max distance (cm)


void setup() {
Serial.begin (115200);           // echo pin of ultrasonic sensor
io.connect();
// wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
//  WiFi.begin(SSID,PASS);
  // we are connected
  Serial.println();
  Serial.println(io.statusText());
// defining the pins as input and output respectively 
pinMode(echoPin, INPUT);
pinMode(trigPin, OUTPUT);
pinMode(green, OUTPUT);
pinMode(red, OUTPUT);
pinMode(buzzer, OUTPUT);
}

void loop() {

io.run();    // function. it keeps the client connected to
delay(50);
long duration, distance;
digitalWrite(trigPin, LOW); 
delayMicroseconds(2); 
digitalWrite(trigPin, HIGH);
delayMicroseconds(10); 
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;        // get distance in cm
float p= (MaxDist - distance);
float p1= (p/MaxDist);                 // converting into percentage
int percent= p1 *100;


 if (percent >= 80){                   // when percentage is than 80%
digitalWrite(green,LOW);               // green turn off
tone(buzzer,400,200);                  // buzzer starts beeping
digitalWrite(red,HIGH);                // red glows
delay(500);
Display -> save("Warning!");           // sending warning to the cloud
}
else {                                 // less than 80%
digitalWrite(red,LOW);                 // red turns off
digitalWrite(green,HIGH);              // green glows
noTone(buzzer);                        // buzzer stops beeping
Display -> save("Normal!");            // sending normal to the cloud
}
WaterLevel ->save(percent);       // sending value of percentage to the cloud
delay(500);
}
