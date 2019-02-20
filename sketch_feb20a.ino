//Include liquid display library
//#include <LiquidCrystal.h>

//Motor one
#define in1 2
#define in2 3

//Motor two
#define in3 4
#define in4 5

//Set the pins for the ultrasonic sensor
const int trigPinRight = 9;
const int echoPinRight = 8;
const int trigPinLeft = 11;
const int echoPinLeft = 10;
const int trigPinMid = 12;
const int echoPinMid = 13;

//defines variables for ultrasonic 
long durationRight;
int distanceRight; 
long durationLeft;
int distanceLeft;
long durationMid;
int distanceMid;

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
//const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  //lcd.begin(16, 2);
  
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
  pinMode(trigPinRight, OUTPUT); //sets right trigPin as output
  pinMode(echoPinRight, INPUT); //sets right echoPin as input
  pinMode(trigPinLeft, OUTPUT);
  pinMode(echoPinLeft, INPUT);
  pinMode(trigPinMid, OUTPUT);
  pinMode(echoPinMid, INPUT);

  //Allow serial visualisation of distances
  Serial.begin(9600); //starts serial communication
}

void loop() {

  //create the Right trigPin 
  digitalWrite(trigPinRight, LOW);
  delay(10);
  
  //create the Left trigPin
  digitalWrite(trigPinLeft, LOW);
  delay(10);

  //create the middle trigPin
  digitalWrite(trigPinMid, LOW);
  delay(10);

  //sets the right trigPin on HIGH state for micro seconds
  digitalWrite(trigPinRight, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinRight, LOW); 
  
  //Reads Right echoPin, returns sound wave travel time in microseconds
  durationRight = pulseIn(echoPinRight, HIGH);

  //calculating right distance 
  distanceRight = durationRight * 0.034/2;
  
  //sets left trig pin on High state for micro seconds
  digitalWrite(trigPinLeft, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinLeft, LOW);

  //Reads left echoPin, returns sound wave travel time in microseconds
  durationLeft = pulseIn(echoPinLeft, HIGH);

  //calculating left distance 
  distanceLeft = durationLeft * 0.034/2;

  //sets the middle trigPin on HIGH state for micro seconds
  digitalWrite(trigPinMid, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinMid, LOW); 
  
  //Reads middle echoPin, returns sound wave travel time in microseconds
  durationMid = pulseIn(echoPinMid, HIGH);

  //calculating mid distance 
  distanceMid = durationMid * 0.034/2;

 if (distanceLeft < 20 && distanceRight > 20){

    //--- IF THE ROBOT SEES SOMETHING ON ITS LEFT, TURN RIGHT --- //

    //Back the robot up for 2 seconds
    // Turn off the display:
    //lcd.clear();
    //delay(500);
    // Print forward to the LCD.
    //lcd.print("Back");
    //Turn on Display
   
    
    //digitalWrite(in1, LOW);
    //digitalWrite(in2, HIGH);
    //digitalWrite(in3, LOW);
    //digitalWrite(in4, HIGH);
    //delay(500);
    
    //Rotate the robot for 1 second
    // Print forward to the LCD.
    //lcd.print("Rotate")
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(1);
  }else if (distanceLeft > 20 && distanceRight < 20){

    //--- IF THE ROBOT SEES SOMETHING ON ITS RIGHT, TURN LEFT --- //

    //Back the robot up for 2 seconds
    // Turn off the display:
    //lcd.clear();
    //delay(500);
    // Print forward to the LCD.
    //lcd.print("Back");
    //Turn on Display
   
    
    //digitalWrite(in1, LOW);
    //digitalWrite(in2, HIGH);
    //digitalWrite(in3, LOW);
    //digitalWrite(in4, HIGH);
    //delay(500);
    
    //Rotate the robot for 1 second
    // Print forward to the LCD.
    //lcd.print("Rotate")
    digitalWrite(in2, LOW);
    digitalWrite(in1, HIGH);
    digitalWrite(in4, HIGH);
    digitalWrite(in3, LOW);
    delay(1);
  }else if (distanceLeft < 20 && distanceRight < 20 && distanceMid < 40){

    //--- IF THE ROBOT SEES SOMETHING ON BOTH SIDES, BACK UP --- //

    //Back the robot up for 2 seconds
    // Turn off the display:
    //lcd.clear();
    //delay(500);
    // Print forward to the LCD.
    //lcd.print("Back");
    //Turn on Display
   
    
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    delay(200);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(1);
  }
  else {

    // --- IF THE ROBOT DOESNT SEE ANYTHING INFRONT, MOVE FORWARD --- //
    
    // Turn off the display:
    //lcd.clear();
    //delay(500);
    // Print forward to the LCD.
    //lcd.print("Forward");
    //Turn on Display
    //delay(500);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(1);
  }
}
