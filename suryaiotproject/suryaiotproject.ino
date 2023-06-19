#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#define DHT11_PIN 23
int pumppin=21;
int humdpump=19;
int sensorpin=22;
int humd=12;
void setup(){
  Serial.begin(115200);
  pinMode(pumppin,OUTPUT);
  pinMode(humd,OUTPUT);
  pinMode(sensorpin,INPUT);
}
void loop(){
  DHT.read(DHT11_PIN);
  Serial.println("Humidity:");
  Serial.println(DHT.humidity);
   if (digitalRead(sensorpin)==HIGH)
 {
  digitalWrite(pumppin,HIGH);
  Serial.println("No Water In Field Pump Is ON");
 }
 else
 {
  digitalWrite(pumppin,LOW);
  Serial.println("Water in field pump is OFF");
 }

 if(DHT.humidity<20){
    digitalWrite(humd,HIGH);
    digitalWrite(humdpump,HIGH);
    Serial.println("Humidity is LOW running humidity control system");
 }
 else if(DHT.humidity>20 && DHT.humidity<100){
  digitalWrite(humd,LOW);
  digitalWrite(humdpump,LOW);
  Serial.println("Humidity control system is OFF");}
 else if(DHT.humidity>100){
  digitalWrite(humd,HIGH);
  digitalWrite(humdpump,LOW);
  Serial.println("Humidity is HIGH Running humidity control system");
 }
 else{}
 delay(1000);
}
