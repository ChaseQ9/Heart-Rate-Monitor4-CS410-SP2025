## ❤️ Heart Rate Monitor - End-User Manual
Welcome! This guide will walk you through how to **set up, build, run and use** the Heart Rate Monitor project created for CS410-SP2025.

## What You Need
- ESP32 board
- KY-039 Heartbeat Sensor Module
- Breadboard and wires
- USB cable to connect ESP32 to your computer
- Python(Python 3) installed on your computer
- A modern web browser (e.g., Chrome, Firefox)
- Visual Studio Code (Recommended IDE)

## How to set up
1. **Download the Project**
- Download the project files from our GitHub repository (Either clone or download ZIP and extract it locally)
2. **Install Python Dependencies**
- Install Flask using pip: "pip install flask"
3. **Hardware Setup**
- Configure the breadboard with the ESP32 and Ky-039

## How to build it
Use the Arduino IDE to upload the project.ino file in your ESP32 board:
- Open project.ino in the Arduino IDE.
- Select your board type (e.g., "ESP32 Dev Module").
- Select the correct COM port.
- Click Upload to flash the ESP32. 
- (Optional) Adjust the threshold value in project.ino depending on your pulse sensor's sensitivity.

## How to run it
Run the Backend Server
- In the terminal, run: "python/python3 server.py"
- Once started, the server will provide a local address (e.g., http://127.0.0.1:5000)
- Copy and paste that into your web browser.
- Keep the terminal running while using the application.

## How to use it
- Place your finger between the LED and sensor on the ESP32.
- Do this in a dimly or darkly lit room for best results.
- Wait a few seconds for signal detection.
- Your current heart rate (BPM) will appear on the website in real time.

## Troubleshooting
### Problem / Solution 
1. **No heart rate detected**
- Ensure finger placement is correct, check lighting and be patient.
- Make sure the wiring is done correctly and check if the pin used in the code is the same as the hardware.
- Make sure the LED is working (use a cellphone camera to check if the LED emits anything)
2. **Server doesn't start**
- Make sure Flask is installed and use python/python3 server.py
3. **Website shows no data**
- Confirm ESP32 is sending data; check wiring and serial connection.
4. **Inaccurate heartrates**
- Make sure the baudrate set in the code is the same as the serial monitor
- Adjust the if statement in project.ino that checks for heartrates to skip any readings that occur too close 

## Notes
- This project does not store any personal health data.
- All readings are processed in real time and are not logged or saved.
- For technical background, please check the issue page on our website for more details on how PPG or photo-plethysmography works.
