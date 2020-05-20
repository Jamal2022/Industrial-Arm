/*
 * Created on Tue May 19 22:50:32 2020
 * @author: Jamal Ali
 * Github : Jamal2022
 * Gmail : jamalabdu213@gmail.com
 */

#include <Servo.h>
//Bluetooth
int tx=1;
int rx=0;
char inSerial[15];
//Servo
Servo servo01;
Servo servo02;
Servo servo03;
Servo servo04;
Servo servo05;
Servo servo06;
// current position
int servo6Pos=30; //servo6
int servo5Pos=75; //servo5
int servo4Pos=120; //servo4
int servo3Pos=75;//servo3
int servo2Pos=140; //servo2
int servo1Pos=0;//servo1
// previous position
int servo1PPos, servo2PPos, servo3PPos, servo4PPos, servo5PPos, servo6PPos;
// Speed
int speedDelay = 50;

void setup() {
  //Servo
  servo01.attach(5);
  servo02.attach(6);
  servo03.attach(7);
  servo04.attach(8);
  servo05.attach(9);
  servo06.attach(10);
  Serial.begin(9600);
  
  //Bleutooth
  pinMode(tx, OUTPUT);
  pinMode(rx, INPUT);
  
  // Robot arm initial position
  servo1PPos = 0;
  servo01.write(servo1PPos);
  servo2PPos = 140;
  servo02.write(servo2PPos);
  servo3PPos = 75;
  servo03.write(servo3PPos);
  servo4PPos = 120;
  servo04.write(servo4PPos);
  servo5PPos = 75;
  servo05.write(servo5PPos);
  servo6PPos = 30;
  servo06.write(servo6PPos);

}

void loop() {
  int i=0;
  delay(speedDelay);
  if (Serial.available() > 0) {
    inSerial[i]=Serial.read();
    i++;
    inSerial[i]='\0';}
  switch (inSerial[0])
    {
      case 'r':
        Serial.println("S6+");
        servo6Pos=servo6Pos+1;
        servo06.write(servo6Pos);
        servo6PPos=servo6Pos;
        break;
      
      case 'g':
        Serial.println("S6-");
        servo6Pos=servo6Pos-1;
        servo06.write(servo6Pos);
        servo6PPos=servo6Pos;
        break;
      
      case 'h':
        Serial.println("S5+");
        servo5Pos=servo5Pos+1;
        servo05.write(servo5Pos); 
        servo5PPos=servo5Pos;
        break;
      
      case 'i':
        Serial.println("S5-");
        servo5Pos=servo5Pos-1;
        servo05.write(servo5Pos);
        servo5PPos=servo5Pos;
        break;
  
      case 'n':
        Serial.println("S4+");
        servo4Pos=servo4Pos+1;
        servo04.write(servo4Pos);
        servo4PPos=servo4Pos;
        break;
        
      case 'u':
        Serial.println("S4-");
        servo4Pos=servo4Pos-1;
        servo04.write(servo4Pos);
        servo4PPos=servo4Pos;
        break;
        
      case 'o':
        Serial.println("S3+");
        servo3Pos=servo3Pos+1;
        servo03.write(servo3Pos);
        servo3PPos=servo3Pos; 
        break;
        
      case 'd':
        Serial.println("S3-");
        servo3Pos=servo3Pos-1;
        servo03.write(servo3Pos); 
        servo3PPos=servo3Pos;
        break;
        
      case 'l':
        Serial.println("S2+");
        servo2Pos=servo2Pos+1;
        servo02.write(servo2Pos);
        servo2PPos=servo2Pos;
        break;
      case 'm':
        Serial.println("S2-");
        servo2Pos=servo2Pos-1;
        servo02.write(servo2Pos);
        servo2PPos=servo2Pos;
        break;
      case 'a':
        Serial.println("S1+");
        servo1Pos=servo1Pos+5;
        servo01.write(servo1Pos);
        servo1PPos=servo1Pos;
        break;
      case 'j':
        Serial.println("S1-");
        servo1Pos=servo1Pos-1;
        servo01.write(servo1Pos);
        servo1PPos=servo1Pos;
        break;
 }    
}
