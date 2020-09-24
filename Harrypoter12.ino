#include <SoftwareSerial.h>

#define Xendstop 8
#define Yendstop 9
#define Zendstop 10
#define XdirPin 2
#define XstepPin 3
#define YdirPin 4
#define YstepPin 5
#define ZdirPin 6
#define ZstepPin 7
#define garo 300
#define deagak 425
#define Zmove 200
#define Xcenter 600
#define Ycenter 600
#define Zcenter 200
#define stepinfinity 9999999999
#define XMotorLeft digitalWrite(XdirPin, HIGH); // X모터 반시계 x+
#define XMotorRight digitalWrite(XdirPin, LOW); // X모터 시계 x-
#define YMotorLeft digitalWrite(YdirPin, HIGH); // Y모터 반시계 y+
#define YMotorRight digitalWrite(YdirPin, LOW); // Y모터 시계 y-
#define ZMotorUp digitalWrite(ZdirPin, HIGH); // Z모터 상승 z+
#define ZMotorDown digitalWrite(ZdirPin, LOW); // Z모터 하강 z-
#define XYMotorLeft digitalWrite(XdirPin, HIGH);digitalWrite(YdirPin, HIGH);
#define XYMotorRight digitalWrite(XdirPin, LOW);digitalWrite(YdirPin, LOW);
#define XYMotorLeftRight digitalWrite(XdirPin, HIGH);digitalWrite(YdirPin, LOW);
#define XYMotorRightLeft digitalWrite(XdirPin, LOW);digitalWrite(YdirPin, HIGH);
#define XMotorMove digitalWrite(XstepPin, HIGH);delayMicroseconds(2000);digitalWrite(XstepPin, LOW);delayMicroseconds(2000);
#define YMotorMove digitalWrite(YstepPin, HIGH);delayMicroseconds(3000);digitalWrite(YstepPin, LOW);delayMicroseconds(3000);
#define ZMotorMove digitalWrite(ZstepPin, HIGH);delayMicroseconds(3000);digitalWrite(ZstepPin, LOW);delayMicroseconds(3000);
#define XYMotorMove digitalWrite(XstepPin, HIGH);delayMicroseconds(3000);digitalWrite(XstepPin, LOW);delayMicroseconds(3000);digitalWrite(YstepPin, HIGH);delayMicroseconds(3000);digitalWrite(YstepPin, LOW);delayMicroseconds(3000);
int Xdir = 0;
int Ydir = 0;
int mission = 0;
void setup() {
  pinMode(XstepPin, OUTPUT);
  pinMode(XdirPin, OUTPUT);
  pinMode(YstepPin, OUTPUT);
  pinMode(YdirPin, OUTPUT);
  pinMode(ZstepPin, OUTPUT);
  pinMode(ZdirPin, OUTPUT);
  pinMode(Xendstop, INPUT_PULLUP);
  pinMode(Yendstop, INPUT_PULLUP);
  pinMode(Zendstop, INPUT_PULLUP);
  Serial.begin(9600);


  if(digitalRead(Xendstop) == LOW){    // x 엔드스탑까지 초기화
  XYMotorRight
  for( int i = 0; i<stepinfinity; i++){
    XYMotorMove
    if (digitalRead(Xendstop) == HIGH) {
      break;}
   XYMotorMove}
  }
  if(digitalRead(Yendstop) == LOW){    // Y 엔드스탑까지 초기화
  XYMotorLeftRight
  for( int i = 0; i<stepinfinity; i++){
    XYMotorMove
    if (digitalRead(Yendstop) == HIGH) {
      break;}
   XYMotorMove}
  }
  if(digitalRead(Zendstop) == LOW){    // Y 엔드스탑까지 초기화
  ZMotorDown
  for( int i = 0; i<stepinfinity; i++){
    ZMotorMove
    if (digitalRead(Zendstop) == HIGH) {
      break;}
   ZMotorMove}
  }
   YMotorLeft  //y 센터
    for (int i =0; i < Ycenter; i++){
      YMotorMove}
   ZMotorUp  //z 초기값(센터라함)
    for (int i =0; i < Zcenter; i++){
      ZMotorMove}
  }
