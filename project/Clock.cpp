#include "Clock.h"
using namespace std;
#include <Arduino.h>
/*  Patrick M
    Clock Object initialization.  Creates a new Clock Object, setting
    all values to 0 and all time_block array entries to false.
*/
Clock::Clock() {
    schedule_count = 0;
    current_hour = 0;
    current_minute = 0;
    for (int i = 0; i < 10; i++) {
    has_measured[i] = false;
    }
}

/** Patrick M
    add_time_block: Int Int Int -> Void
    Takes in the hour and minute of the day (24 hr clock) and desired 
    duration (1 - 3600 seconds) and adds the scheduled time and duration
    into the Clock's time block.
*/
void Clock::add_time_block(int hour, int minuteint duration) {
    // Our time block can only have up to 10 scheduled entries
    if (schedule_count < 10) {  
        // We have room, put in the desired entry and increment schedule_count
        schedule[schedule_count] = {hour, minute, duration};
        has_measured[schedule_count] = false; // has not been measured by default.
        schedule_count++;
        // Displays a message to let user know entry has been scheduled.
        Serial.print("Added time block at ");
        Serial.print(hour);
        Serial.print(":");
        Serial.print(minute);
        Serial.print(" for ");
        Serial.print(duration);
        Serial.println(" seconds.");
    } else {  // Display message if time block is full.
        Serial.println("Cannot add more time blocks.  Schedule is full.");
  }
}

/** Patrick M
    simulate_time_passage: Int Int -> Void
    Jumps forward in time to simulate a monitoring duration. (for testing purposes)
*/
void Clock::simulate_time_passage(int hours, int minutes) {
    // Get the total minutes we are jumping forward in time
    int total_minutes = current_hour * 60 + current_minute + hours * 60 + minutes;
    current_hour = (total_minutes / 60) % 24;  // Gives the current hour (24 hr clock)
    current_minute = total_minutes % 60;       // Gives current minute (24 hr clock)
    // Print a message showing that time passage has been simulated along with current time
    Serial.print("Simulated time passage. Current time: ");
    Serial.print(current_hour);
    Serial.print(":");
    Serial.println(current_minute);
    }

/** Patrick M
    set_current_time: Int Int -> Void
    Manually sets the internal clock to the given hour and minute (24 hr clock)
*/
void Clock::set_current_time(int hour, int minute) {
    current_hour = hour;
    current_minute = minute;
    Serial.print("Time set to ");
    Serial.print(current_hour);
    Serial.print(":");
    Serial.println(current_minute);
}

/** Patrick M
    get_current_hour & get_current_minute: No input -> Int
    Accessors for hour and minute for the Clock object
*/
// Get the current hour (24 hr clock)
int Clock::get_current_hour() {
    return current_hour;
}

// Get the current mintue (24 hr clock)
int Clock::get_current_minute() {
    return current_minute;
}

/** Patrick M
    print_schedule: No Input -> Void
    Prints all currently scheduled times in the time block.
*/
void Clock::print_schedule() {
    Serial.println("Scheduled Monitoring Blocks:");
    for (int i = 0; i < schedule_count; i++) {
        Serial.print("Block ");
        Serial.print(i + 1);
        Serial.print(": ");
        Serial.print(schedule[i].startHour);
        Serial.print(":");
        Serial.print(schedule[i].startMinute);
        Serial.print(" for ");
        Serial.print(schedule[i].duration);
        Serial.print("seconds | Measured: ");
        Serial.println(has_measured[i] ? "Yes" : "No");
    }
}










