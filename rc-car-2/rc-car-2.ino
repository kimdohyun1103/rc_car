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
               case 'F': Forward(); break;
               case 'R': Right(); break; 
               case 'S': Stop(); break;
               case 'L': Left(); break;
               case 'B': Back(); break;
               case 'G': ForwardLeft(); break;
               
               
       
             } 
      }  
void Forward(){  
    //  앞
    digitalWrite(motor1PinA, LOW);
     digitalWrite(motor1PinB, LOW);
     digitalWrite(motor2PinA, LOW);
     digitalWrite(motor2PinB, HIGH);
}
void Back(){  
    //  후진
    digitalWrite(motor1PinA, LOW);
     digitalWrite(motor1PinB, HIGH);
     digitalWrite(motor2PinA, HIGH);
     digitalWrite(motor2PinB, LOW);
}
void Left(){  
    // 좌
    digitalWrite(motor1PinA, LOW);
     digitalWrite(motor1PinB, LOW);
     digitalWrite(motor2PinA, LOW);
     digitalWrite(motor2PinB, HIGH);
}
void Right(){
    // 우
   digitalWrite(motor1PinA, HIGH);
     digitalWrite(motor1PinB, LOW);
     digitalWrite(motor2PinA, LOW);
     digitalWrite(motor2PinB, LOW);
}
void Stop(){
    // 정지
    digitalWrite(motor1PinA, LOW);
     digitalWrite(motor1PinB, LOW);
     digitalWrite(motor2PinA, LOW);
     digitalWrite(motor2PinB, LOW);
}
void ForwardLeft(){
    // 좌전진
 analogWrite(enablelPin, 255);
           analogWrite(enablerPin, 100);
   digitalWrite(motor1PinA, LOW);
     digitalWrite(motor1PinB, HIGH);
     digitalWrite(motor2PinA, LOW);
     digitalWrite(motor2PinB, HIGH);
         
 void ForwardRight(){
    // 우전진
 analogWrite(enablelPin, 255);
           analogWrite(enablerPin, 100);
   digitalWrite(motor1PinA, HIGH);
     digitalWrite(motor1PinB, LOW);
     digitalWrite(motor2PinA, HIGH);
     digitalWrite(motor2PinB, LOW);

}
//우전진, 좌후진, 우후진 은 아직 만들지 못함. 그래서 좌 전진만 만들었다.
