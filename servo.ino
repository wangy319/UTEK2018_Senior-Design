//#include <NewPing.h>
#include <Servo.h>

// define pins and other constants
const int servo1Pin = 3;
const int servo2Pin = 4;

//const int trigPin = 9;
//const int echoPin = 10;
//const int max_distance = 300;

// variables to use later on
//int dist;
int angle;

// create instances of servo and ping class
Servo Servo1;
Servo Servo2;
//NewPing sonar(trigPin, echoPin, max_distance);

void setup()
{
//  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
//  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  Servo1.attach(servo1Pin);   // connect servo to pin 3
  Servo2.attach(servo2Pin);   // connect servo to pin 4
}

void loop()
{
  //Serial.print("Ping: ");
  //dist = sonar.ping_cm();  
  //Serial.print(dist);
  //Serial.println("cm");

  /*
  Servo1.write(0);
  delay(500);  //wait 0.5 seconds
  Servo1.write(30);
  delay(500);  //wait 0.5 seconds
  Servo1.write(-30);
  delay(500);  //wait 0.5 seconds
  */
  Servo1.write(90);
  delay(2000);  //wait 0.5 seconds
  Servo1.write(180);    //Move Down
  delay(2000);  //wait 0.5 seconds
  delay(2000);  //wait 0.5 seconds
  Servo2.write(90);
  delay(2000);  //wait 0.5 seconds
  Servo2.write(120);    //Move Down
  delay(2000);  //wait 0.5 seconds
  Servo2.write(60);    //Move Down
  delay(2000);  //wait 0.5 seconds
  //Servo2.write(100);
  //delay(2000);  //wait 0.5 seconds
  //Servo2.write(150);
  //delay(2000);  //wait 0.5 seconds
}


