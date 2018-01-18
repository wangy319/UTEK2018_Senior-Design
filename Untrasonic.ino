
#include <NewPing.h>
//#include <Servo.h>

// define pins and other constants

const int trigPin = 11;
const int echoPin = 2;
const int max_distance = 300;

// variables to use later on
int dist;

// create instances of servo and ping class
//Servo Servo1;
//Servo Servo2;
NewPing sonar(trigPin, echoPin, max_distance);

void setup()
{
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
//  Servo1.attach(servo1Pin);   // connect servo to pin 3
//  Servo2.attach(servo2Pin);   // connect servo to pin 4
}

void loop()
{
  Serial.print("Ping: ");
  dist = sonar.ping_cm();  
  Serial.print(dist);
  Serial.println("cm");
  delay(200);
  /*
  Servo1.write(0);
  delay(500);  //wait 0.5 seconds
  Servo1.write(30);
  delay(500);  //wait 0.5 seconds
  Servo1.write(-30);
  delay(500);  //wait 0.5 seconds
  Servo2.write(90);
  delay(5000);  //wait 0.5 seconds
  Servo2.write(100);
  delay(2000);  //wait 0.5 seconds
  //Servo2.write(150);
  //delay(2000);  //wait 0.5 seconds
  */
}


