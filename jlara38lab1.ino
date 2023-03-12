/*
  1 - Author: Jose Lara

  2 - Lab: Lab 1 - Toggle Button

  3. Description: Replicating an AND logic gate using LED's and Buttons. Having the two buttons pressed will allow for the 3rd (red LED) to light up.
  we idicate that a button is pressed by lightning up a blue LED.

  4. Pin - 13 is connected to the 1st button while its output is given to the Arduino through the 13th pin. This is an input component.
     Pin - 12 is connected to my 2nd button while its output is given to the Arduino through the 12th pin. This is an input component.
     Pin - 8 is for my Blue LED which is an output component.
     Pin - 9 is for my 2nd Blue LED which is an output component.
     Pin - 10 is for my Red LED which is an output component.
     
  5. References: 
    https://www.youtube.com/watch?v=aMato4olzi8
    https://www.youtube.com/watch?v=c7UZv6eH4YU
    https://docs.arduino.cc/built-in-examples/digital/StateChangeDetection
    https://www.youtube.com/watch?v=VPGRqML_v0w
    https://drive.google.com/file/d/1oYZPr5tMV6rBQhtMiJENcV73Tse7TGNg/view?usp=share_link
    https://learn.zybooks.com/zybook/UICCS362DiazHerreraSpring2023/chapter/4/section/6

  6. Demo: In-Person Demonstration: 1/30/2023, 9AM Lab,  Elijah Parr 

*/

int LEDState = 0;
int LEDPin = 8;
int buttonPin = 13;
int buttonNew;
int buttonOld = 1;

int LEDStateOne = 0;
int LEDPinOne = 9;
int buttonPinOne = 12;
int buttonNewOne;
int buttonOldOne = 1;

int LEDPinRed = 10;
int LEDStateRed = 0;

int dt = 100;

void setup() {
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);
  pinMode(LEDPinOne, OUTPUT);
  pinMode(LEDPinRed, OUTPUT);
  pinMode(buttonPin,INPUT);
  pinMode(buttonPinOne,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonNew = digitalRead(buttonPin);
  buttonNewOne = digitalRead(buttonPinOne);

  if(buttonOld == 0 && buttonNew == 1) {
    if(LEDState == 0) {
      digitalWrite(LEDPin, HIGH); 
      LEDState = 1;
    } else {
      digitalWrite(LEDPin,LOW);
      LEDState = 0;
    }
  }

  if(buttonOldOne == 0 && buttonNewOne == 1) {
    if(LEDStateOne == 0) {
      digitalWrite(LEDPinOne,HIGH);
      LEDStateOne = 1;
    } else {
      digitalWrite(LEDPinOne,LOW);
      LEDStateOne = 0;
    }
  }

  if(LEDStateOne == 1 && LEDState == 1) {
    digitalWrite(LEDPinRed,HIGH);
    LEDStateRed = 1;
  } else {
    digitalWrite(LEDPinRed,LOW);
    LEDStateRed = 0;
  }

  buttonOld = buttonNew;
  buttonOldOne = buttonNewOne;
  delay(dt);
}
