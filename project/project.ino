// DEFINES 
#define HEARTBEAT_PIN 23
#define MINUTE 60000
// DEFINES 

// INCLUDE LIBRARIES 
#include <Arduino.h>
// INCLUDE LIBRARIES 

// VARIABLE DEFINITIONS 
unsigned long lastBeatTime = 0;
unsigned long startWindow = 0;
int beatCount = 0;
const int windowSize = 10000; // 10 seconds
// VARIABLE DEFINITIONS 

// This function is run once on the esp32 initialization
// This function is used to set things such as the pinMode for the pin we are currently using 
void setup() {
  Serial.begin(115200);
  pinMode(HEARTBEAT_PIN, INPUT);
  startWindow = millis();
}

// This loop continously runs on the esp32 board
// This is where the bpm is calculates 
void loop() {
  static int lastState = LOW;
  int currentState = digitalRead(HEARTBEAT_PIN);
  unsigned long now = millis();
  
  // If statement is used to mitigate "double counting" in our program. We do not want to count a heartbeat twice 
  if (currentState == HIGH && (now - lastBeatTime > 700)) {
    Serial.print("now - last beat time = ");
    Serial.println(now - lastBeatTime);
    beatCount++;
    lastBeatTime = now;
  }

  // Check to see if it has been 10 seconds (the window for how often we want to calculate / display the heartbeat )
  if (now - startWindow >= windowSize) {
    int bpm = beatCount;
    Serial.print("Heart Rate (BPM): ");
    Serial.println(bpm);

    // Reset for next window
    beatCount = 0;
    startWindow = now;
    currentState = LOW;
  }

  // lastState = currentState;
}