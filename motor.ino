// connect motor controller pins to Arduino digital pins
// motor one
//int enA = 10;
int in1 = 9;
int in2 = 8;
// motor two
int in3 = 7;
int in4 = 6;   

//Color Sensor pin setup
#define S0 10
#define S1 11
#define S2 12
#define S3 13
#define sensorOut 5

void setup()
{
  // set all the motor control pins to outputs
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  //Color sensor Set up
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  Serial.begin(9600);
  
}

void demoOne()
{
  // this function will run the motors in both directions at a fixed speed

  // now change motor directions
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  delay(300);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW); 
  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW); 
  delay(300);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW); 
  
}


void loop()
{
  demoOne();
  
//  demoTwo();
//  delay(1000);
}
