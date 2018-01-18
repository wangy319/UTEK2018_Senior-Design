
#include <NewPing.h>
#include <Servo.h>
int r = 0, y = 0, p = 0;
int c;
int cup1, cup2, cup3;
int history[6][1];      //First row is color, the second row is distance

// connect motor controller pins to Arduino digital pins
// motor one
int in1 = 9;
int in2 = 8;
// motor two
int in3 = 7;
int in4 = 6;
//Servo
const int servo1Pin = 3;
const int servo2Pin = 4;

//Color Sensor pin setup
#define S0 10
//#define S1 11
#define S2 13
#define S3 12
#define sensorOut 5

int frequency = 0;

//Untrasonic sensor pin define pins and other constants
const int trigPin = 11;
const int echoPin = 2;
const int max_distance = 300;

// variables to use later on
int dist;
int angle;

// create instances of servo and ping class
Servo Servo1;
Servo Servo2;
NewPing sonar(trigPin, echoPin, max_distance);

//Color Sensor 
int get_color() {
  int color;
  int R = get_R();
  int G = get_G();
  int B = get_B();
  if(R>=50){
    color = 0;    //Black
  }else{
    if(G>35){
      color = 1;  //Red
      r = r+1;
    }else if(B<20){
      color = 3;  //Pink
      p = p+1;
    }else{
      color = 2;  //Yellow
      y = y+1;
    } 
  }
  return color;
}

int get_R(){
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  int avg = 0;

  int i;
  for(i=0; i<=5;i++){
    // Reading the output frequency
    frequency = pulseIn(sensorOut, LOW);
    delay(50);
    avg = avg + frequency;
  }
  avg = round(avg/5);
  
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
    
  return avg;
}

int get_G(){
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  int avg = 0;
  int i = 0;
  for(i=0; i<=5;i++){
    // Reading the output frequency
    frequency = pulseIn(sensorOut, LOW);
    delay(50);
    avg = avg + frequency;
  }
  avg = round(avg/5);

  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  
  return avg;
}

int get_B(){
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
  int avg = 0;
  int i = 0;
  for(i=0; i<=5;i++){
    // Reading the output frequency
    frequency = pulseIn(sensorOut, LOW);
    delay(50);
    avg = avg + frequency;
  }
  avg = round(avg/5);
  
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
    
  return avg;
}

