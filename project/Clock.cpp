#include "Clock.h"
#include <iostream>
#include <iomanip>
using namespace std;

/**
    Clock Object initialization. Creates a new Clock Object, setting
    all values to 0 and all time_block array entries to false.
*/
Clock::Clock() {
    schedule_count = 0;                        // Number of scheduled time blocks (max 10)
    current_hour = 0;                          // Current hour of internal clock
    current_minute = 0;                        // Current minute of internal clock     (00:00 by default)

    for (int i = 0; i < 10; i++) {             // Set if measurement has been performed to false by default
        has_measured[i] = false;
    }
}

/**
    add_time_block: Int Int Int -> Void
    Takes in the hour and minute of the day (24 hr clock) and desired 
    duration (1 - 3600 seconds) and adds the scheduled time and duration
    into the Clock's time block.
*/
void Clock::add_time_block(int hour, int minute, int duration) {
    // Our time block can only have up to 10 scheduled entries
    if (schedule_count < 10) {  
        // We have room, put in the desired entry and increment schedule_count
        schedule[schedule_count] = {hour, minute, duration};
        has_measured[schedule_count] = false; // has not been measured by default.
        schedule_count++;

        // Displays a message to let user know entry has been scheduled.
        cout << "Added time block at " 
             << setw(2) << setfill('0') << hour << ":" 
             << setw(2) << setfill('0') << minute
             << " for " << duration << " seconds." << endl;
    } else {  // Display message if time block is full.
        cout << "Cannot add more time blocks. Schedule is full." << endl;
    }
}

/**
 * simulate_time_passage: Int Int -> Void
 * Simulate a passage of time in hours and minutes for testing purposes
 * @param hours Time in hours to simulate
 * @param minutes Time in minutes to simulate
 */
void Clock::simulate_time_passage(int hours, int minutes) {
    // Get the total minutes we are jumping forward in time
    int total_minutes = current_hour * 60 + current_minute + hours * 60 + minutes;
    current_hour = (total_minutes / 60) % 24;  // Gives the current hour (24 hr clock)
    current_minute = total_minutes % 60;       // Gives current minute (24 hr clock)

    // Print a message showing that time passage has been simulated along with current time
    cout << "Simulated time passage. Current time: "
         << setw(2) << setfill('0') << current_hour << ":" 
         << setw(2) << setfill('0') << current_minute << endl;
}

/**
 * set_current_time: Int Int -> Void
 * Manually sets the internal clock to the given hour and minute (24 hr clock)
 * @param hour Time in hours to set the internal clock
 * @param minute Time in minutes to set the internal clock
 */
void Clock::set_current_time(int hour, int minute) {
    current_hour = hour;
    current_minute = minute;
    cout << "Time set to " 
         << setw(2) << setfill('0') << current_hour << ":"
         << setw(2) << setfill('0') << current_minute << endl;
}


/**
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

/**
    print_schedule: No Input -> Void
    Prints all currently scheduled times in the time block.
*/
void Clock::print_schedule() {
    cout << "Scheduled Monitoring Blocks:" << endl;
    for (int i = 0; i < schedule_count; i++) {
        cout << "Block " << (i + 1) << ": "
             << setw(2) << setfill('0') << schedule[i].startHour << ":"
             << setw(2) << setfill('0') << schedule[i].startMinute
             << " for " << schedule[i].duration << " seconds"
             << " | Measured: " << (has_measured[i] ? "Yes" : "No") << endl;
    }
}

/**
 * reset_time_block: No Input -> Void
 * Resets all saved time block in time block struct to
 * has_measured = false.  This enables scheduled measurements
 * to be repeated until the scheduled time blocks are removed
 * or replaced.
 */
void Clock::reset_time_block() {
    for (int i = 0; i < 10; i++) {
        // Any scheduled time blocks that have performed their measurements
        // reset to has_measured = false.
        if (has_measured[i])
        {
            has_measured[i] = false;
        }
    }
}