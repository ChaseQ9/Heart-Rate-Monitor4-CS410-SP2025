// Program: project.ino
// This program is designed to measure heart rate using an ESP32 microcontroller and a pulse sensor.

// Variable Declarations
const int pulsePin = 34;  // GPIO34 for analog input, replace with whatever anolog pin you are using with your microboard
const int buzzerPin = 22;// GPIO22 for the buzzer. Currently unused
int threshold = 19;      // Threshold for fluctuations to determine a heartbeat, adjust according to your sensor
unsigned long lastBeatTime = 0; // Time since the last Beat (heartbeat)
int beatCount = 0; // how many beats we have come across
unsigned long startTime = 0;

// The setup function is run once at the initialization
void setup() {
  Serial.begin(115200); //baudrate to read serial monitor make sure it matches whatever baudrate your serial monitor is set to
  delay(2000);
  startTime = millis(); 
  pinMode(buzzerPin, OUTPUT);
}

// The loop function is run continously on the board
void loop() {
  int analogValue = analogRead(pulsePin);

  // Detect heart beat (avoid duplicates through time)
  if (analogValue > threshold && (millis() - lastBeatTime) > 250) {
    beatCount++;
    // Serial.println("beat detected");
    lastBeatTime = millis(); //marks the current time
  }

  // Every 10 seconds, calculate BPM
  if (millis() - startTime >= 10000) {
    // equation we have come across to calculate bpm
    float bpm = (beatCount / 10.0) * 60.0;
    
     if (bpm >= 140) { //if the calculated bpm is greater than or equal to 140 activate buzzer
       tone(buzzerPin, 10000, 500);
         delay(1000);
         noTone(buzzerPin);
         delay(1000);
    }
    
    Serial.println(bpm);
    beatCount = 0;
    startTime = millis(); //resets everything for the next loop
  }

  delay(10);  // Small delay to reduce noise
}
