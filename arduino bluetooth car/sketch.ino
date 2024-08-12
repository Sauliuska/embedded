#include <SoftwareSerial.h>
int drivingMode = 0;
const int stepSpeed = 25;
int speed = drivingMode * stepSpeed;
int IN1 = 11;
int IN2 = 10;
int IN3 = 9;
int IN4 = 6;
int backLightPin = 13;
int frontLightPin1 = 4;
int frontLightPin2 = 7;
bool  m = false;
bool frontLightsOn = false;

void stop();
void speed_configuration();
void move_forward();
void move_backward();
void move_forward_left();
void move_forward_right();

SoftwareSerial BTSerial(2, 3);// bluetooth komunikacija

char input;

void setup() {
  // pinMode(4, OUTPUT); // jungiam norint keisti bluetooth moduli
  // digitalWrite(4, HIGH);
  pinMode(backLightPin, OUTPUT);
  pinMode(frontLightPin1, OUTPUT);
  pinMode(frontLightPin2, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter AT Commands:");
  BTSerial.begin(9600);
}

void loop() {

  if(BTSerial.available()){
    input = BTSerial.read();
    Serial.write(input);
    Serial.println();
  }
  if(input == 'F'){
    move_forward();
  }
  else if(input == 'B'){
    move_backward();
  }
  else if(input == 'G'){
    move_forward_left();
  }
  else if(input == 'I'){
    move_forward_right();
  }
  else if(input == 'L'){
    move_left();
  }
  else if(input == 'R'){
    move_right();
  }
  else if(input == 'W'){
    digitalWrite(frontLightPin1, HIGH);
    digitalWrite(frontLightPin2, HIGH);
  }
  else if(input == 'w'){
    digitalWrite(frontLightPin1, LOW);
    digitalWrite(frontLightPin2, LOW);
  }
  else if(input == 'U'){
    digitalWrite(backLightPin, HIGH);
  }
  else if(input == 'u'){
    digitalWrite(backLightPin, LOW);
  }
  else if(input == '0'){
    drivingMode = 0;
    speed_configuration();
  }
  else if(input == '1'){
    drivingMode = 1;
    speed_configuration();
  }
  else if(input == '2'){
    drivingMode = 2;
    speed_configuration();
  }
  else if(input == '3'){
    drivingMode = 3;
    speed_configuration();
  }
  else if(input == '4'){
    drivingMode = 4;
    speed_configuration();
  }
  else if(input == '5'){
    drivingMode = 5;
    speed_configuration();
  }
  else if(input == '6'){
    drivingMode = 6;
    speed_configuration();
  }
  else if(input == '7'){
    drivingMode = 7;
    speed_configuration();
  }
  else if(input == '8'){
    drivingMode = 8;
    speed_configuration();
  }
  else if(input == 9){
    drivingMode = 9;
    speed_configuration();
  }
  else if(input == 'q'){
    drivingMode = 10;
    speed = 255;
  }
  else if(input == 'S'){
    stop();
    Serial.write("stopped");
  }
}

void move_forward(){
  analogWrite(IN1, speed);
  analogWrite(IN2, 0);
  analogWrite(IN3, speed);
  analogWrite(IN4, 0);
}

void move_backward(){
  analogWrite(IN1, 0);
  analogWrite(IN2, speed);
  analogWrite(IN3, 0);
  analogWrite(IN4, speed);
}

void move_forward_left(){
  analogWrite(IN1, 0);
  analogWrite(IN2, speed);
  analogWrite(IN3, speed);
  analogWrite(IN4, 0);
}

void move_forward_right(){
  analogWrite(IN1, speed);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, speed);
}

void move_left(){
  move_forward_left();
}

void move_right(){
  move_forward_right();
}

void speed_configuration(){
  speed = drivingMode * stepSpeed;
}

void stop(){
  analogWrite(IN1, 0);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, 0);  
}
