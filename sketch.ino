//Fabiolus
//the_fabiolous@hotmail.com
//2020/08/27


const int A1A = 2;//define pin 2 for A1A
const int A1B = 3;//define pin 3 for A1B

const int B1A = 4;//define pin 8 for B1A
const int B1B = 5;//define pin 9 for B1B

// Speed control potentiometers
int SpeedControl = A2;

// Motor Speed Values - Start at zero
int MotorSpeed1 = 0;
int MotorSpeed2 = 0;

// Define Joystick Connections
#define joyX A0
#define joyY A1

int joyposX = 512;
int joyposY = 512;


void setup() {
Serial.begin(9600);
  pinMode(B1A, OUTPUT); // define pin as output
  pinMode(B1B, OUTPUT);
  pinMode(A1A, OUTPUT);
  pinMode(A1B, OUTPUT);
  digitalWrite(B1A, LOW);
  digitalWrite(B1B, LOW);
  digitalWrite(A1A, LOW);
  digitalWrite(A1B, LOW);

  //Initializng the joystick pins as input
  //pinMode (x_key, INPUT) ;
  //pinMode (y_key, INPUT) ;

  delay(3000);
}

void loop() {
  // put your main code here, to run repeatedly:

// joyposX = analogRead(joyX);
 // joyposY = analogRead(joyY);

    joyposX = analogRead(joyX);
  joyposY = analogRead(joyY);
  MotorSpeed1 = analogRead(SpeedControl);
  MotorSpeed2 = analogRead(SpeedControl);

  //Serial.print("X : ");
  //Serial.println(joyposX);
  //Serial.print("Y : ");
  Serial.println(joyposY);
  //Serial.print("potValue : ");
  //Serial.println(data.potValue);
  delay(10);

  if (joyposX > 510)
  {

    // This is BACWARD
    MotorSpeed1 = map(MotorSpeed1, 0, 1023, 0, 255);
    MotorSpeed2 = map(MotorSpeed2, 0, 1023, 0, 255);
    digitalWrite(A1A, HIGH);
    analogWrite(A1B, MotorSpeed1);
    digitalWrite(B1A, HIGH);
    analogWrite(B1B, MotorSpeed2);


  }

  else if (joyposX < 480)
  {

    // This is FORWARD
    MotorSpeed1 = map(MotorSpeed1, 0, 1023, 0, 255);
    MotorSpeed2 = map(MotorSpeed2, 0, 1023, 0, 255);
    digitalWrite(A1A, LOW);
    analogWrite(A1B, 255 - MotorSpeed1);
    digitalWrite(B1A, LOW);
    analogWrite(B1B, 255 - MotorSpeed2);

  }

  else if (joyposY < 480)
  {
    // This is right
    MotorSpeed1 = map(MotorSpeed1, 0, 1023, 0, 255);
    MotorSpeed2 = map(MotorSpeed2, 0, 1023, 0, 255);
    digitalWrite(A1A, LOW);
    analogWrite(A1B, 255 - MotorSpeed1);
    digitalWrite(B1A, HIGH);
    analogWrite(B1B, MotorSpeed2);

  }

  else if (joyposY > 520)
  {

    // This is right
    MotorSpeed1 = map(MotorSpeed1, 0, 1023, 0, 255);
    MotorSpeed2 = map(MotorSpeed2, 0, 1023, 0, 255);
    digitalWrite(A1A, HIGH);
    analogWrite(A1B, MotorSpeed1);
    digitalWrite(B1A, LOW);
    analogWrite(B1B, 255 - MotorSpeed2);

  }

  else
  {
    digitalWrite(B1A, LOW);
    digitalWrite(B1B, LOW);
    digitalWrite(A1A, LOW);
    digitalWrite(A1B, LOW);

  }

}