void loop() {
  if (Serial.available()){
    mission = Serial.read();
  }
  if (Xdir == 0 && Ydir ==0){  // 원점일때는 8방향 전부 움직임 가능
    if(mission == 1){
      YMotorLeft
        for (int i =0; i < deagak; i++){
          YMotorMove}
          Xdir += 1;
          Ydir += 1;
    }
        else if(mission == 2){
      XYMotorLeft
        for (int i =0; i < garo; i++){
          XYMotorMove}
          Xdir += 1;
    }
        else if(mission == 3){
      XMotorLeft
        for (int i =0; i < deagak; i++){
          XMotorMove}
          Xdir += 1;
          Ydir += -1;
    }
        else if(mission == 4){
      XYMotorLeftRight
        for (int i =0; i < garo; i++){
          XYMotorMove}
          Ydir += -1;
    }
       else if(mission == 5){
      YMotorRight
        for (int i  =0; i < deagak; i++){
          YMotorMove}
          Xdir += -1;
          Ydir += -1;
    }
        else if(mission == 6){
      XYMotorRight
        for (int i =0; i < garo; i++){
          XYMotorMove}
          Xdir += -1;
    }
       else if(mission == 7){
      XMotorRight
        for (int i =0; i < deagak; i++){
          XMotorMove}
          Xdir += -1;
          Ydir += 1;
    }
       else if(mission == 8){
      XYMotorRightLeft
        for (int i =0; i < garo; i++){
          XYMotorMove}
          Ydir += 1;
    }
  }
  if (Xdir == 1 && Ydir ==0){  // 1,0일때 x + 방향 제외 모두가능(1,2,3제외)
 if(mission == 4){
      XYMotorLeftRight
        for (int i =0; i < garo; i++){
          XYMotorMove}
          Ydir += -1;
    }
       else if(mission == 5){
      YMotorRight
        for (int i  =0; i < deagak; i++){
          YMotorMove}
          Xdir += -1;
          Ydir += -1;
    }
        else if(mission == 6){
      XYMotorRight
        for (int i =0; i < garo; i++){
          XYMotorMove}
          Xdir += -1;
    }
       else if(mission == 7){
      XMotorRight
        for (int i =0; i < deagak; i++){
          XMotorMove}
          Xdir += -1;
          Ydir += 1;
    }
       else if(mission == 8){
      XYMotorRightLeft
        for (int i =0; i < garo; i++){
          XYMotorMove}
          Ydir += 1;
    }
  }
    if (Xdir == -1 && Ydir ==0){ // -1,0 일떄 x - 방향 제외 모두가능
    if(mission == 1){
      YMotorLeft
        for (int i =0; i < deagak; i++){
          YMotorMove}
          Xdir += 1;
          Ydir += 1;
    }
        else if(mission == 2){
      XYMotorLeft
        for (int i =0; i < garo; i++){
          XYMotorMove}
          Xdir += 1;
    }
        else if(mission == 3){
      XMotorLeft
        for (int i =0; i < deagak; i++){
          XMotorMove}
          Xdir += 1;
          Ydir += -1;
    }
        else if(mission == 4){
      XYMotorLeftRight
        for (int i =0; i < garo; i++){
          XYMotorMove}
          Ydir += -1;
    }
       else if(mission == 8){
      XYMotorRightLeft
        for (int i =0; i < garo; i++){
          XYMotorMove}
          Ydir += 1;
    }
  }
    if (Xdir == 0 && Ydir ==1){
      if(mission == 2){
      XYMotorLeft
        for (int i =0; i < garo; i++){
          XYMotorMove}
          Xdir += 1;
    }
        else if(mission == 3){
      XMotorLeft
        for (int i =0; i < deagak; i++){
          XMotorMove}
          Xdir += 1;
          Ydir += -1;
    }
        else if(mission == 4){
      XYMotorLeftRight
        for (int i =0; i < garo; i++){
          XYMotorMove}
          Ydir += -1;
    }
       else if(mission == 5){
      YMotorRight
        for (int i  =0; i < deagak; i++){
          YMotorMove}
          Xdir += -1;
          Ydir += -1;
    }
        else if(mission == 6){
      XYMotorRight
        for (int i =0; i < garo; i++){
          XYMotorMove}
          Xdir += -1;
    }
  }
   if (Xdir == 0 && Ydir ==-1){
    if(mission == 1){
      YMotorLeft
        for (int i =0; i < deagak; i++){
          YMotorMove}
          Xdir += 1;
          Ydir += 1;
    }
        else if(mission == 2){
      XYMotorLeft
        for (int i =0; i < garo; i++){
          XYMotorMove}
          Xdir += 1;
    }
        else if(mission == 6){
      XYMotorRight
        for (int i =0; i < garo; i++){
          XYMotorMove}
          Xdir += -1;
    }
       else if(mission == 7){
      XMotorRight
        for (int i =0; i < deagak; i++){
          XMotorMove}
          Xdir += -1;
          Ydir += 1;
    }
       else if(mission == 8){
      XYMotorRightLeft
        for (int i =0; i < garo; i++){
          XYMotorMove}
          Ydir += 1;
    }
  }
   if (Xdir == 1 && Ydir ==1){
    if(mission == 4){
      XYMotorLeftRight
        for (int i =0; i < garo; i++){
          XYMotorMove}
          Ydir += -1;
    }
       else if(mission == 5){
      YMotorRight
        for (int i  =0; i < deagak; i++){
          YMotorMove}
          Xdir += -1;
          Ydir += -1;
    }
        else if(mission == 6){
      XYMotorRight
        for (int i =0; i < garo; i++){
          XYMotorMove}
          Xdir += -1;
    }
  }
  if (Xdir == 1 && Ydir ==-1){
    if(mission == 6){
      XYMotorRight
        for (int i =0; i < garo; i++){
          XYMotorMove}
          Xdir += -1;
    }
       else if(mission == 7){
      XMotorRight
        for (int i =0; i < deagak; i++){
          XMotorMove}
          Xdir += -1;
          Ydir += 1;
    }
       else if(mission == 8){
      XYMotorRightLeft
        for (int i =0; i < garo; i++){
          XYMotorMove}
          Ydir += 1;
    }}
  if (Xdir == -1 && Ydir ==-1){
    if(mission == 1){
      YMotorLeft
        for (int i =0; i < deagak; i++){
          YMotorMove}
          Xdir += 1;
          Ydir += 1;
    }
        else if(mission == 2){
      XYMotorLeft
        for (int i =0; i < garo; i++){
          XYMotorMove}
          Xdir += 1;
    }
       else if(mission == 8){
      XYMotorRightLeft
        for (int i =0; i < garo; i++){
          XYMotorMove}
          Ydir += 1;
    }
  }
  if (Xdir == -1 && Ydir ==1){
    if(mission == 2){
      XYMotorLeft
        for (int i =0; i < garo; i++){
          XYMotorMove}
          Xdir += 1;
    }
        else if(mission == 3){
      XMotorLeft
        for (int i =0; i < deagak; i++){
          XMotorMove}
          Xdir += 1;
          Ydir += -1;
    }
        else if(mission == 4){
      XYMotorLeftRight
        for (int i =0; i < garo; i++){
          XYMotorMove}
          Ydir += -1;
    }
  }}
