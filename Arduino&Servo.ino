#include "Servo.h"
Servo myservo;
String inputString = ""; // a String to hold incoming data
boolean stringComplete = false; // whether the string is complete
long fsub;
long sub;
long msub;
void setup() {
// initialize serial:
Serial.begin(115200);
myservo.attach(9);
// reserve 200 bytes for the inputString:
inputString.reserve(200);
}
void loop() {
// print the string when a newline arrives:
if (stringComplete) {
fsub=sub; 
sub=inputString.toInt();
Serial.println(sub);
// clear the string:
inputString = "";
stringComplete = false;
}
msub=sub-fsub;
msub=msub*20;
//Serial.print(mlike);
if (msub==0) {msub = 0;}
if (msub==1) msub = 20;
if (msub<=10 && msub>1) mlike = map(msub, 1, 10, 20, 50);
if (msub<=30 && msub>10) mlike = map(msub, 10, 30, 50, 70);
if (msub<=50 && msub>30) mlike = map(msub, 30, 50, 70, 90);
if (msub<=70 && msub>50) mlike = map(msub, 50, 70, 90, 110);
if (msub<=100 && msub>70) mlike = map(msub, 70, 100, 110, 130);
if (msub<=200 && msub>100) mlike = map(msub, 100, 200, 130, 150);
if (msub<=500 && msub>200) mlike = map(msub, 200, 500, 150, 170);
if (msub<=1000 && msub>500) mlike = map(msub, 500, 1000, 170, 180);
myservo.write(msub);
//Serial.print("    ");
//Serial.println(mlike);
delay(15); 
}
/*
 SerialEvent occurs whenever a new data comes in the hardware serial RX. This
 routine is run between each time loop() runs, so using delay inside loop can
 delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
while (Serial.available()) {
// get the new byte:
char inChar = (char)Serial.read();
// add it to the inputString:
inputString += inChar;
// if the incoming character is a newline, set a flag so the main loop can
// do something about it:
if (inChar == '\n') {
stringComplete = true;
}
}
}