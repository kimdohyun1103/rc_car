// A 바퀴만 움직임         step1-1-1-rc-motor1-front로 저장

int motor1PinA  = 2 ;
int motor1PinB =  3 ;
int enablelPin= 11 ; 
int motor2PinA  = 4 ;
int motor2PinB =  5 ;
int enable2Pin= 10 ; 

  void setup() {
     pinMode(motor1PinA, OUTPUT);     
     pinMode(motor1PinB, OUTPUT);
     pinMode(enablelPin, OUTPUT);
     analogWrite(enablelPin, 100);//모터속도를 정해준다
     pinMode(motor2PinA, OUTPUT);     
     pinMode(motor2PinB, OUTPUT);
     pinMode(enable2Pin, OUTPUT);
     analogWrite(enable2Pin, 100);//모터속도를 정해준다
  }

void loop() {
     digitalWrite(motor1PinA, HIGH); // 전진
     digitalWrite(motor1PinB, LOW);
     digitalWrite(motor2PinA, LOW);
     digitalWrite(motor2PinB, HIGH);
     delay(1000);
  
     digitalWrite(motor1PinA, LOW); // 후진
     digitalWrite(motor1PinB, HIGH);
     digitalWrite(motor2PinA, HIGH);
     digitalWrite(motor2PinB, LOW);
     delay(1000);

     digitalWrite(motor1PinA, LOW); // 좌회전
     digitalWrite(motor1PinB, LOW);
     digitalWrite(motor2PinA, LOW);
     digitalWrite(motor2PinB, HIGH);
     delay(1000);

     digitalWrite(motor1PinA, HIGH); // 우회전
     digitalWrite(motor1PinB, LOW);
     digitalWrite(motor2PinA, LOW);
     digitalWrite(motor2PinB, LOW);
     delay(1000);

     digitalWrite(motor1PinA, LOW); // 정지
     digitalWrite(motor1PinB, LOW);
     digitalWrite(motor2PinA, LOW);
     digitalWrite(motor2PinB, LOW);
     delay(10000);
     }
