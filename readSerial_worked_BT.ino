int incomingByte = 0;   // for incoming serial data
int i = 0;
byte iB = B00000000;
byte inB = B00000000;
void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
        // Try to change this for quicker speed.
}

void loop() {
       
        
        iB++;
        Serial.println(iB);
        // send data only when you receive data:
        if (Serial.available() > 0) {
          if (
                // read the incoming byte:
                inB = Serial.read();

                // say what you got:
                //Serial.print("********** : ");
                //Serial.println(inB, DEC);
        }
        if(iB>B11111111)iB = 0;
        delay(1000);
}
