#include <Servo.h>
#include <IRremote.h>
int IR = 6 ; 
int q=0;
int i = 0;
IRrecv irrecv(IR);
decode_results results ; 
#define plus 16754775
#define minus 16769055 
#define one 16724175 // number 1 
#define two 16718055 // number 2
#define three 16743045 // number 3
#define four 16716015 // number 4
#define five 16726215 // number 5
int p=0;
int gripperState = 0;
int wristState=0;
int elbowState=0;
int shoulderState=0;
int baseState=0;
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
  case one :
  Serial.println("wrist");
  wristState = 1 ; 
  elbowState=0;
  baseState=0;
  shoulderState=0;
  break;
  case two : 
   Serial.println("elbow");
  wristState = 0 ; 
  elbowState=1;
  baseState=0;
  shoulderState=0;
    break;     
  case three : 
     Serial.println("shoulder");
  wristState = 0 ; 
  elbowState=0;
  shoulderState=1;
  baseState=0;
  
    break; 
    
   case four : 
       Serial.println("base");
  wristState = 0 ; 
  elbowState=0;
  shoulderState=0;
  baseState=1;
    break; 
// you can add more case for more remote control 

 }
 if (wristState == 1 ) {
   switch (value) {
    case plus : 
    if(wrist_angle <= 90 ){
       if ( p < 180 )  p+=10; // you can change the number of movement for angle  
       for(i = q ; i<=p; i++) {
       wrist.write(i);}
       Serial.println(i);
       q = p;
       delay(15);
    }
    break;
    case minus : 
    if(wrist_angle >= 0 && wrist_angle <180){
      if(p>=1) p-= 10; // you can change the number of movement for angle 
      for( i = q ; i>=p; i--) {
       wrist.write(i);}
       Serial.println(i);
       q = p;
       delay(15);
    }
  break ;  
   }
 }
  if (elbowState == 1 ) {
   switch (value) {
    case plus : 
    if(elbow_angle <= 90 ){
       if ( p < 180 )  p+=10; // you can change the number of movement for angle 
       for(i = q ; i<=p; i++) {
       elbow.write(i);}
       Serial.println(i);
       q = p;
       delay(15);
    }
    break;
    case minus : 
    if(elbow_angle >= 0 && elbow_angle <180){
      if(p>=1) p-= 10; // you can change the number of movement for angle 
      for( i = q ; i>=p; i--) {
       elbow.write(i);}
       Serial.println(i);
       q = p;
       delay(15);
    }
  break ;  
   }
 } if (shoulderState == 1 ) {
   switch (value) {
    case plus : 
    if(shoulder_angle <= 90 ){
       if ( p < 180 )  p+=10; // you can change the number of movement for angle 
       for(i = q ; i<=p; i++) {
       shoulder.write(i);}
       Serial.println(i);
       q = p;
       delay(15);
    }
    break;
    case minus : 
    if(shoulder_angle >= 0 && shoulder_angle <180){
      if(p>=1) p-= 10; // you can change the number of movement for angle 
      for( i = q ; i>=p; i--) {
      shoulder.write(i);}
       Serial.println(i);
       q = p;
       delay(15);
    }
  break ;  
   }
 } 
 if (baseState == 1 ) {
   switch (value) {
    case plus : 
    if(base_angle <= 90 ){
      if ( p < 180 )  p+=10;// you can change the number of movement for angle 
       for(i = q ; i<=p; i++) {
       base.write(i);}
       Serial.println(i);
       q = p;
       delay(15);
    }
    break;
    case minus : 
    if(base_angle >= 0 && base_angle <180){
      if(p>=1) p-= 10; // you can change the number of movement for angle 
      for( i = q ; i>=p; i--) {
       base.write(i);}
       Serial.println(i);
       q = p;
       delay(15);
    }
  break ;  
   }

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
