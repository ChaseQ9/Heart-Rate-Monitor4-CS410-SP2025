# Heart-Rate-Monitor4-CS410-SP2025
Final Project for CS410-SP2025

## Our Goal
The goal for this project was for our group to create a heart rate monitor that a user is able to use to monitor their current heart rate
(their bpm). Although our project was not able to be implemented to actually measure a users heart rate (due to a faulty sensor), we created 
a friendly dashboard which allows users to simply and easily see their current bpm at a glance without having to jump through many hoops of
logging in to a website. Our website does not store any previous data from the user so there is never a concern for the user's saftey in regards
to their health information being lost. All data is run in realtime from our ESP32 board through a flask python server and in the end delivered
to our website for viewing. 

## How to use our project
Our project is simple to use in its nature. For a user to measure their heart rate, all that needs to be done is to place your finger between the 
led light and the sensor (across from the light) in a dimly (or preferebly dark) lit room to be able to get the best results. From here, our project will 
do all of the work of transmitting the data gathered from the sensor so that it can be easily viewed in our website. For the data to be sent from the 
ESP32 to the website, you must first run python[3] server.py (3 is sometimes required so it could be python or python3, it is python3 for me [Chase]
writing this). Once the server is up and running, the data will then be sent from the ESP32 to the website. To view the website a user could run the VSCode live server
extension from the extensions library. 
 

## Project layout
Our project is built in a simple file structure setup. We store all of the relevent project files in the directory named "project" at 
the github url link listed here: https://github.com/ChaseQ9/Heart-Rate-Monitor4-CS410-SP2025/tree/main 
Within our project directory, we have a "static_website" directory which stores all the relevant html and css as well as images, videos, 
and our javascript file we use for our clock on the website as well. Outside of this directory, we have all our files regarding the (future) 
implementation of our clock files, heart files, and our server.py file which is the file that is used to bring the data from the ESP32 to the website 
through the Flask framework.

## Warning
Our project was implemented with a broken sensor so when integrating our the source code with your sensor, you will have to adjust the threshhold value in
project.ino which determines a singular heart rate depending on how sensitive your sensor is. Check the issue page on our website for more details on how PPG or photo-plethysmography works.

## Detailed Usage
For more details regarding our project, please refer to our code-manual.md and user-manual.md.