void stop_car(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void forward(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(300);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(300);
}

void backward(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(300);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(300);
}

void s2_move(int k){
  if(history[k][0] == cup1){
    Servo2.write(0);
    delay(100);
    Servo2.write(90);
  }else if(history[k][0] == cup3){
    Servo2.write(180);
    delay(100);
    Servo2.write(90);
  }else{
    Servo2.write(90);
  }
}



/*--------------------------------------------------------------------*/
void demo()
{
  //Initially the speed of the car is zero
  stop_car();
  delay(500); //10s
  
  //Forward
  forward();

  dist = sonar.ping_cm();
  
  while (dist >=80){      //Use Ultraonic sensor to determine candy position
    //STOP the car
    forward();
    Serial.print("Ping: ");
    dist = sonar.ping_cm();  
    Serial.print(dist);
    Serial.println("cm");
    delay(100);
  }
  //Get Color
  stop_car();
  c = get_color();    //0 = Black, 1 = Red, 2 = Yello, 3 = Pink
  history[0][0] = c;
  history[0][1] = dist;      

  while (dist >=68){      //Use Ultraonic sensor to determine candy position
    //STOP the car
    forward();
    Serial.print("Ping: ");
    dist = sonar.ping_cm();  
    Serial.print(dist);
    Serial.println("cm");
    delay(100);
  }
  //Get Color
  stop_car();
  c = get_color();    //0 = Black, 1 = Red, 2 = Yello, 3 = Pink
  history[0][0] = c;
  history[0][1] = dist;      
  //Forward
  forward();
  
  while (dist >=56){      //Use Ultraonic sensor to determine candy position
    //STOP the car
    forward();
    Serial.print("Ping: ");
    dist = sonar.ping_cm();  
    Serial.print(dist);
    Serial.println("cm");
    delay(100);
  }
  //Get Color
  stop_car();
  c = get_color();    //0 = Black, 1 = Red, 2 = Yello, 3 = Pink
  history[0][0] = c;
  history[0][1] = dist;      
  //Forward
  forward();
  
  while (dist >=44){      //Use Ultraonic sensor to determine candy position
    //STOP the car
    forward();
    Serial.print("Ping: ");
    dist = sonar.ping_cm();  
    Serial.print(dist);
    Serial.println("cm");
    delay(100);
  }
  //Get Color
  stop_car();
  c = get_color();    //0 = Black, 1 = Red, 2 = Yello, 3 = Pink
  history[0][0] = c;
  history[0][1] = dist;      
  //Forward
  forward();
  
  while (dist >=32){      //Use Ultraonic sensor to determine candy position
    //STOP the car
    forward();
    Serial.print("Ping: ");
    dist = sonar.ping_cm();  
    Serial.print(dist);
    Serial.println("cm");
    delay(100);
  }
  //Get Color
  stop_car();
  c = get_color();    //0 = Black, 1 = Red, 2 = Yello, 3 = Pink
  history[0][0] = c;
  history[0][1] = dist;      
  //Forward
  forward();

  while (dist >=20){      //Use Ultraonic sensor to determine candy position
    //STOP the car
    forward();
    Serial.print("Ping: ");
    dist = sonar.ping_cm();  
    Serial.print(dist);
    Serial.println("cm");
    delay(100);
  }
  //Get Color
  stop_car();
  c = get_color();    //0 = Black, 1 = Red, 2 = Yello, 3 = Pink
  history[0][0] = c;
  history[0][1] = dist;      
  //Forward
  forward();
  
  while (dist >=8){      //Use Ultraonic sensor to determine candy position
    //STOP the car
    forward();
    Serial.print("Ping: ");
    dist = sonar.ping_cm();  
    Serial.print(dist);
    Serial.println("cm");
    delay(100);
  }
  //Get Color
  stop_car();
  c = get_color();    //0 = Black, 1 = Red, 2 = Yello, 3 = Pink
  history[0][0] = c;
  history[0][1] = dist;      
  //Forward
  forward();
   
  //List is finished

  //Define the cup number

  if(r>y){
    if(r>p){
      cup1 = 1;
    }else{
      cup1 = 3;
    }
  }else{      //r<y
    if(p<y){
      cup1 = 2;  //y
    }else{
      cup1 = 3; //p 
    }
  }

  if(r<y){
    if(r<p){
      cup3 = 1;  //r
    }else{
      cup3 = 3;    //p
    }
  }else{      //r<y
    if(p<y){
      cup3 = 3;  //p
    }else{
      cup3 = 2; //y
    }
  }

  cup2 = 1;
  if(cup2 == cup1 || cup2 == cup3){
    cup2 = 2;
    if(cup2 == cup1 || cup2 == cup3){
      cup2 = 3;
    }
  }
  
  //Go back to the 4th candy
  dist = sonar.ping_cm(); 
  while (dist<=history[3][1]){
    backward();
  }
  stop_car();

  //Start moving candies
  //Board move down
  Servo1.write(180);
  s2_move(3);

  dist = sonar.ping_cm(); 
  while (dist<=history[2][1]){
    backward();
  }
  stop_car();
  //Start moving candies
  s2_move(2);

  dist = sonar.ping_cm(); 
  while (dist<=history[1][1]){
    backward();
  }
  stop_car();
  //Start moving candies
  s2_move(1);

  dist = sonar.ping_cm(); 
  while (dist<=history[0][1]){
    backward();
  }
  stop_car();
  //Start moving candies
  s2_move(0);

  //get out candies
  dist = sonar.ping_cm(); 
  while (dist<=90){
    backward();
  }
  stop_car();

  //Board move up
  Servo1.write(90);
  
  //Go back to the 7th candy
  dist = sonar.ping_cm(); 
  while (dist>=history[6][1]){
    forward();
  }
  stop_car();

  //Start moving candies
  //Board move down
  Servo1.write(180);
  s2_move(6);

  dist = sonar.ping_cm(); 
  while (dist<=history[5][1]){
    backward();
  }
  stop_car();
  //Start moving candies
  s2_move(5);

  dist = sonar.ping_cm(); 
  while (dist<=history[4][1]){
    backward();
  }
  stop_car();
  //Start moving candies
  s2_move(4);

  //get out candies
  dist = sonar.ping_cm(); 
  while (dist<=90){
    backward();
  }
  stop_car();
}

void setup()
{

  // set all the motor control pins to outputs
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  //Color sensor Set up
  pinMode(S0, OUTPUT);
  //pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  //digitalWrite(S1,LOW);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  
  Servo1.attach(servo1Pin);   // connect servo to pin 3
  Servo2.attach(servo2Pin);   // connect servo to pin 4

  Serial.begin(9600); // Starts the serial communication
}



void loop()
{
  //Initialization
  Servo1.write(90);
  Servo2.write(90);
  
  demo();
  delay(1000);

}
