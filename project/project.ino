#define HEARTBEAT_PIN 23
#define MINUTE 60000
#include <Arduino.h>
unsigned long lastBeatTime = 0;
unsigned long startWindow = 0;
int beatCount = 0;
const int windowSize = 10000; // 10 seconds


void setup() {
  Serial.begin(115200);
  pinMode(HEARTBEAT_PIN, INPUT);
  startWindow = millis();
}

void loop() {
  static int lastState = LOW;
  int currentState = digitalRead(HEARTBEAT_PIN);
  unsigned long now = millis();

  if (currentState == HIGH && (now - lastBeatTime > 700)) {
    Serial.print("now - last beat time = ");
    Serial.println(now - lastBeatTime);
    beatCount++;
    lastBeatTime = now;
  }

  if (now - startWindow >= MINUTE) {
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