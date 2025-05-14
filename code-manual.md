## 🧠 Heart Rate Monitor — Code Manual
Welcome! This guide will walk you through the **internal structure and functionality** of the Heart Rate Monitor project created for CS410-SP2025.

## Internal Structure

### Root Directory
- `code-manual.md`: Developer documentation
- `user-manual.md`: End-user manual (setup, build, run, and use)
- `LICENSE`: Open-source license information

### .vscode/
- `settings.json`: VS Code workspace settings

### project/
- `settings.json`: Project-level configuration

#### __pycache__/
- Python bytecode cache (auto-generated)

#### .vscode/
- `c_cpp_properties.json`: Optional local C++ project settings

#### static_website/
- **Web Pages**:
  - `index.html`: Main dashboard (landing page)
  - `description.html`: Project overview
  - `future.html`: Future work
  - `issue.html`: Known issues
  - `team.html`: Team introduction
- **Scripts & Styles**:
  - `clock.js`: JavaScript for real-time BPM updates
  - `style.css`, `description-style.css`, `future-style.css`, `issue-style.css`, `team-style.css`: Page-specific stylesheets
- **Assets**:
  - `images/`: UI images
  - `videos/`: Video demonstrations

#### Source Code Files
- `Clock.cpp`, `Clock.h`: Clock logic (C++)
- `heart.cpp`, `heart.h`: Heartbeat detection and calculation logic (C++)
- `project.ino`: Arduino sketch for ESP32
- `server.py`: Python Flask server for reading from serial and serving data to frontend

## Functionality
This section describes the major components of the project and their purpose, along with how they work together to deliver heart rate monitoring functionality.

### 1. `project.ino` (ESP32 Arduino Sketch)
- Collects analog readings from ESP32
- Spikes in between the readings are interpereted as a singular heartbeat
- Takes the average time between each reading in the last 10 seconds to find a BPM
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
- Implements a software-based time scheduler.
- Supports up to 10 measurement time blocks (`TimeBlock` structs).
- Allows manual or simulated setting of the current time.
- Useful for simulation/testing without a hardware RTC.

### How it all connects:
1. The **ESP32** reads analog pulse data → processes it into BPM → sends it via **serial**.
2. The **Flask server** (`server.py`) reads that serial data and makes it available via an HTTP endpoint.
3. The **frontend** fetches this data periodically and updates the BPM on screen in real time.
