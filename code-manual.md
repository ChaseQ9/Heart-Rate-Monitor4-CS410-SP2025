## 🧠 Heart Rate Monitor — Code Manual
Welcome! This guide will walk you through the **internal structure and functionality** of the Heart Rate Monitor project created for CS410-SP2025.

## Internal Structure
Heart-Rate-Monitor4-CS410-SP2025/
│
├── .vscode/                            # VS Code workspace settings
│   └── settings.json
│
├── project/
│   ├── __pycache__/                    # Python bytecode cache
│   ├── .vscode/                        # (Optional) Local project settings
│   │   └── c_cpp_properties.json
│   ├── settings.json                   # Project-level settings
│
│   ├── static_website/                # Frontend files served to the user
│   │   ├── images/                    # UI images
│   │   ├── videos/                    # Videos or demonstrations
│   │   ├── clock.js                   # JavaScript for real-time clock/BPM updates
│   │   ├── description.html           # Project overview webpage
│   │   ├── description-style.css
│   │   ├── future.html                # Future work page
│   │   ├── future-style.css
│   │   ├── index.html                 # Main dashboard (user landing page)
│   │   ├── issue.html                 # Project limitations/issues
│   │   ├── issue-style.css
│   │   ├── style.css                  # General styles
│   │   ├── team.html                  # Team introduction page
│   │   ├── team-style.css
│
│   ├── Clock.cpp                      # Clock logic (C++)
│   ├── Clock.h
│   ├── heart.cpp                      # Heart rate calculation logic (C++)
│   ├── heart.h
│   ├── project.ino                    # Arduino sketch running on ESP32
│   ├── server.py                      # Python Flask server for serial-to-web communication
│
├── code-manual.md                     # Developer documentation
├── user-manual.md                     # End-user manual(setup, build, run and use)
├── LICENSE                            # Open-source license info

## Functionality
This section describes the major components of the project and their purpose, along with how they work together to deliver heart rate monitoring functionality.

### 1. `project.ino` (ESP32 Arduino Sketch)
- Collects heart rate signals from the Pulse Sensor.
- Applies a threshold to detect beats per minute (BPM).
- Sends BPM data over the serial port to the host machine.

### 2. `server.py` (Python Flask Backend)
- Listens to the ESP32 over serial.
- Parses incoming BPM data.
- Hosts a simple Flask API that serves the latest BPM reading to the frontend via HTTP.

### 3. `static_website/` (Frontend UI)
- Displays BPM on a clean, user-friendly webpage.
- Files:
  - `index.html`: Main UI layout.
  - `clock.js`: Updates time or BPM data on screen in real-time.
  - `style.css`: Styling for the website layout.
- Additional HTML pages (`team.html`, `issues.html`, etc.) give more context about the project.

### 4. `heart.cpp` / `heart.h`
- C++ module for BPM processing logic (in case of modular expansion or simulation).
- Can be used for local testing without hardware.

### 5. `Clock.cpp` / `Clock.h`
- 
- 

### How it all connects:
1. The **ESP32** reads analog pulse data → processes it into BPM → sends it via **serial**.
2. The **Flask server** (`server.py`) reads that serial data and makes it available via an HTTP endpoint.
3. The **frontend** fetches this data periodically and updates the BPM on screen in real time.