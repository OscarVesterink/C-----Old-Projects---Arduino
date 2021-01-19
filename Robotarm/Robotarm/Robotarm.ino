#include <Servo.h>

Servo servo_test;        //initialize a servo object for the connected servo 
Servo servo_1;
Servo servo_2; 
Servo servo_3;
Servo servo_4;
Servo servo_5;
               
int angle = 0; 
 
 
void setup() 
{ 
  servo_test.attach(9);      // attach the signal pin of servo to pin9 of arduino
    servo_1.attach(8);
      servo_2.attach(7);
        servo_3.attach(6);
          servo_4.attach(5);
            servo_5.attach(4);
            
} 
  
void loop() 
{ 
  for(angle = 0; angle < 180; angle += random(1,180))    // command to move from 0 degrees to 180 degrees 
  {                                  
    servo_test.write(angle);                 //command to rotate the servo to the specified angle
    delay(20);                       
  } 
 
  delay(100);
  
 for(angle = 180; angle>=1; angle-= random (1,180))     // command to move from 180 degrees to 0 degrees 
  {                                
    servo_test.write(angle);              //command to rotate the servo to the specified angle
    delay(20);                       
  } 

    delay(100);
}
