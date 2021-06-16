#include <Servo.h>
int p=0;
Servo base ;
Servo shoulder ;
Servo elbow ;
Servo wrist ;
Servo gripper ;
void setup() {
Serial.begin(9600);
delay(50);
base.attach(8); 
shoulder.attach(9);
elbow.attach(10);
wrist.attach(11);
gripper.attach(12);
base.write(0); // initial point for all motors
shoulder.write(0);
elbow.write(0);
wrist.write(0);
gripper.write(0);

}

void loop() {
for(p=0 ; p<90 ; p++ ){
  base.write(p);
  shoulder.write(p);
  elbow.write(p);
  wrist.write(p);
  gripper.write(p);
  delay(15);

}
for(p=90 ; p>=1 ; p-- ){
  base.write(p);
  shoulder.write(p);
  elbow.write(p);
  wrist.write(p);
  gripper.write(p);
  delay(15);

  }
}
