///////////////////////////////////////////////////////////////
//                                                          //
//                                                         //
//Bluetooth ile arduino araba/tank                        //
//                                                       //
//                                                      //
// coded by Semih GÜL                                  //
// supported by Rıza Ferit Külköylüoğlu               //
//                                                   //
//////////////////////////////////////////////////////

#include <StepperMotor.h>
#include<SoftwareSerial.h> 
char readString;
#define SolMotorileri 10
#define SolMotorGeri 11
#define SagMotorileri 8
#define SagMotorGeri 9
#define SagMotorE 5
#define SolMotorE 6
SoftwareSerial bt(2,3); /* (Rx,Tx) */   
StepperMotor motor( A5, A4, A3, A2);
void setup() {
 pinMode(SolMotorileri, OUTPUT);
 pinMode(SolMotorGeri, OUTPUT);
 pinMode(SagMotorileri, OUTPUT);
 pinMode(SagMotorGeri, OUTPUT);
 pinMode(SagMotorE, OUTPUT);
 pinMode(SolMotorE, OUTPUT);
 pinMode(A5, OUTPUT);
 pinMode(A4, OUTPUT);
 pinMode(A3, OUTPUT);
 pinMode(A2, OUTPUT);

 pinMode(7, OUTPUT);
 motor.setStepDuration(1);
 bt.begin(9600); 
 Serial.begin(9600); //Bluetooth modülümüz ile 9600 bandında haberleşeceğiz
}
 
void loop() {
 if (bt.available()) { // gelen komutu alıyoruz
 readString = bt.read();
 
 }
 
 
  if (readString == 'W') { // gelen komut kontrolüne göre işlem yaptırıyoruz
  analogWrite(SolMotorileri, 200);
  analogWrite(SolMotorGeri, LOW);
  analogWrite(SagMotorileri, 200);
  analogWrite(SagMotorGeri, LOW);
  analogWrite(SagMotorE, 255);
  analogWrite(SolMotorE, 255);
}


 
  if (readString == 'X') { // gelen komut kontrolüne göre işlem yaptırıyoruz
  digitalWrite(SolMotorileri, LOW);
  digitalWrite(SolMotorGeri, LOW);
  digitalWrite(SagMotorileri, LOW);
  digitalWrite(SagMotorGeri, LOW);
  digitalWrite(SagMotorE, 0);
  digitalWrite(SolMotorE, 0);
}
 
 if (readString == 'S') {
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, 120);
digitalWrite(SagMotorileri, LOW);
digitalWrite(SagMotorGeri, 120);
digitalWrite(SagMotorE, 255);
digitalWrite(SolMotorE, 255);
}


 if (readString == 'D') { // gelen komut kontrolüne göre işlem yaptırıyoruz
digitalWrite(SolMotorileri, 120);
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SagMotorileri, LOW);
digitalWrite(SagMotorGeri, 120);
digitalWrite(SagMotorE, 255);
digitalWrite(SolMotorE, 255);
}
 
  if (readString == 'A') { // gelen komut kontrolüne göre işlem yaptırıyoruz
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, 120);
digitalWrite(SagMotorileri, 120);
digitalWrite(SagMotorGeri, LOW);
digitalWrite(SagMotorE, 255);
digitalWrite(SolMotorE, 255);
}
 

  if (readString == 'Q') { // gelen komut kontrolüne göre işlem yaptırıyoruz
motor.step(10);}

  

  if (readString == 'E') { // gelen komut kontrolüne göre işlem yaptırıyoruz
motor.step(-10);}
 


 if (readString == 'R') { // gelen komut kontrolüne göre işlem yaptırıyoruz
digitalWrite(7, HIGH);
delay(500);
digitalWrite(7, LOW);
}


}
