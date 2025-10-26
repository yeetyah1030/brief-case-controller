#include <ezButton.h>

// slider pins
const int sliderPotPin1 = A0;
const int sliderPotPin2 = A1;
const int sliderPotPin3 = A2;

// rotary pot pins
const int rotaryPotPin1 = A3;
const int rotaryPotPin2 = A4;
const int rotaryPotPin3 = A5;

// onoff switch pins
ezButton toggleSwitch1 = 2;
ezButton toggleSwitch2 = 4;
ezButton toggleSwitch3 = 7;

// LEDs
const int LED_PIN1 = 8;
const int LED_PIN2 = 12;
const int LED_PIN3 = 13;

void setup() {
  // init serial comms
  Serial.begin(9600); 

  // slider setup
  pinMode(sliderPotPin1, INPUT);
  pinMode(sliderPotPin2, INPUT);
  pinMode(sliderPotPin3, INPUT);

  // set toggle switch debug
  toggleSwitch1.setDebounceTime(50);
  toggleSwitch2.setDebounceTime(50);
  toggleSwitch3.setDebounceTime(50);

  // rotary pins setup
  pinMode(rotaryPotPin1, INPUT);
  pinMode(rotaryPotPin2, INPUT);
  pinMode(rotaryPotPin3, INPUT);

  // LED setup
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
}

void loop() {
  // call input functions
  sliderCtrl();
  toggleSwitchCtrl();
  rotaryCtrl();
}

void sliderCtrl(){
  // read the analog value from the slider potentiometer
  int sliderVal1 = analogRead(sliderPotPin1);
  int sliderVal2 = analogRead(sliderPotPin2);
  int sliderVal3 = analogRead(sliderPotPin3); 

  Serial.print("SLIDER:");
  Serial.print(sliderVal1);
  Serial.print(",");
  Serial.print(sliderVal2);
  Serial.print(",");
  Serial.println(sliderVal3);

  delay(10); 
}

void rotaryCtrl(){
  int rotaryVal1 = analogRead(rotaryPotPin1); 
  int rotaryVal2 = analogRead(rotaryPotPin2);
  int rotaryVal3 = analogRead(rotaryPotPin3);

  // print and read values to serial monitor
  Serial.print("ROTARY:");
  Serial.print(rotaryVal1);
  Serial.print(",");
  Serial.print(rotaryVal2);
  Serial.print(",");
  Serial.println(rotaryVal3);

  delay(10); 
}

void toggleSwitchCtrl(){
  toggleSwitch1.loop();
  toggleSwitch2.loop();
  toggleSwitch3.loop();

  int toggleVal1 = toggleSwitch1.getState();
  int toggleVal2 = toggleSwitch2.getState();
  int toggleVal3 = toggleSwitch3.getState();

  // control LED based on toggle switch state
  if (toggleVal1 == LOW) {
    digitalWrite(LED_PIN1, HIGH);  // LED on
  } else {
    digitalWrite(LED_PIN1, LOW);   // LED off
  }

  if (toggleVal2 == LOW) {
    digitalWrite(LED_PIN2, HIGH);
  } else {
    digitalWrite(LED_PIN2, LOW);
  }

  if (toggleVal3 == LOW) {
    digitalWrite(LED_PIN3, HIGH);
  } else {
    digitalWrite(LED_PIN3, LOW);
  }

  Serial.print("SWITCH:");
  Serial.print(toggleVal1);
  Serial.print(",");
  Serial.print(toggleVal2);
  Serial.print(",");
  Serial.println(toggleVal3);
  
  delay(10);
}
