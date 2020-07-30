#include <Servo.h>
Servo motor;
const int trigger=13,echo=11; //pin for sensor
const int angle_of_small_boxes =0 ;
const int angle_of_medium_boxes = 90;
const int angle_of_large_boxes = 180;
void setup() {
  // put your setup code here, to run once:
motor.attach(3);
pinMode(trigger,OUTPUT);
pinMode(echo,INPUT);
Serial.begin(9600);
  motor.write(90);



}

void loop() {
long duration=0; //duration of the pulse
float distance=0; //distance
digitalWrite(trigger,LOW);
delayMicroseconds(10);

digitalWrite(trigger,HIGH);
delayMicroseconds(5);
digitalWrite(trigger,LOW);

duration=pulseIn(echo,HIGH);
// determine the distance in cm
distance =duration / 58.8; 
Serial.print(distance);
 Serial.println("cm");

// for small boxes
if (distance<300 && distance>200) {
  motor.write(angle_of_small_boxes);
  delay(1000);
  motor.write(90);
   delay(1000);

  }
  // for medium boxes
  else if (distance<199 && distance>100){
    motor.write(angle_of_medium_boxes);
    delay(1000);
    motor.write(90);
    delay(1000);

    }
  //for large boxes
    else if (distance<99 && distance>0){
      motor.write(angle_of_large_boxes);
      delay(1000);
      motor.write(90);
      delay(1000);

      }
}