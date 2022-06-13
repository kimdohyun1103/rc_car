#include <SoftwareSerial.h>
SoftwareSerial BTSerial(12, 13);   //RX,TX

int motor1PinA  = 2  ;
int motor1PinB  = 3  ;
int enablelPin  =11 ;   
int motor2PinA  = 4  ;
int motor2PinB  = 5  ;
int enablerPin  = 10 ;  
char in;
   void setup() {
         pinMode(8, OUTPUT);
         pinMode(7, OUTPUT);
        BTSerial.begin(9600);//블루투스 통신
        Serial.begin(9600);//시리얼통신
    
        pinMode(motor1PinA, OUTPUT);
        pinMode(motor1PinB, OUTPUT);
        pinMode(motor2PinA, OUTPUT);
        pinMode(motor2PinB, OUTPUT);
        pinMode(enablerPin, OUTPUT);
        pinMode(enablelPin, OUTPUT);

        // set enablePin high so that motor can turn on:
       analogWrite(enablerPin, 250);
       analogWrite(enablelPin, 250);
       }
   void loop() {
       if (BTSerial.available())
          { in =BTSerial.read();
            Serial.write(in);
         }
         if (Serial.available()) 
          {  BTSerial.write(Serial.read());
             Serial.print("data =");
           Serial.println(in);
          }
    
    switch(in){
              
               case 'R': Right(); break; 
               case 'S': Stop(); break;
               case 'L': Left(); break;
             
             
               
               
       
             } 
      }  
void Left(){  
    // 좌
    digitalWrite(motor1PinA, LOW);
     digitalWrite(motor1PinB, LOW);
     digitalWrite(motor2PinA, LOW);
     digitalWrite(motor2PinB, HIGH);
     digitalWrite(8, HIGH);
}
void Right(){
    // 우
   digitalWrite(motor1PinA, HIGH);
     digitalWrite(motor1PinB, LOW);
     digitalWrite(motor2PinA, LOW);
     digitalWrite(motor2PinB, LOW);
     digitalWrite(7, HIGH);
}
void Stop(){
    // 정지
    digitalWrite(motor1PinA, LOW);
     digitalWrite(motor1PinB, LOW);
     digitalWrite(motor2PinA, LOW);
     digitalWrite(motor2PinB, LOW);
     digitalWrite(8, LOW);
     digitalWrite(7, LOW);

}
