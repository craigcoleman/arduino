// This code runs an arduino with a IR decoder 
// and Magnovox remote
// I need to do  bit of work decoding the IR .  Notice hexin = results.value; 
// Notice #include <Servo.h> has been changed from K Shirriff's code
// C Coleman

#include <Servo.h> 
#include <IR.h>
Servo servoRight;               
Servo servoLeft; 

int led5 = 5; //left    port
int led6 = 6;  //right  starrbord

int ms250 = 250;
 
int RECV_PIN = 3;
byte hexin = 0x0;
IRrecv irrecv(RECV_PIN);

decode_results results;
 
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  servoRight.attach(11);                     // Attach right signal to pin 12
   servoLeft.attach(12);
   pinMode(led5, OUTPUT);
   pinMode(led6, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    hexin = results.value;
    Serial.println(hexin);
    //foward
    if ((hexin == 102) || (hexin == 167)){ delay(ms250);  servoRight.writeMicroseconds(700); servoLeft.writeMicroseconds(2300);
                                      digitalWrite(led5, HIGH); digitalWrite(led6, HIGH);              }
    //back
    if ((hexin == 18) || (hexin == 251 )){ delay(ms250);   servoRight.writeMicroseconds(2300);servoLeft.writeMicroseconds(700);}   
    //right
    if ((hexin == 111) || (hexin == 154 )){ delay(ms250);  rightTurn(1000); }  
   //left
    if ((hexin == 110) || (hexin == 151 )){ delay(ms250);  leftTurn(1000);}    
    //spingRight
    if ((hexin == 13) || (hexin == 13 )){ delay(ms250);  spinRight(); digitalWrite(led5, LOW); digitalWrite(led6, HIGH);       }  
    //spinLeft
    if ((hexin == 38) || (hexin == 26 )){ delay(ms250);  spinLeft();digitalWrite(led5, HIGH); digitalWrite(led6, LOW);   }  
    
// stop  
 if (hexin == 46) { delay(ms250);   servoRight.writeMicroseconds(1500);servoLeft.writeMicroseconds(1500); }
    irrecv.resume(); // Receive the next value
  }
}


void spinRight(){
  delay(ms250);servoRight.writeMicroseconds(500);servoLeft.writeMicroseconds(500);
  digitalWrite(led5, LOW); digitalWrite(led6, HIGH);  
}

void spinLeft(){
 delay(ms250);servoRight.writeMicroseconds(2500);servoLeft.writeMicroseconds(2500); 
;digitalWrite(led5, HIGH); digitalWrite(led6, LOW); 
}

void leftTurn(int turnVal){
  for (int i = 0; i < turnVal; i++)
  servoRight.writeMicroseconds(2500);servoLeft.writeMicroseconds(2500);
  delay(turnVal);
  servoRight.writeMicroseconds(1500);servoLeft.writeMicroseconds(1500);
}

void rightTurn(int turnVal){
  for (int i = 0; i < turnVal; i++)
  servoRight.writeMicroseconds(500);servoLeft.writeMicroseconds(500);
  delay(turnVal);
  servoRight.writeMicroseconds(1500);servoLeft.writeMicroseconds(1500);
}
