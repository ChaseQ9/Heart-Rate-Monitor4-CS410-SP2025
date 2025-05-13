#include <iostream>
#include "heart.h"
#include <cstdlib>

/*  This is the header description for our heart.cpp file. This file as well as its .h counterpart are used to represent a heart rate 
* calculated by our project.ino file and our esp32 board. The goal of this file and our .h version of this file is to allow
* a user to know specific facts about their heart and to implement our clock class and files in order to have specific measuring "moments"
* from our project so that they can keep an eye on the parts of their day they deem to be important enough to measure their heart rates
*/

using namespace std;

Heart::Heart(int u_age, String u_name) {
  heart_rate = 0;
  average_heart_rate = 0.0;
  monitor_time = 0;
  irregular = false;
  name = u_name;
  age = u_age;
  cout << "Heart Monitor Initialized" << endl;
}

Heart::~Heart() {
  cout << "Final Statistics for [" << name << "]: Heart Rate - " << heart_rate << ", Average Heart Rate - " << average_heart_rate << ", Monitored Time - " << monitor_time << endl;
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
  cout << "Measuring heart rate for " << seconds << " seconds..." << endl;
  wait_x_seconds(seconds * 1000);
  // Need to edit, just simulation for now...
  int simulated_rate = rand(50, 140);  // Replace random with actual sensor logic later!
  set_heart_rate(simulated_rate);
  cout << "Heart rate measured: " << simulated_rate << endl;
  if (normal_heart_rate(average_heart_rate)) {
    cout << "Your heart-rate is normal!";
  } else {
    cout << "Your heart-rate is NOT normal!";
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

// William M
// Function to record the average heart rate every hour over a 24-hour cycle 
// Can be adjusted to store the average heart rate for however long 
// of a cycle you want
void storeDailyAvgHeartRates(Heart &heart) {
  // Array to hold 24 heartrate measurements for a 24hr cycle
  double hourlyAverages[24];
  for (int hour = 0; hour < 24; hour++) {
    // Inform the user which hour is being measured.
    cout << "Starting measurement for hour " << hour + 1 << endl;
    // Measure heart rate for one hour
    heart.measure_for_seconds(3600);
    // Retrieve and store the average heart rate from the current measurement.
    hourlyAverages[hour] = heart.get_avg_heart_rate();
    // Log the measured average for this hour.
    cout << "Recorded avg heart rate for hour " << hour + 1 << ": " << hourlyAverages[hour] << endl;
  }
  
  // Optionally, display the entire day's measurements.
  cout << "Daily average heart rates:" << endl;
  for (int i = 0; i < 24; i++) {
    cout << "Hour " << i + 1 << ": " << hourlyAverages[i] << endl;
  }
}


