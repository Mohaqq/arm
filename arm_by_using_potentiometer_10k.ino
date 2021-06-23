

#include <Servo.h>
#define pot1 A0
#define pot2 A1
#define pot3 A2
#define pot4 A3
#define pot5 A4
double v=0;
double v2=0;
double v3=0;
double v4=0;
double v5=0;
Servo base ;
Servo shoulder ;
Servo elbow ;
Servo wrist ;
Servo gripper ;



void setup()
{
  Serial.begin(9600);
delay(50);
base.attach(8); 
shoulder.attach(9);
elbow.attach(10);
wrist.attach(11);
gripper.attach(12);
base.write(90); // initial point for all motors
shoulder.write(90);
elbow.write(90);
wrist.write(90);
gripper.write(0);

}

void loop()
{
 
  v = analogRead(pot1);
  v = map(v,0,1023,0,90);
  gripper.write(v);
  Serial.println(v);
  delay(15);
   v2 = analogRead(pot2);
    v2 = map(v2,0,1023,0,90);
    wrist.write(v2);
    Serial.println(v2);
      delay(15);
   v3= analogRead(pot3);
    v3 = map(v3,0,1023,0,90);
    elbow.write(v3);
    Serial.println(v3);
      delay(15);
   v4 = analogRead(pot4);
    v4 = map(v4,0,1023,0,90);
    shoulder.write(v4);
    Serial.println(v4);
      delay(15);
   v5 = analogRead(pot5);
    v5 = map(v5,0,1023,0,90);
    base.write(v5);
    Serial.println(v5);
      delay(15);

}
