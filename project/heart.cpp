#include "heart.h"

Heart::Heart(int u_age, String u_name) {
  heart_rate = 0;
  average_heart_rate = 0.0;
  monitor_time = 0;
  irregular = false;
  name = u_name;
  age = u_age;
  Serial.println("Heart monitor initialized");
}

Heart::~Heart() {
  Serial.print("Final Statistics for [");
  Serial.print(name); // Arduino way to convert std::string to print. 
  Serial.print("]: Heart Rate - ");
  Serial.print(heart_rate);
  Serial.print(", Average Heart Rate - ");
  Serial.print(average_heart_rate);
  Serial.print(", Monitored Time - ");
  Serial.println(monitor_time);
}

// Andrew N
// Getters and Setters
int Heart::get_heart_rate() {
  return heart_rate;
}

double Heart::get_avg_heart_rate() {
  return average_heart_rate;
}

void Heart::set_monitor_time(int time) {
  monitor_time = time;
}

void Heart::set_average_heart_rate(double average_rate) {
  average_heart_rate = average_rate;
}

void Heart::set_heart_rate(int rate) {
  heart_rate = rate;
}

// Patrick M
/** measure_for_seconds: Int -> Void
*   Takes in a specified time (in seconds), and records heart rate during that time. Placedholder
*   until we know the actual sensor logic
*/
void Heart::measure_for_seconds(int seconds) {
  Serial.print("Measuring heart rate for ");
  Serial.print(seconds);
  Serial.println(" seconds...");
  wait_x_seconds(seconds * 1000);
  // Need to edit, just simulation for now...
  int simulated_rate = random(50, 140);  // Replace random with actual sensor logic later!
  set_heart_rate(simulated_rate);
  Serial.print("Heart rate measured: ");
  Serial.println(simulated_rate);
  if (normal_heart_rate(average_heart_rate)) {
    Serial.println ("Your heart-rate is normal!");
  } else {
    Serial.println ("Your heart-rate is NOT normal!");
  }
}

// Chase Q - Function to wait x amount of seconds, this is useful for measuring a heart rate for a user as 
// typically we can get a good measure after of analyzing. Typically a minute is good for measuring 
// 1 minute = 60_000 milli_seconds
void Heart::wait_x_seconds(int milli_seconds) {
  unsigned int start = millis();
  unsigned int current = 0;
  unsigned int elapsed = 0;
  while (true) {
    current = millis();
    elapsed = current - start;
    if (elapsed >= milli_seconds) {
      return;
    }
  }
}

bool normal_heart_rate(double average_heart_rate) {
  // If betwen 60 and 100, will return True (Patrick McDonald)
  return (average_heart_rate >= 60 && average_heart_rate <= 100); 
}

// Function to record the average heart rate every hour over a 24-hour cycle.
// Probably gonna change this to 
void storeDailyAvgHeartRates(Heart &heart) {
  // Array to hold 24 heartrate measurements for a 24hr cycle
  double hourlyAverages[24];
  for (int hour = 0; hour < 24; hour++) {
    // Inform the user which hour is being measured.
    Serial.print("Starting measurement for hour ");
    Serial.println(hour + 1);
    // Measure heart rate for one hour
    heart.measure_for_seconds(3600);
    // Retrieve and store the average heart rate from the current measurement.
    hourlyAverages[hour] = heart.get_avg_heart_rate();
    // Log the measured average for this hour.
    Serial.print("Recorded avg heart rate for hour ");
    Serial.print(hour + 1);
    Serial.print(": ");
    Serial.println(hourlyAverages[hour]);
  }
  
  // Optionally, display the entire day's measurements.
  Serial.println("Daily average heart rates:");
  for (int i = 0; i < 24; i++) {
    Serial.print("Hour ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.println(hourlyAverages[i]);
  }
}


