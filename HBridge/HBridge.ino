//Motor one
#define in1 2
#define in2 3

//Motor two
#define in3 4
#define in4 5

//Set the pins for the ultrasonic sensor
const int trigPin = 9;
const int echoPin = 8;

//defines variables for ultrasonic 
long duration;
int distance; 

void setup() {
  //Set motor pins to output
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  //Set initial rotation direction
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  //Setup ultrasonic sensor pins
  pinMode(trigPin, OUTPUT); //sets trigPin as output
  pinMode(echoPin, INPUT); //sets echoPin as input

  //Allow serial visualisation of distances
  Serial.begin(9600); //starts serial communication
}

void loop() {

  //create the trigPin 
  digitalWrite(trigPin, LOW);
  delay(10);

  //sets the trigPin on HIGH state for micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); 

  //Reads echoPin, returns sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  //calculating distance 
  distance = duration * 0.034/2;

  //Prints distance on Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");

  //Go forward if nothing infront
  if (distance > 10) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(20);
  }else{
    //Back the robot up for 2 seconds
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(500);
    //Rotate the robot for 1 second
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(250);
  }
}
