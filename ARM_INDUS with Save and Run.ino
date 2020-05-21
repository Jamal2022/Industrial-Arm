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
// for storing positions/steps
int servo01SP[50], servo02SP[50], servo03SP[50], servo04SP[50], servo05SP[50], servo06SP[50]; 
// Speed
int speedDelay = 50;
// Index
int index = 0;
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
      case 's':
        Serial.println("Save");
        save();
        inSerial[0]='z';
        break;
      case 'v':
        Serial.println("Run");
        runarm();
        inSerial[0]='z';
        break;
      case 't':
        Serial.println("Reset");
        reset();
        inSerial[0]='z';
        break;
 }    
}
void save(){
  // save position into the array
  servo01SP[index] = servo1PPos;  
  Serial.println(servo1PPos);
  servo02SP[index] = servo2PPos;
  Serial.println(servo2PPos);
  servo03SP[index] = servo3PPos;
  Serial.println(servo3PPos);
  servo04SP[index] = servo4PPos;
  Serial.println(servo4PPos);
  servo05SP[index] = servo5PPos;
  Serial.println(servo5PPos);
  servo06SP[index] = servo6PPos;
  Serial.println(servo6PPos);
  index++;   
  }
void reset(){
  // Clear the array data to 0
  memset(servo01SP, 0, sizeof(servo01SP));
  memset(servo02SP, 0, sizeof(servo02SP));
  memset(servo03SP, 0, sizeof(servo03SP));
  memset(servo04SP, 0, sizeof(servo04SP));
  memset(servo05SP, 0, sizeof(servo05SP));
  memset(servo06SP, 0, sizeof(servo06SP));
  index = 0;
  }
void runarm(){
  int l=0;
  while (inSerial[0]!='t'){//Reset
    
    for (int i=0 ; i<index-1 ; i++ ){
      if (Serial.available() > 0) {
        inSerial[l]=Serial.read();
        l++;  
        }
      inSerial[l]='\0';
      if ( inSerial[0]=='p'){//Pause
        l=0;
        while ( inSerial[0]!='v'){//RUN
           if (Serial.available() > 0) {
              inSerial[l]=Serial.read(); 
           }
           inSerial[l+1]='\0';
           if ( inSerial[0]=='t'){//Reset
              break;
           }
        }
      }
      //SERVO1
      Serial.println(servo01SP[i]);
      if (servo01SP[i] == servo01SP[i + 1]) {
      }
      if (servo01SP[i] > servo01SP[i + 1]) {
        for ( int j = servo01SP[i]; j >= servo01SP[i + 1]; j--) {
          servo01.write(j);
          delay(speedDelay);
        }
      }
      if (servo01SP[i] < servo01SP[i + 1]) {
        for ( int j = servo01SP[i]; j <= servo01SP[i + 1]; j++) {
          servo01.write(j);
          delay(speedDelay);
        }
      }
      // SERVO2
      Serial.println(servo02SP[i]);
      if (servo02SP[i] == servo02SP[i + 1]) {
      }
      if (servo02SP[i] > servo02SP[i + 1]) {
        for ( int j = servo02SP[i]; j >= servo02SP[i + 1]; j--) {
          servo02.write(j);
          delay(speedDelay);
        }
      }
      if (servo02SP[i] < servo02SP[i + 1]) {
        for ( int j = servo02SP[i]; j <= servo02SP[i + 1]; j++) {
          servo02.write(j);
          delay(speedDelay);
        }
      }
      //SERVO3
      Serial.println(servo03SP[i]);
      if (servo03SP[i] == servo03SP[i + 1]) {
      }
      if (servo03SP[i] > servo03SP[i + 1]) {
        for ( int j = servo03SP[i]; j >= servo03SP[i + 1]; j--) {
          servo03.write(j);
          delay(speedDelay);
        }
      }
      if (servo03SP[i] < servo03SP[i + 1]) {
        for ( int j = servo03SP[i]; j <= servo03SP[i + 1]; j++) {
          servo03.write(j);
          delay(speedDelay);
        }
      }
      //SERVO4
      Serial.println(servo04SP[i]);
      if (servo04SP[i] == servo04SP[i + 1]) {
      }
      if (servo04SP[i] > servo04SP[i + 1]) {
        for ( int j = servo04SP[i]; j >= servo04SP[i + 1]; j--) {
          servo04.write(j);
          delay(speedDelay);
        }
      }
      if (servo04SP[i] < servo04SP[i + 1]) {
        for ( int j = servo04SP[i]; j <= servo04SP[i + 1]; j++) {
          servo04.write(j);
          delay(speedDelay);
        }
      }
      //SERVO5
      Serial.println(servo05SP[i]);
      if (servo05SP[i] == servo05SP[i + 1]) {
      }
      if (servo05SP[i] > servo05SP[i + 1]) {
        for ( int j = servo05SP[i]; j >= servo05SP[i + 1]; j--) {
          servo05.write(j);
          delay(speedDelay);
        }
      }
      if (servo05SP[i] < servo05SP[i + 1]) {
        for ( int j = servo05SP[i]; j <= servo05SP[i + 1]; j++) {
          servo05.write(j);
          delay(speedDelay);
        }
      }
      //SERVO6
      Serial.println(servo06SP[i]);
      if (servo06SP[i] == servo06SP[i + 1]) {
      }
      if (servo06SP[i] > servo06SP[i + 1]) {
        for ( int j = servo06SP[i]; j >= servo06SP[i + 1]; j--) {
          servo06.write(j);
          delay(speedDelay);
        }
      }
      if (servo06SP[i] < servo06SP[i + 1]) {
        for ( int j = servo06SP[i]; j <= servo06SP[i + 1]; j++) {
          servo06.write(j);
          delay(speedDelay);
        }
      }   
   }
  }
 }
