#include <Servo.h>
#include <IRremote.h>
int IR = 6 ; 
int q=0;
int i = 0;
IRrecv irrecv(IR);
decode_results results ; 
#define plus 16754775
#define minus 16769055 
int p=0;
int gripperState = 0;
Servo base ;
Servo shoulder ;
Servo elbow ;
Servo wrist ;
Servo gripper ;
double base_angle=90;
double shoulder_angle=90;
double elbow_angle=90;
double wrist_angle=90;
double gripper_angle=0;
String data;
String data1;
String data2;
String data3;
double angle1;
double angle2;
double angle3;
double angle4;
double prev_base_angle=90;
double prev_shoulder_angle=90;
double prev_elbow_angle=90;
double prev_wrist_angle=90;
void setup() {
irrecv.enableIRIn(); 
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

void loop() {

if(irrecv.decode(&results))
{
  unsigned int value = results.value;
  switch (value) {
    case plus:
    if(wrist_angle <= 90 && elbow_angle<= 90&&shoulder_angle<= 90&&base_angle <= 90 ){
       p+=10;
       for(i = q ; i<=p; i++) {
       base.write(i); 
       shoulder.write(i);
       elbow.write(i);
       wrist.write(i);}
       Serial.println(i);
       q = p;
       delay(15);
    }
    break;
    case minus:
    if(wrist_angle >= 0 && wrist_angle <180 && elbow_angle>= 0&&elbow_angle<180 && shoulder_angle>= 0&&shoulder_angle<180 &&base_angle >= 0 &&base_angle <180 ){
      p-= 10;
      for( i = q ; i>=p; i--) {
       base.write(i); 
       shoulder.write(i);
       elbow.write(i);
       wrist.write(i);}
       Serial.println(i);
       q = p;
       delay(15);
    }
    break; 
    // you can add more case for more options like number 1 or 0 ... 
    
  }
    switch (gripperState){
      case 0 :
      gripper.write(60);
      gripperState = 1;
      break;
      case 1 :
       gripper.write(0);
      gripperState = 0;
      break;
    }
  irrecv.resume(); }
}
