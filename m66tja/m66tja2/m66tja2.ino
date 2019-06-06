/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/

const int trigPinL = 10;
const int trigPinR = 8;
const int echoPinL = 11;
const int echoPinR = 9;
const int outL = 5;
const int outR = 6;
long durationR;
long durationL;
int distanceL;
int distanceR;
void setup() {
pinMode(trigPinL, OUTPUT); 
pinMode(trigPinR, OUTPUT);
pinMode(outL, OUTPUT); 
pinMode(outR, OUTPUT);
pinMode(echoPinL, INPUT); 
pinMode(echoPinR, INPUT);
Serial.begin(9600); 

}
void loop() {
  sensorL();
  sensorR();
  distance();
}

void sensorL(){
// TRIGGER L
  digitalWrite(trigPinL, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinL, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinL, LOW);
  durationL = pulseIn(echoPinL, HIGH);
  distanceL = durationL*0.034/2;

  delay(10);
  }
// TRIGGER R
void sensorR(){
  digitalWrite(trigPinR, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinR, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinR, LOW);
  durationR = pulseIn(echoPinR, HIGH);
  distanceR = durationR*0.034/2;
  delay(10);
}
void distance(){
  Serial.print("DistanceL: ");
  Serial.println(distanceL);
  Serial.print("DistanceR: ");
  Serial.println(distanceR);
  if (distanceL <= 40) {
    //digitalWrite(outL, LOW);
    //delayMicroseconds(2);
    digitalWrite(outL, HIGH);
    Serial.print("L is high");
    delayMicroseconds(10000);
    digitalWrite(outL, LOW);
  };
  if (distanceR <= 40) {
    //digitalWrite(outR, LOW);
    //delayMicroseconds(2);
    digitalWrite(outR, HIGH);
    Serial.print("R is high");    
    delayMicroseconds(10000);
    digitalWrite(outR, LOW);
  };
  delayMicroseconds(10);
//  digitalWrite(outR, LOW);
//  digitalWrite(outL, LOW);
  delay(50);
}
  

