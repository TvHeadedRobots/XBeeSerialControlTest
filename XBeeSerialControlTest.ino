#include <stdio.h>

char incomingByte[3];   // array of 3 vals
char servoValC1[1];
char servoValC2[1];
char servoValC3[1];
int servoVal = 0;

void setup() {
        Serial.begin(57600);
}

void loop() {
/*
        int a = 1, b = 2;
        char c[40]; 
        sprintf(c, "%d%d", a, b);
        Serial.println(atoi(c));
*/
        
        // send data only when you receive data:
        if (Serial.available() > 0) {
            Serial.print("peek-a-boo: ");
            Serial.println(Serial.peek());
          
            // read the incoming and concatenate it in a 3 digit value:            
            for (int i = 0; i < 3; i++) 
            {
              incomingByte[i] = Serial.read();
              Serial.print("incomingByte[");
              Serial.print(i);
              Serial.println("]");
              Serial.println(incomingByte[i]);
              delay(1000);
              
              if (i == 0) 
              {
                sprintf(servoValC1, "%c", incomingByte[i]);
                Serial.print("servoValC1: ");
                Serial.println(servoValC1);
                Serial.println(Serial.peek());
                delay(1000);                
                //continue;
                //break;
              } 
              else if (i == 1) 
              {
                sprintf(servoValC2, "%c %c", incomingByte[i-1], incomingByte[i]);
                Serial.print("servoValC2: ");
                Serial.println(servoValC2);
                Serial.println(Serial.peek());
                delay(1000);
                //continue;
                //break;
              } 
              else if (i == 2)
              {
                sprintf(servoValC3, "%c %c %c", incomingByte[i-2], incomingByte[i-1], incomingByte[i]);
                Serial.print("servoValC3: ");
                Serial.println(servoValC3);
                Serial.println(Serial.peek());
                delay(1000);
                //continue;
                //break;
              }
              
            }

            //servoVal = (atoi(servoValC3));
            //if (servoVal > 0) {
             // say what you got:
             //Serial.print("I received: ");
             //Serial.println(servoVal);
             //}
        }
      
}
