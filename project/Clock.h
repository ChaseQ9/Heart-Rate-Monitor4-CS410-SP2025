#ifndef CLOCK_H
#define CLOCK_H
#include "heart.h"

// This is a simple time clock used for scheduling periods of time
// for monitoring (could work with multiple types of activity)
struct TimeBlock {
  int startHour;      // 0 - 23
  int startMinute;    // 0 - 59
  int duration;       // 1 - 3600 (in seconds) could be longer, but up to 1 hour for now?
};

class Clock {
  public:
  Clock();

  void add_time_block(int hour, int minute, int duration);  // Schedule monitoring session                             
  void simulate_time_passage(int hours, int minutes);        // testing purposes only                                                        
  void set_current_time(int hour, int minute);              // Set internal clock

  int get_current_hour();
  int get_current_minute();
  
  void print_schedule();      // Debugging/Logging
  
  // Template: can monitor any object with a measure_for_seconds(int) method
  template <typename T>
  void check_and_measure(T &monitorable) {
    for (int i = 0; i < schedule_count; i++) {
      if (!has_measured[i] && schedule[i].startHour == current_hour && 
                              schedule[i].startMinute == current_minute) {
        Serial.print("Scheduled measurement triggered at ");
        Serial.print(current_hour);
        Serial.print(":");
        Serial.println(current_minute);
        // Call the object's measure_for_seconds function
        monitorable.measure_for_seconds(schedule[i].duration);
        // Time block has been tested
        has_measured[i] = true;
      }
    }
  }

  private:
    TimeBlock schedule[10];   // Max number of scheduled time blocks
    int schedule_count;       // Tracks how many time blocks are scheduled
    int current_hour;         // Current internal hour time of Clock  (maually set or simulated without RTC)
    int current_minute;       // Same as current_hour but for minutes in internal time of Clock
    bool has_measured[10];    // Tracks whether a measurement has already been taken for each time block TODAY

};

#endif