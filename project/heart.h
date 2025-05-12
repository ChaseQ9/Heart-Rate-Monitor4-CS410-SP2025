#ifndef HEART_H
#define HEART_H
#include <Arduino.h>

/*  This is the header description for our heart.h file. This file as well as its .cpp counterpart are used to represent a heart rate 
* calculated by our project.ino file and our esp32 board. The goal of this file and our .cpp version of this file is to allow
* a user to know specific facts about their heart and to implement our clock class and files in order to have specific measuring "moments"
* from our project so that they can keep an eye on the parts of their day they deem to be important enough to measure their heart rates
*/

class Heart {
  public:
    Heart(int age, String name);
    ~Heart();

    int get_heart_rate();
    double get_avg_heart_rate();
    int get_monitor_time();

    // Andrew N - Implemented set_monitor_time, set_average_heart_rate, set_heart_rate.
    void set_monitor_time(int time);
    void set_average_heart_rate(double average_rate);
    void set_heart_rate(int rate);

    // Patrick M - Implement measure_for_seconds 
    void measure_for_seconds(int seconds);   // simulates live measurement during recording of heart-rate

    String get_name();
    int get_age();
    void set_name();
    void set_age();

    void wait_x_seconds(int milli_seconds);
  private:
    int heart_rate;
    double average_heart_rate; 
    int monitor_time; // in seconds (could change)
    bool irregular;
    String name;
    int age;
};

void wait_60_second(int milli_seconds);
bool normal_heart_rate(double average_heart_rate);

#endif 