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
//좌회전일때 왼쪽에 있는 Led가 켜지고 우회전일때 오른쪽에 있는 Led가 켜진다. 아두이노 7번 8번에 수수 점퍼선을 연결하고
//그것을 GND하나와 저항 두개를 연결하여 LED를 연결하였다. 그다음 (좌)에 loop에 digitalWrite(8, HIGH); (우)에 digitalWrite(7, HIGH); 로 불이 들어오게 하고
//(정지) 에는 digitalWrite(7, LOW); 그리고 digitalWrite(8, LOW);를 하여 불이 꺼지도록 만들었다.
//그렇게 하고 블루투스와 연결하여, 아두이노 rc카 블루투스 프로그램에서 왼쪽 버튼을 누르면 왼쪽LED가 켜지고 오른쪽버튼을 누르면 오른쪽 LED가 켜지게 프로그래밍했다.

//느낀점
//미션을 받아 아무도움도 받지 않고 혼자 프로그래밍을 해보는 경험이 처음이어서 하나도 못할것 이라고 생각했지만 30분만에 3등으로 미션을 완료했다. 
//아두이노라는 프로그램을 처음사용해 보는데 서로 다른 코딩 두개를 연결하는 법에 대해서도 숙련되고, 회로를 연결하는 방법에 대해서도 숙련되어서 성장한 느낌이 들고,
//나의 힘으로만 회로를 연결하고 코딩을 했다는사실이 자랑스럽고 감격스럽다.
